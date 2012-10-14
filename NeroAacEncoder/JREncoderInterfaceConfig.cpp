#include "Stdafx.h"
#include "JREncoderInterface.h"

namespace MediaCenterNeroAacEncoder {
	MediaCenterNeroAacEncoderInterface::Config::Config()
	{
		Mode = EncoderMode::TargetQuality;
		TargetQuality = 0.5;
		Profile = EncoderProfile::Automatic;
	}

	MediaCenterNeroAacEncoderInterface::Config::Config(const std::wstring& str)
	{
		if (str.empty())
		{
			*this = Config();
			return;
		}

		std::wistringstream stream(str);
		boost::archive::text_wiarchive archive(stream);

		try
		{
			Config temp;
			archive >> temp;

			*this = temp;
		}
		catch (boost::archive::archive_exception& /*e*/)
		{
			*this = Config();
		}
	}

	MediaCenterNeroAacEncoderInterface::Config::operator std::wstring() const
	{
		std::wostringstream result;
		boost::archive::text_woarchive archive(result);

		archive << *this;
		return result.str();
	}

	template<typename Archive>
	void MediaCenterNeroAacEncoderInterface::Config::serialize(Archive& ar, const unsigned int /*version*/)
	{
		ar & Mode;
		switch (Mode)
		{
		case EncoderMode::TargetBitRate:
			ar & TargetBitRate;
			break;
		case EncoderMode::TargetQuality:
			ar & TargetQuality;
			break;

		case EncoderMode::TargetStreamingBitRate:
			ar & TargetStreamingBitRate;
			break;
		}
		
		ar & Profile;
	}
}
