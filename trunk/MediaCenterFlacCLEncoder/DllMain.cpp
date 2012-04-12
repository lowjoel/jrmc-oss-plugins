#include "Stdafx.h"
#include "DllMain.h"

#pragma unmanaged

namespace {
	HINSTANCE DllInstance = nullptr;
	class EncoderRegistrationRegistrar : public EncoderRegistrationBase
	{
	public:
		static IJREncoder* CreateEncoder(int nIndex)
		{
			for (boost::ptr_vector<EncoderRegistrationBase>::const_iterator i = Encoders.begin();
				i != Encoders.end() && nIndex--; ++i)
			{
				return i->Create();
			}

			return nullptr;
		}

		static HRESULT Install()
		{
			HRESULT returnCode = S_OK;
			for (boost::ptr_vector<EncoderRegistrationBase>::const_iterator i = Encoders.begin();
				i != Encoders.end(); ++i)
			{
				try
				{
					i->Install();
				}
				catch (...)
				{
					returnCode = SELFREG_E_CLASS;
				}
			}

			return returnCode;
		}

		static HRESULT Uninstall()
		{
			HRESULT returnCode = S_OK;
			for (boost::ptr_vector<EncoderRegistrationBase>::const_iterator i = Encoders.begin();
				i != Encoders.end(); ++i)
			{
				try
				{
					i->Uninstall();
				}
				catch (...)
				{
					returnCode = SELFREG_E_CLASS;
				}
			}

			return returnCode;
		}
	};
}

namespace MediaCenterFlacCLEncoder {
#pragma region CreateEncoder
	/// Export your plugin from a DLL with a single export function CreateEncoder.  You
	/// can put any number of encoders into a single DLL.  CreateEncoder(...) will be
	/// called with the index 0, 1, 2, etc. until a NULL encoder is returned.
	extern "C" __declspec(dllexport)
	IJREncoder* CreateEncoder(int nIndex, IJREncoderCallback * pCallback)
	{
		return EncoderRegistrationRegistrar::CreateEncoder(nIndex);
	}
#pragma endregion

#pragma region Install/uninstall
	extern "C" __declspec(dllexport)
	HRESULT __cdecl DllRegisterServer(void)
	{
		return EncoderRegistrationRegistrar::Install();
	}

	extern "C" __declspec(dllexport)
	HRESULT __cdecl DllUnregisterServer(void)
	{
		return EncoderRegistrationRegistrar::Uninstall();
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

std::wstring EncoderRegistrationBase::GetDllPath()
{
	wchar_t modulePath[MAX_PATH];
	GetModuleFileName(DllInstance, modulePath, MAX_PATH);
	return modulePath;
}

boost::ptr_vector<EncoderRegistrationBase> EncoderRegistrationBase::Encoders;
