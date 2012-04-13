; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
AppName=FlacCL Encoder Plugin for J. River Media Center
AppVerName=FlacCL Encoder Plugin for J. River Media Center 0.1
AppPublisher=Joel Low
AppPublisherURL=joelsplace.sg
AppSupportURL=joelsplace.sg
AppUpdatesURL=joelsplace.sg
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
Source: ..\..\bin\Release\Win32\CUETools.Codecs.dll; DestDir: {app}; Flags: ignoreversion recursesubdirs createallsubdirs;
Source: ..\..\bin\Release\Win32\CUETools.Codecs.FLACCL.dll; DestDir: {app}; Flags: ignoreversion recursesubdirs createallsubdirs;
Source: ..\..\bin\Release\Win32\CUETools.Codecs.FLAKE.dll; DestDir: {app}; Flags: ignoreversion recursesubdirs createallsubdirs;
Source: ..\..\bin\Release\Win32\OpenCLNet.dll; DestDir: {app}; Flags: ignoreversion recursesubdirs createallsubdirs;
Source: ..\..\bin\Release\Win32\MediaCenterFlacCLEncoder.dll; DestDir: {app}; Flags: ignoreversion recursesubdirs createallsubdirs;
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Run]
Filename: "regsvr32"; Parameters: """{app}\MediaCenterFlacCLEncoder.dll"""; WorkingDir: "{app}\"; StatusMsg: "Registering Plugin"; Flags:runhidden

[UninstallRun]
Filename: "regsvr32"; Parameters: "/u ""{app}\MediaCenterFlacCLEncoder.dll"""; WorkingDir: "{app}\"; StatusMsg: "Unregistering Plugin"; Flags:runhidden