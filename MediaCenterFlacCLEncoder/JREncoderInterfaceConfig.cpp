#include "Stdafx.h"
#include "JREncoderInterface.h"


namespace MediaCenterFlacCLEncoder {
	MediaCenterFlacCLEncoderInterface::Config::Config()
	{
		CompressionLevel = 7;
		PaddingBytes = 0;
		VerifyEncoding = false;
		ComputeMd5Hash = false;
		OffloadTasksToCpu = false;
		DoRiceEncoding = false;

		GpuWorkGroupSize = -1;
		FramesPerMultiprocessor = -1;
		AdditionalCpuThreads = -1;
		BlockSize = -1;
		TasksPerChannel = -1;
		TasksPerWindow = -1;
		StereoDecorrelationAlgorithm = -1;
		WindowAlgorithm = -1;

		PartitionOrder = std::make_pair(0, 0);
		PredictionOrder = std::make_pair(0, 0);
		FixedOrder = std::make_pair(0, 0);
		Precision = std::make_pair(0, 0);

		UseCpuEmulation = false;
	}

	MediaCenterFlacCLEncoderInterface::Config::Config(const std::wstring& str)
	{
		if (str.length() * sizeof(wchar_t) >= sizeof(*this))
		{
			*this = *reinterpret_cast<const Config*>(&str[0]);
		}
		else
		{
			*this = Config();
		}
	}

	MediaCenterFlacCLEncoderInterface::Config::operator std::wstring() const
	{
		return std::wstring(reinterpret_cast<const wchar_t*>(this),
			sizeof(*this) / sizeof(wchar_t));
	}
}
