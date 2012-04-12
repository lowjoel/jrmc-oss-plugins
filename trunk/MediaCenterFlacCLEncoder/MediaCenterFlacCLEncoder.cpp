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
}
