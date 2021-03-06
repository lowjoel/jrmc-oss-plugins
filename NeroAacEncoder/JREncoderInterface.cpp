#include "Stdafx.h"

#include "JREncoderInterface.h"
#include "MediaCenterNeroAacEncoder.h"
#include "SettingsForm.h"
#include "DllMain.h"
#include "Util.h"

using namespace System;

namespace MediaCenterNeroAacEncoder {
	MediaCenterNeroAacEncoderInterface::MediaCenterNeroAacEncoderInterface()
	{
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_VERSION,					L"1.0.0"));
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_DISPLAY_NAME,				L"Nero AAC Encoder Plugin for Media Jukebox/Media Center"));
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_EXTENSION,				L"m4a"));
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_ANY_FORMAT_FILE_INPUT,	L"0"));
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_WAV_FILE_INPUT,			L"1"));
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_BUFFER_INPUT,				L"1"));
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_UNCOMPRESSED_WAV_OUTPUT,	L"0"));
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_CONFIGURABLE,				boost::lexical_cast<std::wstring>(JR_ENCODER_CONFIGURABLE_YES)));
	}

	MediaCenterNeroAacEncoderInterface::~MediaCenterNeroAacEncoderInterface()
	{
	}

	void MediaCenterNeroAacEncoderInterface::Initialise()
	{
	}

	void MediaCenterNeroAacEncoderInterface::Install()
	{
		HKEY key;
		if (RegCreateKeyEx(HKEY_LOCAL_MACHINE,
			L"SOFTWARE\\J. River\\Media Jukebox\\Plugins\\Encoders\\Nero AAC Encoder",
			0, nullptr, REG_OPTION_NON_VOLATILE, KEY_WRITE | KEY_READ, nullptr,
			&key, nullptr) != ERROR_SUCCESS)
		{
			throw GetLastError();
		}

		auto RegSetStringValue = [](HKEY key, const wchar_t* valueName, const wchar_t* valueValue)
		{
			if (RegSetValueEx(key, valueName, 0, REG_SZ, reinterpret_cast<const BYTE*>(valueValue),
				sizeof(*valueValue) * (wcslen(valueValue) + 1)) != ERROR_SUCCESS)
			{
				throw GetLastError();
			}
		};
		auto RegSetDWordValue = [](HKEY key, const wchar_t* valueName, DWORD valueValue)
		{
			if (RegSetValueEx(key, valueName, 0, REG_DWORD, reinterpret_cast<const BYTE*>(&valueValue),
				sizeof(valueValue)))
			{
				throw GetLastError();
			}
		};

		HRESULT returnCode = SELFREG_E_CLASS;
		try
		{
			MediaCenterNeroAacEncoderInterface encoder;
			RegSetStringValue(key, L"Company", L"Joel Low");
			RegSetStringValue(key, L"Copyright", L"Copyright 2012 Joel Low");
			RegSetStringValue(key, L"Description", BStr(encoder.GetInfo(JR_ENCODER_INFO_DISPLAY_NAME)));
			RegSetStringValue(key, L"Ext", BStr(encoder.GetInfo(JR_ENCODER_INFO_EXTENSION)));
			RegSetStringValue(key, L"URL", L"http://joelsplace.sg");
			RegSetStringValue(key, L"Version", BStr(encoder.GetInfo(JR_ENCODER_INFO_VERSION)));

			RegSetStringValue(key, L"Path", EncoderRegistrationBase::GetDllPath().c_str());
			RegSetDWordValue(key, L"IVersion", JR_ENCODER_CURRENT_VERSION);
			returnCode = S_OK;
		}
		catch (DWORD /*error*/)
		{
			throw;
		}

		RegCloseKey(key);
	}

	void MediaCenterNeroAacEncoderInterface::Uninstall()
	{
		if (RegDeleteKeyEx(HKEY_LOCAL_MACHINE,
			L"SOFTWARE\\J. River\\Media Jukebox\\Plugins\\Encoders\\Nero AAC Encoder",
#ifdef _WIN64
			KEY_WOW64_64KEY,
#else
			KEY_WOW64_32KEY,
#endif
			0) != ERROR_SUCCESS)
		{
			throw std::exception();
		}
	}

#pragma region Buffer-based encoding (must support encoding happening from a worker thread)
	BOOL MediaCenterNeroAacEncoderInterface::StartBufferBased(WAVEFORMATEX* pwfeFormat,
		__int64 /*nApproximateTotalBytes*/)
	{
		System::Diagnostics::Debug::Assert(!Encoder);

		String^ filePath = gcnew String(BStr(GetInfo(JR_ENCODER_INFO_DESTINATION_FILENAME)));
		filePath += L'.' + gcnew String(BStr(GetInfo(JR_ENCODER_INFO_EXTENSION)));
		Encoder = gcnew MediaCenterNeroAacEncoder(filePath);
		SetInfo(JR_ENCODER_INFO_DESTINATION_FILENAME, filePath);

		//Set the settings
		Config config(BStr(GetInfo(JR_ENCODER_INFO_SETTINGS)));
		Encoder->Configure(config, pwfeFormat);

		return TRUE;
	}

	BOOL MediaCenterNeroAacEncoderInterface::EncodeBufferBased(BYTE* pBuffer,
		int nBufferBytes)
	{
		//Check if we have anything to write.
		if (!nBufferBytes)
		{
			return TRUE;
		}

		try
		{
			array<Byte>^ buffer = gcnew array<Byte>(nBufferBytes);
			pin_ptr<byte> bufferPtr = &buffer[0];
			memcpy(bufferPtr, pBuffer, nBufferBytes);

			Encoder->Write(buffer);
			return TRUE;
		}
		catch (Exception^ e)
		{
			LastError = e;
		}

		SetInfo(JR_ENCODER_INFO_LAST_ERROR, LastError->Message);
		Encoder->Terminate();
		return FALSE;
	}

	BOOL MediaCenterNeroAacEncoderInterface::FinishBufferBased()
	{
		if (!LastError)
			Encoder->Finish();
		return LastError ? FALSE : TRUE;
	}
#pragma endregion

#pragma region Configuration dialog (can show user interface)
	BOOL MediaCenterNeroAacEncoderInterface::Options()
	{
		SettingsForm form;
		BStr config = GetInfo(JR_ENCODER_INFO_SETTINGS);
		if (config && SysStringLen(config))
		{
			form.SetConfig(Config(config));
		}

		if (form.ShowDialog() == DialogResult::OK)
		{
			Config config(form.GetConfig());
			SetInfo(JR_ENCODER_INFO_SETTINGS, config);
		}

		return TRUE;
	}
#pragma endregion

#pragma region Called to complete installation, check for a license, etc. (can show user interface)
	/// Verify is called whenever the encoder plugin is invoked in the UI.
	BOOL MediaCenterNeroAacEncoderInterface::Verify()
	{
		return TRUE;
	}
#pragma endregion

#pragma region Settings, etc.
	BSTR MediaCenterNeroAacEncoderInterface::GetInfo(LPCTSTR pName)
	{
		//Intercept the call to JR_ENCODER_INFO_ESTIMATED_BITRATE
		if (!_tcscmp(pName, JR_ENCODER_INFO_ESTIMATED_BITRATE))
		{
			Config config(BStr(GetInfo(JR_ENCODER_INFO_SETTINGS)));
			int kbps = 0;
			switch (config.Mode)
			{
			case Config::EncoderMode::TargetBitRate:
				kbps = config.TargetBitRate;
				break;

			case Config::EncoderMode::TargetStreamingBitRate:
				kbps = config.TargetStreamingBitRate;
				break;

			case Config::EncoderMode::TargetQuality:
				if (config.TargetQuality < 0.05)
					kbps = 16;
				else if (config.TargetQuality < 0.10)
					kbps = 32;
				else if (config.TargetQuality < 0.25)
					kbps = 64;
				else if (config.TargetQuality < 0.35)
					kbps = 100;
				else if (config.TargetQuality < 0.45)
					kbps = 150;
				else if (config.TargetQuality < 0.5)
					kbps = 170;
				else if (config.TargetQuality < 0.55)
					kbps = 200;
				else if (config.TargetQuality < 0.65)
					kbps = 250;
				else if (config.TargetQuality < 0.75)
					kbps = 300;
				else if (config.TargetQuality < 0.85)
					kbps = 350;
				else if (config.TargetQuality < 0.95)
					kbps = 400;
				else if (config.TargetQuality > 0.99)
					kbps = 425;

				if (config.Profile == Config::EncoderProfile::HeAACv2)
					kbps /= 2;
				else if (config.Profile == Config::EncoderProfile::HeAAC)
					kbps = kbps * 2 / 3;
			}

			std::wstring result = boost::lexical_cast<std::wstring>(kbps);
			return SysAllocStringLen(result.c_str(), result.length());
		}
		
		SettingsMap::const_iterator i = Settings.find(pName);
		if (i == Settings.end())
			return nullptr;

		return SysAllocStringLen(i->second.c_str(), i->second.length());
	}

	BOOL MediaCenterNeroAacEncoderInterface::SetInfo(LPCTSTR pName, LPCTSTR pValue)
	{
		Settings[pName] = pValue;
		return TRUE;
	}

	BOOL MediaCenterNeroAacEncoderInterface::SetInfo(const std::wstring& pName,
		const std::wstring& pValue)
	{
		Settings[pName] = pValue;
		return TRUE;
	}

	BOOL MediaCenterNeroAacEncoderInterface::SetInfo(const std::wstring& pName, System::String^ pValue)
	{
		std::wstring value(msclr::interop::marshal_as<std::wstring>(pValue));

		Settings[pName] = value;
		return TRUE;
	}
#pragma endregion

	EncoderRegistration<MediaCenterNeroAacEncoderInterface> Registration;
}
