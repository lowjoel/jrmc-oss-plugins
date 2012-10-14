#include "Stdafx.h"
#include "MediaCenterNeroAacEncoder.h"

using namespace System;
using namespace System::IO;

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
	}

	MediaCenterNeroAacEncoder::MediaCenterNeroAacEncoder(String^ outPath)
	{
		OutPath = outPath;
	}

	void MediaCenterNeroAacEncoder::Configure(const MediaCenterNeroAacEncoderInterface::Config& config, WAVEFORMATEX* format)
	{
		std::wstring commandLine(L"-ignoreLength -if - ");
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
			commandLine += L"-lc ";
			break;

		case MediaCenterNeroAacEncoderInterface::Config::EncoderProfile::HeAAC:
			commandLine += L"-he ";
			break;

		case MediaCenterNeroAacEncoderInterface::Config::EncoderProfile::HeAACv2:
			commandLine += L"-hev2 ";
			break;

		case MediaCenterNeroAacEncoderInterface::Config::EncoderProfile::Automatic:
		default:
			break;
		}
		
		commandLine += L"-of \"";
		String^ commandLineStr = gcnew String(commandLine.c_str());
		commandLineStr = commandLineStr->Concat(OutPath);
		commandLineStr = commandLineStr->Concat('"');

		//Start the process.

		//Write the header.
		WaveHeader header = { 0x52494646, 0, 0x57415645, 0x666D7420, sizeof(*format) };
		header.Header = *format;

		array<Byte>^ buffer = gcnew array<Byte>(sizeof(header));
		pin_ptr<byte> bufferPtr = &buffer[0];
		memcpy(bufferPtr, &header, sizeof(header));

		//We are ready to start giving data blocks.
	}

	void MediaCenterNeroAacEncoder::Write(array<Byte>^ data)
	{
		Writer->Write(data);
	}

	void MediaCenterNeroAacEncoder::Finish()
	{
		Writer->Close();
	}

	void MediaCenterNeroAacEncoder::Terminate()
	{
		//TODO: What should we do here? MC locks the file.
		//Writer->Delete();
	}
}
