#include "Stdafx.h"

#include "JREncoderInterface.h"
#include "MediaCenterFlacCLEncoder.h"
#include "DllMain.h"

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
		Encoder = gcnew MediaCenterFlacCLEncoder(
			gcnew String(GetInfo(JR_ENCODER_INFO_DESTINATION_FILENAME)), format);
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

		array<Byte>^ buffer = gcnew array<Byte>(nBufferBytes);
		pin_ptr<byte> bufferPtr = &buffer[0];
		memcpy(bufferPtr, pBuffer, nBufferBytes);

		Encoder->Write(buffer);
		return TRUE;
	}

	BOOL MediaCenterFlacCLEncoderInterface::FinishBufferBased()
	{
		Encoder->Finish();
		return TRUE;
	}
#pragma endregion

#pragma region Configuration dialog (can show user interface)
	BOOL MediaCenterFlacCLEncoderInterface::Options()
	{
		return FALSE;
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

		return SysAllocString(i->second.c_str());
	}

	BOOL MediaCenterFlacCLEncoderInterface::SetInfo(LPCTSTR pName, LPCTSTR pValue)
	{
		Settings[pName] = pValue;
		return TRUE;
	}
#pragma endregion

	EncoderRegistration<MediaCenterFlacCLEncoderInterface> Registration;
}
