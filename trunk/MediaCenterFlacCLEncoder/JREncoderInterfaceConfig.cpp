#include "Stdafx.h"
#include "JREncoderInterface.h"

namespace boost {
namespace serialization {
	template<class Archive>
	void serialize(Archive& ar, std::pair<int, int>& pair, const unsigned int version);

	template<class Archive>
	void serialize(Archive& ar, boost::tribool& value, const unsigned int version);
}
}

namespace MediaCenterFlacCLEncoder {
	MediaCenterFlacCLEncoderInterface::Config::Config()
	{
		CompressionLevel = 7;
		PaddingBytes = 0;
		VerifyEncoding = false;
		ComputeMd5Hash = false;
		OffloadTasksToCpu = false;
		DoRiceEncoding = false;

		MappedMemory = boost::indeterminate;
		EstimateWindow = boost::indeterminate;
		ComputeSeekTable = boost::indeterminate;
		ConstantFramesEncoding = boost::indeterminate;

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
		std::wistringstream stream(str);
		boost::archive::text_wiarchive archive(stream);

		try
		{
			Config temp;
			archive >> temp;

			*this = temp;
		}
		catch (boost::archive::archive_exception& e)
		{
			*this = Config();
		}
	}

	MediaCenterFlacCLEncoderInterface::Config::operator std::wstring() const
	{
		std::wostringstream result;
		boost::archive::text_woarchive archive(result);

		archive << *this;
		return result.str();
	}

	template<typename Archive>
	void MediaCenterFlacCLEncoderInterface::Config::serialize(Archive& ar, const unsigned int version)
	{
		ar & CompressionLevel;
		ar & PaddingBytes;
		ar & VerifyEncoding;
		ar & ComputeMd5Hash;
		ar & OffloadTasksToCpu;
		ar & DoRiceEncoding;

		ar & MappedMemory;
		ar & EstimateWindow;
		ar & ComputeSeekTable;
		ar & ConstantFramesEncoding;

		ar & GpuWorkGroupSize;
		ar & FramesPerMultiprocessor;
		ar & AdditionalCpuThreads;
		ar & BlockSize;
		ar & TasksPerChannel;
		ar & TasksPerWindow;
		ar & StereoDecorrelationAlgorithm;
		ar & WindowAlgorithm;
		
		ar & PartitionOrder;
		ar & PredictionOrder;
		ar & FixedOrder;
		ar & Precision;

		ar & OpenCLDefines;
		ar & OpenCLPlatform;
		ar & UseCpuEmulation;
	}
}

namespace boost {
namespace serialization {
	template<class Archive>
	void serialize(Archive& ar, std::pair<int, int>& pair, const unsigned int version)
	{
		ar & pair.first;
		ar & pair.second;
	}

	template<class Archive>
	void serialize(Archive& ar, boost::tribool& value, const unsigned int version)
	{
		ar & value.value;
	}
}
}