#pragma once
#include <map>
#include <vcclr.h>
#include "JREncoder.h"

namespace MediaCenterNeroAacEncoder {
	class MediaCenterNeroAacEncoderInterface : public IJREncoder
	{
	private:
		struct wstring_comparer
		{
			bool operator()(const std::wstring& lhs, const std::wstring& rhs)
			{
				return wcscmp(lhs.c_str(), rhs.c_str()) < 0;
			}
		};
		typedef std::map<std::wstring, std::wstring, wstring_comparer> SettingsMap;

	public:
		/// Stores configuration options for the Nero AAC Encoder.
		struct Config
		{
			friend class boost::serialization::access;

		public:
			enum class EncoderMode {
				TargetQuality,
				TargetBitRate,
				TargetStreamingBitRate
			};

			enum class EncoderProfile {
				Automatic = 0,
				LcAAC,
				HeAAC,
				HeAACv2
			};

		public:
			/// Default constructor.
			Config();

			/// Construct a Config object from the serialised equivalent.
			Config(const std::wstring& str);

			/// Serialises the configuration.
			operator std::wstring() const;

		private:
			template<typename Archive> void serialize(Archive& ar, const unsigned int version);

		public:
			union {
				float TargetQuality;
				unsigned TargetBitRate;
				unsigned TargetStreamingBitRate;
			};

			EncoderMode Mode;
			EncoderProfile Profile;
		};

	public:
		MediaCenterNeroAacEncoderInterface();
		virtual ~MediaCenterNeroAacEncoderInterface();

		//File-based encoding: this is left unimplemented since we will implement
		//Buffer-based encoding
		virtual BOOL StartFileBased() { return FALSE; }
		virtual BOOL StopFileBased() { return FALSE; }

		//Buffer-based encoding (must support encoding happening from a worker thread)
		virtual BOOL StartBufferBased(WAVEFORMATEX * pwfeFormat, __int64 nApproximateTotalBytes);
		virtual BOOL EncodeBufferBased(BYTE * pBuffer, int nBufferBytes);
		virtual BOOL FinishBufferBased();

		//Configuration dialog (can show user interface)
		virtual BOOL Options();

		//Called to complete installation, check for a license, etc. (can show user interface)
		virtual BOOL Verify();

		//Settings, etc.
		virtual BSTR GetInfo(LPCTSTR pName);
		virtual BOOL SetInfo(LPCTSTR pName, LPCTSTR pValue);

	public:
		/// Called at plugin load.
		static void Initialise();

		/// Called when MC is installing us.
		static void Install();

		/// Called when MC is uninstalling us.
		static void Uninstall();

	private:
		//Some private overloads.
		BOOL SetInfo(const std::wstring& pName, const std::wstring& pValue);
		BOOL SetInfo(const std::wstring& pName, System::String^ pValue);

	private:
		/// The handle to the encoder instance.
		gcroot<ref class MediaCenterNeroAacEncoder^> Encoder;

		/// Settings set by JRMC
		SettingsMap Settings;

		/// Last error encountered
		gcroot<System::Exception^> LastError;
	};
}
