#include "Stdafx.h"
#pragma unmanaged

#include "JREncoderInterface.h"

namespace MediaCenterFlacCLEncoder {
	MediaCenterFlacCLEncoderInterface::~MediaCenterFlacCLEncoderInterface()
	{
	}

#pragma region Buffer-based encoding (must support encoding happening from a worker thread)
	BOOL MediaCenterFlacCLEncoderInterface::StartBufferBased(WAVEFORMATEX * pwfeFormat, __int64 nApproximateTotalBytes)
	{
		return FALSE;
	}

	BOOL MediaCenterFlacCLEncoderInterface::EncodeBufferBased(BYTE * pBuffer, int nBufferBytes)
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
		return FALSE;
	}
#pragma endregion
}
