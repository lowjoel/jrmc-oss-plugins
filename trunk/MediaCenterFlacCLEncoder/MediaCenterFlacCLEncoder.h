#pragma once

namespace MediaCenterFlacCLEncoder {
	public ref class MediaCenterFlacCLEncoder
	{
	public:
		MediaCenterFlacCLEncoder(System::String^ outPath,
			CUETools::Codecs::AudioPCMConfig^ format);

		void Write(array<System::Byte>^ data);
		void Finish();

		/// Terminates encoding and deletes the temporary file.
		void Terminate();

		static System::Reflection::Assembly^ LoadDependencies(System::Object^ sender,
			System::ResolveEventArgs^ args);

	private:
		CUETools::Codecs::FLACCL::FLACCLWriter^ Writer;
	};
}
