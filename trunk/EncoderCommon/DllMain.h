#pragma once
#include <boost/ptr_container/ptr_vector.hpp>
#include "JREncoder.h"

class EncoderRegistrationBase
{
public:
	/// Does initialisation work for the encoder. Called once at load time.
	virtual void Initialise() const = 0;

	/// Installs the encoder. Called when DllRegisterServer is called.
	virtual void Install() const = 0;

	/// Uninstalls the encoder. Called when DllUnregisterServer is called.
	virtual void Uninstall() const = 0;

	/// Creates an encoder instance. Called by Media Center.
	virtual IJREncoder* Create() const = 0;

	/// Gets the path to the currently executing DLL.
	static std::wstring GetDllPath();

protected:
	static boost::ptr_vector<EncoderRegistrationBase> Encoders;
};

/// Automatic registration class for Encoder Plugins. Order is determined at link-time.
template<typename EncoderPluginClass>
class EncoderRegistration : protected EncoderRegistrationBase
{
public:
	EncoderRegistration()
	{
		Encoders.push_back(new EncoderRegistration<EncoderPluginClass>(*this));
		Initialise();
	}

	virtual void Install() const
	{
		EncoderPluginClass::Install();
	}

	virtual void Uninstall() const
	{
		EncoderPluginClass::Uninstall();
	}

	virtual void Initialise() const
	{
		EncoderPluginClass::Initialise();
	}

	virtual IJREncoder* Create() const
	{
		return new EncoderPluginClass();
	}
};
