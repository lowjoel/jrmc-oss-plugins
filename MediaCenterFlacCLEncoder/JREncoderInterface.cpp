#include "Stdafx.h"

#include "JREncoderInterface.h"
#include "MediaCenterFlacCLEncoder.h"
#include "DllMain.h"
#include "SettingsForm.h"

using namespace System;
using namespace CUETools::Codecs;

namespace MediaCenterFlacCLEncoder {
	MediaCenterFlacCLEncoderInterface::MediaCenterFlacCLEncoderInterface()
	{
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_VERSION,					L"1.0.0"));
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_DISPLAY_NAME,				L"FlacCL Encoder Plugin for Media Jukebox/Media Center"));
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_EXTENSION,				L"flac"));
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_ANY_FORMAT_FILE_INPUT,	L"0"));
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_WAV_FILE_INPUT,			L"1"));
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_BUFFER_INPUT,				L"1"));
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_UNCOMPRESSED_WAV_OUTPUT,	L"0"));
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_CONFIGURABLE,				boost::lexical_cast<std::wstring>(JR_ENCODER_CONFIGURABLE_YES)));
	}

	MediaCenterFlacCLEncoderInterface::~MediaCenterFlacCLEncoderInterface()
	{
	}

	void MediaCenterFlacCLEncoderInterface::Initialise()
	{
		AppDomain^ currentDomain = AppDomain::CurrentDomain;
		currentDomain->AssemblyResolve += gcnew ResolveEventHandler(MediaCenterFlacCLEncoder::LoadDependencies);
	}

	void MediaCenterFlacCLEncoderInterface::Install()
	{
		HKEY key;
		if (RegCreateKeyEx(HKEY_LOCAL_MACHINE,
			L"SOFTWARE\\J. River\\Media Jukebox\\Plugins\\Encoders\\FlacCL Encoder",
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
			MediaCenterFlacCLEncoderInterface encoder;
			RegSetStringValue(key, L"Company", L"Joel Low");
			RegSetStringValue(key, L"Copyright", L"Copyright 2012 Joel Low");
			RegSetStringValue(key, L"Description", encoder.GetInfo(JR_ENCODER_INFO_DISPLAY_NAME));
			RegSetStringValue(key, L"Ext", encoder.GetInfo(JR_ENCODER_INFO_EXTENSION));
			RegSetStringValue(key, L"URL", L"http://joelsplace.sg");
			RegSetStringValue(key, L"Version", encoder.GetInfo(JR_ENCODER_INFO_VERSION));

			RegSetStringValue(key, L"Path", EncoderRegistrationBase::GetDllPath().c_str());
			RegSetDWordValue(key, L"IVersion", JR_ENCODER_CURRENT_VERSION);
			returnCode = S_OK;
		}
		catch (DWORD error)
		{
			throw;
		}

		RegCloseKey(key);
	}

	void MediaCenterFlacCLEncoderInterface::Uninstall()
	{
		if (RegDeleteKeyEx(HKEY_LOCAL_MACHINE,
			L"SOFTWARE\\J. River\\Media Jukebox\\Plugins\\Encoders\\FlacCL Encoder",
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
	BOOL MediaCenterFlacCLEncoderInterface::StartBufferBased(WAVEFORMATEX* pwfeFormat,
		__int64 nApproximateTotalBytes)
	{
		System::Diagnostics::Debug::Assert(!Encoder);

		AudioPCMConfig^ format = gcnew AudioPCMConfig(pwfeFormat->wBitsPerSample, pwfeFormat->nChannels,
			pwfeFormat->nSamplesPerSec);
		String^ filePath = gcnew String(GetInfo(JR_ENCODER_INFO_DESTINATION_FILENAME));
		filePath += L'.' + gcnew String(GetInfo(JR_ENCODER_INFO_EXTENSION));
		Encoder = gcnew MediaCenterFlacCLEncoder(filePath, format);
		SetInfo(JR_ENCODER_INFO_DESTINATION_FILENAME, filePath);
		return TRUE;
	}

	BOOL MediaCenterFlacCLEncoderInterface::EncodeBufferBased(BYTE* pBuffer,
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
		catch (OpenCLNet::OpenCLBuildException^ e)
		{
			LastError = e;
		}
		catch (Exception^ e)
		{
			LastError = e;
		}

		SetInfo(JR_ENCODER_INFO_LAST_ERROR, LastError->Message);
		Encoder->Terminate();
		return FALSE;
	}

	BOOL MediaCenterFlacCLEncoderInterface::FinishBufferBased()
	{
		if (!LastError)
			Encoder->Finish();
		return LastError ? FALSE : TRUE;
	}
#pragma endregion

#pragma region Configuration dialog (can show user interface)
	BOOL MediaCenterFlacCLEncoderInterface::Options()
	{
		SettingsForm form;
		BSTR config = GetInfo(JR_ENCODER_INFO_SETTINGS);
		if (config && SysStringLen(config))
		{
			form.SetConfig(std::wstring(config, SysStringLen(config)));
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
	BOOL MediaCenterFlacCLEncoderInterface::Verify()
	{
		return TRUE;
	}
#pragma endregion

#pragma region Settings, etc.
	BSTR MediaCenterFlacCLEncoderInterface::GetInfo(LPCTSTR pName)
	{
		SettingsMap::const_iterator i = Settings.find(pName);
		if (i == Settings.end())
			return nullptr;

		return SysAllocStringLen(i->second.c_str(), i->second.length());
	}

	BOOL MediaCenterFlacCLEncoderInterface::SetInfo(LPCTSTR pName, LPCTSTR pValue)
	{
		Settings[pName] = pValue;
		return TRUE;
	}

	BOOL MediaCenterFlacCLEncoderInterface::SetInfo(const std::wstring& pName,
		const std::wstring& pValue)
	{
		Settings[pName] = pValue;
		return TRUE;
	}

	BOOL MediaCenterFlacCLEncoderInterface::SetInfo(const std::wstring& pName, System::String^ pValue)
	{
		msclr::interop::marshal_context marshal;
		std::wstring value(marshal.marshal_as<std::wstring>(pValue));

		Settings[pName] = value;
		return TRUE;
	}
#pragma endregion

	EncoderRegistration<MediaCenterFlacCLEncoderInterface> Registration;
}
