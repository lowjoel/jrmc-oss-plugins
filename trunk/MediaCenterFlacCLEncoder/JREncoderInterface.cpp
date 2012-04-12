#include "Stdafx.h"

#include "JREncoderInterface.h"
#include "MediaCenterFlacCLEncoder.h"

using namespace System;

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

#pragma region Buffer-based encoding (must support encoding happening from a worker thread)
	BOOL MediaCenterFlacCLEncoderInterface::StartBufferBased(WAVEFORMATEX* pwfeFormat, __int64 nApproximateTotalBytes)
	{
		Encoder = gcnew MediaCenterFlacCLEncoder(gcnew String(GetInfo(JR_ENCODER_INFO_DESTINATION_FILENAME)));
		return TRUE;
	}

	BOOL MediaCenterFlacCLEncoderInterface::EncodeBufferBased(BYTE* pBuffer, int nBufferBytes)
	{
		return FALSE;
	}

	BOOL MediaCenterFlacCLEncoderInterface::FinishBufferBased()
	{
		return FALSE;
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
}
