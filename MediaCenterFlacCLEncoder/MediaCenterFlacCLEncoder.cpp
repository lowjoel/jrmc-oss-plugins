// This is the main DLL file.

#include "stdafx.h"

#include "MediaCenterFlacCLEncoder.h"

using namespace System;
using namespace System::IO;
using namespace System::Reflection;
using namespace CUETools::Codecs::FLACCL;

namespace MediaCenterFlacCLEncoder {
	MediaCenterFlacCLEncoder::MediaCenterFlacCLEncoder(String^ outPath)
	{
		Writer = nullptr;/*gcnew FLACCLWriter((output_file == "-" || output_file == "nul") ? "" : output_file,
				output_file == "-" ? Console.OpenStandardOutput() :
				output_file == "nul" ? new NullStream() : null,
				audioSource.PCM);
			encoder.FinalSampleCount = audioSource.Length;*/
		Writer->FinalSampleCount = 0;
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
}
