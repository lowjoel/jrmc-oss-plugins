#include "Stdafx.h"
#include "JREncoderInterface.h"

namespace {
	HINSTANCE DllInstance = nullptr;
}

#pragma unmanaged
namespace MediaCenterFlacCLEncoder {
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
	HRESULT __cdecl DllRegisterServer(void)
	{
		HKEY key;
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

			wchar_t modulePath[MAX_PATH];
			GetModuleFileName(DllInstance, modulePath, MAX_PATH);
			RegSetStringValue(key, L"Path", modulePath);
			RegSetDWordValue(key, L"IVersion", JR_ENCODER_CURRENT_VERSION);
			returnCode = S_OK;
		}
		catch (DWORD error)
		{
		}

		RegCloseKey(key);
		return returnCode;
	}

	extern "C" __declspec(dllexport)
	HRESULT __cdecl DllUnregisterServer(void)
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

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		DllInstance = hinstDLL;
	}

	return TRUE;
}
