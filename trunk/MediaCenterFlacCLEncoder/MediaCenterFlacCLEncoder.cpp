// This is the main DLL file.

#include "stdafx.h"

#include "MediaCenterFlacCLEncoder.h"

using namespace System;
using namespace System::IO;
using namespace System::Reflection;

using namespace CUETools::Codecs;
using namespace CUETools::Codecs::FLACCL;

namespace MediaCenterFlacCLEncoder {
	MediaCenterFlacCLEncoder::MediaCenterFlacCLEncoder(String^ outPath, AudioPCMConfig^ format)
	{
		Writer = gcnew FLACCLWriter(outPath,
			gcnew FileStream(outPath, FileMode::Create, FileAccess::Write),
			format);
	}

	Assembly^ MediaCenterFlacCLEncoder::LoadDependencies(Object^ sender, ResolveEventArgs^ args)
	{
		String^ folderPath = Path::GetDirectoryName(Assembly::GetExecutingAssembly()->Location);
		String^ assemblyPath = Path::Combine(folderPath, (gcnew AssemblyName(args->Name))->Name + ".dll");
		if (File::Exists(assemblyPath) == false)
			return nullptr;

		Assembly^ assembly = Assembly::LoadFrom(assemblyPath);
		return assembly;
	}

	void MediaCenterFlacCLEncoder::Configure(const MediaCenterFlacCLEncoderInterface::Config& config)
	{
		FLACCLWriterSettings^ encoderSettings = gcnew FLACCLWriterSettings();
		Writer->CompressionLevel = config.CompressionLevel;
		Writer->Padding = config.PaddingBytes;
		encoderSettings->DoVerify = config.VerifyEncoding;
		encoderSettings->DoMD5 = config.ComputeMd5Hash;
		encoderSettings->GPUOnly = !config.OffloadTasksToCpu;
		encoderSettings->DoRice = config.DoRiceEncoding;
		
		if (!boost::indeterminate(config.MappedMemory))
			encoderSettings->MappedMemory = (bool)config.MappedMemory;
		if (!boost::indeterminate(config.EstimateWindow))
			Writer->EstimateWindow = (bool)config.EstimateWindow;
		if (!boost::indeterminate(config.ComputeSeekTable))
			Writer->DoSeekTable = (bool)config.ComputeSeekTable;
		if (!boost::indeterminate(config.ConstantFramesEncoding))
			Writer->DoConstant = (bool)config.ConstantFramesEncoding;
		if (config.GpuWorkGroupSize != -1)
			encoderSettings->GroupSize = config.GpuWorkGroupSize;
		if (config.FramesPerMultiprocessor != -1)
			encoderSettings->TaskSize = config.FramesPerMultiprocessor;
		if (config.AdditionalCpuThreads != -1)
			encoderSettings->CPUThreads = config.AdditionalCpuThreads;
		if (config.BlockSize != -1)
			Writer->BlockSize = config.BlockSize;
		if (config.TasksPerChannel != -1)
			Writer->OrdersPerChannel = config.TasksPerChannel;
		if (config.TasksPerWindow != -1)
			Writer->OrdersPerWindow = config.TasksPerWindow;
		int StereoDecorrelationAlgorithm;
		int WindowAlgorithm;

		if (config.PartitionOrder.first > 0)
			Writer->MinPartitionOrder = config.PartitionOrder.first;
		if (config.PartitionOrder.second > 0)
			Writer->MaxPartitionOrder = config.PartitionOrder.second;
		if (config.PredictionOrder.first > 0)
			Writer->MinLPCOrder = config.PredictionOrder.first;
		if (config.PredictionOrder.second > 0)
			Writer->MaxLPCOrder = config.PredictionOrder.second;
		if (config.FixedOrder.first > 0)
			Writer->MinFixedOrder = config.FixedOrder.first;
		if (config.FixedOrder.second > 0)
			Writer->MaxFixedOrder = config.FixedOrder.second;
		if (config.Precision.first > 0)
			Writer->MinPrecisionSearch = config.Precision.first;
		if (config.Precision.second > 0)
			Writer->MaxPrecisionSearch = config.Precision.second;

		if (!config.OpenCLDefines.empty())
		{
			std::vector<std::wstring> defines;
			boost::split(defines, config.OpenCLDefines, boost::is_any_of(";"), boost::token_compress_on);
			std::wstring defineStr;

			for (std::vector<std::wstring>::const_iterator i = defines.begin(); i != defines.end(); ++i)
			{
				std::wstring define(*i);
				std::wstring::const_iterator equals;
				{
					std::wstring::size_type equalsPos = define.find(L'=');
					if (equalsPos == std::wstring::npos)
						equals = define.end();
					else
						equals = define.begin() + equalsPos;
				}

				if (equals == define.end())
					defineStr.append(define);
				else
				{
					defineStr.append(L"#define ");
					defineStr.append(std::wstring(define.begin(), equals));
					defineStr.append(L" ");
					defineStr.append(std::wstring(++equals, define.end()));
				}

				defineStr.append(L"\n");
			}

			msclr::interop::marshal_context marshal;
			encoderSettings->Defines = marshal.marshal_as<String^>(defineStr);
		}
		if (!config.OpenCLPlatform.empty())
		{
			msclr::interop::marshal_context marshal;
			encoderSettings->Platform = marshal.marshal_as<String^>(config.OpenCLPlatform);
		}
		if (config.UseCpuEmulation)
			encoderSettings->DeviceType = CUETools::Codecs::FLACCL::OpenCLDeviceType::CPU;

		Writer->Settings = encoderSettings;
	}

	void MediaCenterFlacCLEncoder::Write(array<Byte>^ data)
	{
		AudioPCMConfig^ format = Writer->PCM;
		CUETools::Codecs::AudioBuffer buffer(format, data, data->Length / format->BlockAlign);

		Writer->Write(%buffer);
	}

	void MediaCenterFlacCLEncoder::Finish()
	{
		Writer->Close();
	}

	void MediaCenterFlacCLEncoder::Terminate()
	{
		//TODO: What should we do here? MC locks the file.
		//Writer->Delete();
	}
}
