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
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_ANY_FORMAT_FILE_INPUT,	L"false"));
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_WAV_FILE_INPUT,			L"true"));
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_BUFFER_INPUT,				L"true"));
		Settings.insert(std::pair<std::wstring, std::wstring>(JR_ENCODER_INFO_UNCOMPRESSED_WAV_OUTPUT,	L"false"));
	}

	MediaCenterFlacCLEncoderInterface::~MediaCenterFlacCLEncoderInterface()
	{
	}

#pragma region Buffer-based encoding (must support encoding happening from a worker thread)
	BOOL MediaCenterFlacCLEncoderInterface::StartBufferBased(WAVEFORMATEX* pwfeFormat, __int64 nApproximateTotalBytes)
	{
		Encoder = gcnew MediaCenterFlacCLEncoder(gcnew String(GetInfo(JR_ENCODER_INFO_DESTINATION_FILENAME)));
		return FALSE;
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
	BOOL MediaCenterFlacCLEncoderInterface::Verify()
	{
		return FALSE;
	}
#pragma endregion

#pragma region Settings, etc.
	BSTR MediaCenterFlacCLEncoderInterface::GetInfo(LPCTSTR pName)
	{
		return nullptr;
	}

	BOOL MediaCenterFlacCLEncoderInterface::SetInfo(LPCTSTR pName, LPCTSTR pValue)
	{
		Settings[pName] = pValue;
		return TRUE;
	}
#pragma endregion
}
