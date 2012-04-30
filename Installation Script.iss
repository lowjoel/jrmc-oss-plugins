; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
AppName=JRiver Media Center OSS Plugins
AppVerName=JRiver Media Center OSS Plugins 1.0.0
AppPublisher=Joel Low
AppPublisherURL=http://code.google.com/p/jrmc-oss-plugins
AppSupportURL=http://code.google.com/p/jrmc-oss-plugins
AppUpdatesURL=http://code.google.com/p/jrmc-oss-plugins
DefaultDirName={pf}\J River\Media Center 17\Plugins
DefaultGroupName=
DisableProgramGroupPage=yes
OutputBaseFilename=Setup
Compression=lzma
SolidCompression=yes
DirExistsWarning=No
SignTool=signtool

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Files]
Source: bin\Release\Win32\CUETools.Codecs.dll; DestDir: {app}; Flags: ignoreversion recursesubdirs createallsubdirs;
Source: bin\Release\Win32\CUETools.Codecs.FLACCL.dll; DestDir: {app}; Flags: ignoreversion recursesubdirs createallsubdirs;
Source: bin\Release\Win32\CUETools.Codecs.FLAKE.dll; DestDir: {app}; Flags: ignoreversion recursesubdirs createallsubdirs;
Source: bin\Release\Win32\OpenCLNet.dll; DestDir: {app}; Flags: ignoreversion recursesubdirs createallsubdirs;
Source: Dependencies\flac.cl; DestDir: {app}; Flags: ignoreversion recursesubdirs createallsubdirs;
Source: bin\Release\Win32\FlacCLEncoder.dll; DestDir: {app}; Flags: ignoreversion recursesubdirs createallsubdirs;

Source: bin\Release\NowPlaying.dll; DestDir: {app}; Flags: ignoreversion recursesubdirs createallsubdirs;
Source: bin\Release\Interop.MediaCenter.dll; DestDir: {app}; Flags: ignoreversion recursesubdirs createallsubdirs;
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Registry]
Root: HKLM; Subkey: "Software\J. River\Media Jukebox\Plugins\Interface\Now Playing"; Flags: uninsdeletekey
Root: HKLM; Subkey: "Software\J. River\Media Jukebox\Plugins\Interface\Now Playing"; ValueType: dword; ValueName: "IVersion"; ValueData: "00000001"; Flags: uninsdeletekey
Root: HKLM; Subkey: "Software\J. River\Media Jukebox\Plugins\Interface\Now Playing"; ValueType: string; ValueName: "Company"; ValueData: "Joel Low"; Flags: uninsdeletekey
Root: HKLM; Subkey: "Software\J. River\Media Jukebox\Plugins\Interface\Now Playing"; ValueType: string; ValueName: "Version"; ValueData: "0.1.0.20"; Flags: uninsdeletekey
Root: HKLM; Subkey: "Software\J. River\Media Jukebox\Plugins\Interface\Now Playing"; ValueType: string; ValueName: "URL"; ValueData: "joelsplace.sg"; Flags: uninsdeletekey
Root: HKLM; Subkey: "Software\J. River\Media Jukebox\Plugins\Interface\Now Playing"; ValueType: string; ValueName: "Copyright"; ValueData: "Copyright (c) 2011, Joel Low"; Flags: uninsdeletekey
Root: HKLM; Subkey: "Software\J. River\Media Jukebox\Plugins\Interface\Now Playing"; ValueType: dword; ValueName: "PluginMode"; ValueData: "00000001"; Flags: uninsdeletekey
Root: HKLM; Subkey: "Software\J. River\Media Jukebox\Plugins\Interface\Now Playing"; ValueType: string; ValueName: "ProdID"; ValueData: "JoelLow.NowPlaying"; Flags: uninsdeletekey

[Run]
Filename: "regsvr32"; Parameters: "/s ""{app}\MediaCenterFlacCLEncoder.dll"""; WorkingDir: "{app}\"; StatusMsg: "Registering FlacCL Encoder"; Flags:runhidden
Filename: "{win}\Microsoft.NET\Framework\v2.0.50727\regasm"; Parameters: "/Codebase ""{app}\NowPlaying.dll"""; WorkingDir: "{app}\"; StatusMsg: "Registering Now Playing"; Flags:runhidden

[UninstallRun]
Filename: "regsvr32"; Parameters: "/s /u ""{app}\MediaCenterFlacCLEncoder.dll"""; WorkingDir: "{app}\"; StatusMsg: "Unregistering FlacCL Encoder"; Flags:runhidden
Filename: "{win}\Microsoft.NET\Framework\v2.0.50727\regasm"; Parameters: "/unregister ""{app}\NowPlaying.dll"""; WorkingDir: "{app}\"; StatusMsg: "Registering Now Playing"; Flags:runhidden
