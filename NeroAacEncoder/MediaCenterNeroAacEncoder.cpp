#include "Stdafx.h"
#include "MediaCenterNeroAacEncoder.h"
#include "DllMain.h"

using namespace System;
using namespace System::IO;
using namespace System::Diagnostics;

namespace MediaCenterNeroAacEncoder {
	namespace {
		struct WaveHeader
		{
			unsigned __int32 RiffID; //"RIFF" 0x52494646
			unsigned __int32 RiffLength;
			unsigned __int32 RiffType; //"WAVE" 0x57415645

			unsigned __int32 HeaderID; //"fmt " 0x666D7420
			unsigned __int32 HeaderSize; //16 + extra format bytes
			WAVEFORMATEX Header;
		};

		struct DataChunk
		{
			unsigned __int32 DataID; //"data" 0x64617461
			unsigned __int32 DataSize;
		};
	}

	MediaCenterNeroAacEncoder::MediaCenterNeroAacEncoder(String^ outPath)
	{
		OutPath = outPath;
	}

	void MediaCenterNeroAacEncoder::Configure(const MediaCenterNeroAacEncoderInterface::Config& config, WAVEFORMATEX* format)
	{
		std::wstring commandLine(L"-ignorelength ");
		switch (config.Mode)
		{
		case MediaCenterNeroAacEncoderInterface::Config::EncoderMode::TargetBitRate:
			commandLine += L"-br " + boost::lexical_cast<std::wstring>(config.TargetBitRate);
			break;

		case MediaCenterNeroAacEncoderInterface::Config::EncoderMode::TargetQuality:
			commandLine += L"-q " + boost::lexical_cast<std::wstring>(config.TargetQuality);
			break;

		case MediaCenterNeroAacEncoderInterface::Config::EncoderMode::TargetStreamingBitRate:
			commandLine += L"-cbr " + boost::lexical_cast<std::wstring>(config.TargetStreamingBitRate);
			break;

		}

		switch (config.Profile)
		{
		case MediaCenterNeroAacEncoderInterface::Config::EncoderProfile::LcAAC:
			commandLine += L" -lc ";
			break;

		case MediaCenterNeroAacEncoderInterface::Config::EncoderProfile::HeAAC:
			commandLine += L" -he ";
			break;

		case MediaCenterNeroAacEncoderInterface::Config::EncoderProfile::HeAACv2:
			commandLine += L" -hev2 ";
			break;

		case MediaCenterNeroAacEncoderInterface::Config::EncoderProfile::Automatic:
		default:
			break;
		}
		String^ commandLineStr = gcnew String(commandLine.c_str()) + L" -if - -of \"" + OutPath + "\"";

		//Start the process.
		ProcessStartInfo^ startInfo = gcnew ProcessStartInfo(Path::Combine(
				Path::GetDirectoryName(gcnew String(EncoderRegistrationBase::GetDllPath().c_str())),
				L"neroAacEnc.exe"),
			commandLineStr);
		startInfo->UseShellExecute = false;
		startInfo->CreateNoWindow = true;
		startInfo->RedirectStandardInput = true;
		startInfo->RedirectStandardOutput = true;
		Encoder = Process::Start(startInfo);

		//Write the header.
		WaveHeader h = { 0 };
		memcpy(&h.RiffID, "RIFF", sizeof(h.RiffID));
		h.RiffLength = 0;
		memcpy(&h.RiffType, "WAVE", sizeof(h.RiffType));
		memcpy(&h.HeaderID, "fmt ", sizeof(h.HeaderID));
		h.HeaderSize = sizeof(*format) + (format->cbSize ? format->cbSize : -2);
		h.Header = *format;

		array<Byte>^ buffer = gcnew array<Byte>(sizeof(h));
		pin_ptr<byte> bufferPtr = &buffer[0];
		memcpy(bufferPtr, &h, sizeof(h));
		Encoder->StandardInput->BaseStream->Write(buffer, 0, sizeof(__int32) * 5 + h.HeaderSize);

		//We are ready to start giving data blocks.
		DataChunk chunk = { 0 };
		memcpy(&chunk.DataID, "data", sizeof(chunk.DataID));
		chunk.DataSize = 0;
		memcpy(bufferPtr, &chunk, sizeof(chunk));
		Encoder->StandardInput->BaseStream->Write(buffer, 0, sizeof(chunk));
	}

	void MediaCenterNeroAacEncoder::Write(array<Byte>^ data)
	{
		Debug::Assert(Encoder != nullptr);

		Encoder->StandardInput->BaseStream->Write(data, 0, data->Length);
	}

	void MediaCenterNeroAacEncoder::Finish()
	{
		Encoder->StandardInput->Close();
		Encoder->WaitForExit();
	}

	void MediaCenterNeroAacEncoder::Terminate()
	{
		//TODO: What should we do here? MC locks the file.
		//Writer->Delete();
	}
}
