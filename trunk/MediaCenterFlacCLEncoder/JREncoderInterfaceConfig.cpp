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

		PartitionOrder = std::make_pair(-1, -1);
		PredictionOrder = std::make_pair(-1, -1);
		FixedOrder = std::make_pair(-1, -1);
		Precision = std::make_pair(-1, -1);

		UseCpuEmulation = false;
	}

	MediaCenterFlacCLEncoderInterface::Config::Config(const std::wstring& str)
	{
	}

	MediaCenterFlacCLEncoderInterface::Config::operator std::wstring() const
	{
		return std::wstring();
	}
}
