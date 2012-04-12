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

#pragma region CreateEncoder
	/// Export your plugin from a DLL with a single export function CreateEncoder.  You
	/// can put any number of encoders into a single DLL.  CreateEncoder(...) will be
	/// called with the index 0, 1, 2, etc. until a NULL encoder is returned.
	extern "C" __declspec(dllexport)
	IJREncoder* CreateEncoder(int nIndex, IJREncoderCallback * pCallback)
	{
		return nullptr;
	}
#pragma endregion

#pragma region Install/uninstall
	extern "C" __declspec(dllexport)
	HRESULT __stdcall DllRegisterServer(void)
	{
		HKEY key = { 0 };
		if (RegCreateKeyEx(HKEY_LOCAL_MACHINE,
			L"SOFTWARE\\J. River\\Media Jukebox\\Plugins\\Encoders\\FlacCL Encoder",
			0, nullptr, REG_OPTION_NON_VOLATILE, KEY_WRITE | KEY_READ, nullptr,
			&key, nullptr) != ERROR_SUCCESS)
		{
			return SELFREG_E_CLASS;
		}

		auto RegSetStringValue = [](HKEY key, const wchar_t* valueName, const wchar_t* valueValue)
		{
			if (RegSetValueEx(key, valueName, 0, REG_SZ, reinterpret_cast<const BYTE*>(valueValue),
				sizeof(*valueValue) * (wcslen(valueValue) + 1)) != ERROR_SUCCESS)
			{
				throw GetLastError();
			}
		};

		HRESULT returnCode = SELFREG_E_CLASS;
		try
		{
			RegSetStringValue(key, L"Company", L"Joel Low");
			RegSetStringValue(key, L"Copyright", L"Copyright");
			RegSetStringValue(key, L"Description", L"FlacCL Encoder Plugin for Media Jukebox/Media Center");
			RegSetStringValue(key, L"Ext", L"flac");
			RegSetStringValue(key, L"URL", L"http://joelsplace.sg");
			RegSetStringValue(key, L"Version", L"1.0.0");
			returnCode = S_OK;
		}
		catch (DWORD error)
		{
		}

		RegCloseKey(key);
		return returnCode;
	}

	extern "C" __declspec(dllexport)
	HRESULT __stdcall DllUnregisterServer(void)
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
			return SELFREG_E_CLASS;
		}

		return S_OK;
	}
#pragma endregion
}
