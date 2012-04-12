#pragma once

/**************************************************************************************************************
JREncoder

This defines the interface to a J. River encoder plugin.  The interface is a C++ interface derived from the
class IJREncoder below.

You must implement either the buffer-based (recommended) or the file-based encoding functions.  There is no
need to implement both, since the file-based operations can be easily emulated by using the buffer-based
functions.

All settings should be serialized to a single string and returned on GetInfo(JR_ENCODER_INFO_SETTINGS).  The
framework will save these settings and provide the appropriate settings when using the encoder.

Encoder plugins should be silent during encoding.  Errors should be available using 
GetInfo(JR_ENCODER_INFO_LAST_ERROR), but should never be automatically displayed to the user.

Export your plugin from a DLL with a single export function CreateEncoder.  You can put any number of encoders
into a single DLL.  CreateEncoder(...) will be called with the index 0, 1, 2, etc. until a NULL encoder is
returned.

You should also export the functions DllRegisterServer and DllUnregisterServer.  The framework will call these
at install and uninstall time.  For a plugin to appear in the program, it must be registered in the registry
at this location: HKEY_LOCAL_MACHINE\SOFTWARE\J. River\Media Center 13\Plugins\Encoders.  To see the format 
that is required in the registry, it is recommended that you simply view the stock encoders that ship with the 
program.
**************************************************************************************************************/

/**************************************************************************************************************
Defines for encoder interface
**************************************************************************************************************/
#define JR_ENCODER_CURRENT_VERSION				5

#define JR_ENCODER_INFO_VERSION					_T("Version")					// encoder version (return JR_ENCODER_CURRENT_VERSION)
#define JR_ENCODER_INFO_DISPLAY_NAME			_T("Display Name")				// the display name of the encoder
#define JR_ENCODER_INFO_EXTENSION				_T("Extension")					// the default / current extension used by the encoder (no dot, all lowercase)
#define JR_ENCODER_INFO_SOURCE_FILENAME			_T("Source Filename")			// file-based source filename
#define JR_ENCODER_INFO_DESTINATION_FILENAME	_T("Destination Filename")		// file-based destination filename
#define JR_ENCODER_INFO_ESTIMATED_BITRATE		_T("Estimated Bitrate")			// best guess bitrate in kbps using the current settings
#define JR_ENCODER_INFO_SETTINGS				_T("Settings")					// all settings serialized to a string
#define JR_ENCODER_INFO_STREAMING				_T("Streaming")					// whether the encoded file can be streamed as it's encoded
#define JR_ENCODER_INFO_ANY_FORMAT_FILE_INPUT	_T("Any Format File Input")		// whether the encoder supports file input of any format
#define JR_ENCODER_INFO_WAV_FILE_INPUT			_T("WAV File Input")			// whether the encoder supports WAV file input
#define JR_ENCODER_INFO_BUFFER_INPUT			_T("Buffer Input")				// whether the encoder supports buffer input
#define JR_ENCODER_INFO_LAST_ERROR				_T("Last Error")				// the last error encountered by the encoder
#define JR_ENCODER_INFO_CONFIGURABLE			_T("Configurable")				// the type of configuration supported / needed (JR_ENCODER_CONFIGURABLE_TYPES)
#define JR_ENCODER_INFO_UNCOMPRESSED_WAV_OUTPUT	_T("Uncompressed WAV Output")	// return 1 if the output of the encoder is a standard, uncompressed WAV file
#define JR_ENCODER_INFO_AUTO_CONFIG				_T("Auto Config")				// 1 or 0, 1 means encoder should configure itself using a preset specified by...
#define JR_ENCODER_INFO_AUTO_CONFIG_FOR			_T("Auto Config For")			// set to one of the ENCODER_AUTO_CONFIG_FOR_... enum

enum JR_ENCODER_CONFIGURABLE_TYPES
{
	JR_ENCODER_CONFIGURABLE_NO,
	JR_ENCODER_CONFIGURABLE_YES,
	JR_ENCODER_CONFIGURABLE_MANDATORY,
};

#include "SharedFiles/AudioFormatIncludes.h"

/**************************************************************************************************************
IJREncoderCallback
**************************************************************************************************************/
class IJREncoder;
class IJREncoderCallback
{
public:

	// callbacks (only used during file-based encoding -- should be fired from same thread as caller)
	virtual void JREncoder_Finished(IJREncoder * pEncoder) = 0;
	virtual void JREncoder_Failure(IJREncoder * pEncoder, int nError, LPCTSTR pDescription) = 0;
	virtual void JREncoder_Progress(IJREncoder * pEncoder, int nProgress) = 0;
};

/**************************************************************************************************************
IJREncoder
**************************************************************************************************************/
class IJREncoder
{
public:

	// construction / destruction
	virtual ~IJREncoder() { }

	// file-based encoding
	virtual BOOL StartFileBased() = 0;
	virtual BOOL StopFileBased() = 0;

	// buffer-based encoding (must support encoding happening from a worker thread)
	virtual BOOL StartBufferBased(WAVEFORMATEX * pwfeFormat, int64 nApproximateTotalBytes) = 0;
	virtual BOOL EncodeBufferBased(BYTE * pBuffer, int nBufferBytes) = 0;
	virtual BOOL FinishBufferBased() = 0;

	// configuration dialog (can show user interface)
	virtual BOOL Options() = 0;

	// called to complete installation, check for a license, etc. (can show user interface)
	virtual BOOL Verify() = 0;

	// settings, etc.
	virtual BSTR GetInfo(LPCTSTR pName) = 0;
	virtual BOOL SetInfo(LPCTSTR pName, LPCTSTR pValue) = 0;
};

/**************************************************************************************************************
Creation function declaration
**************************************************************************************************************/
typedef IJREncoder * (*proc_CreateEncoder)(int nIndex, IJREncoderCallback * pCallback);
