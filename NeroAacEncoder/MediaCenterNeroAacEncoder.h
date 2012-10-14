#pragma once
#include "JREncoderInterface.h"

namespace MediaCenterNeroAacEncoder {
	public ref class MediaCenterNeroAacEncoder
	{
	public:
		MediaCenterNeroAacEncoder(System::String^ outPath);

		/// Configures the encoder based on the provided configuration settings.
		void Configure(const MediaCenterNeroAacEncoderInterface::Config& config, WAVEFORMATEX* header);

		void Write(array<System::Byte>^ data);
		void Finish();

		/// Terminates encoding and deletes the temporary file.
		void Terminate();

	private:
	};
}
