#pragma once

namespace MediaCenterFlacCLEncoder {
	public ref class MediaCenterFlacCLEncoder
	{
	public:
		MediaCenterFlacCLEncoder(System::String^ outPath);

		static System::Reflection::Assembly^ LoadDependencies(System::Object^ sender,
			System::ResolveEventArgs^ args);

	private:
		CUETools::Codecs::FLACCL::FLACCLWriter^ Writer;
	};
}
