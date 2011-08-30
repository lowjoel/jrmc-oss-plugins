#region Libraries
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;

using MediaCenter;

#endregion

namespace JoelLow.NowPlaying
{
	#region Interop Program ID Registration

	// This string must unique and match the String in the Inno Setup Script
	[System.Runtime.InteropServices.ProgId("JoelLow.WLMNowPlaying")]
	#endregion

	public partial class MainInterface : UserControl
	{
		#region Properties

		public MediaCenter.MCAutomation MediaCenterAutomation
		{
			get;
			private set;
		}

		public MediaCenter.IMJVersionAutomation MediaCenterVersion
		{
			get
			{
				return MediaCenterAutomation.GetVersion();
			}
		}

		public MediaCenter.IMJFileAutomation CurrentTrack
		{
			get
			{
				MediaCenter.IMJCurPlaylistAutomation playlist = MediaCenterAutomation.GetCurPlaylist();
				if (playlist != null)
					return playlist.GetFile(playlist.Position);
				else
					return null;
			}
		}
		
		#endregion

		#region Constructor

		public MainInterface()
		{
			InitializeComponent();
		}
		#endregion

		#region Media Center Initialisation

		// Set all Components on the Panel to invisible
		private void setVisibility(Control ctlControl, Boolean blnVisible)
		{
			while (ctlControl != null)
			{
				ctlControl.Visible = blnVisible;

				ctlControl = mainPanel.GetNextControl(ctlControl, true);
			}
		}

		/// <summary>
		/// Check the version of Media Center. I've only tested this on 14.0.160 and later.
		/// </summary>
		/// <returns></returns>
		private Boolean checkVersion()
		{
			IMJVersionAutomation version = MediaCenterAutomation.GetVersion();
			if (version.Major >= 14 && version.Minor >= 0 && version.Build >= 160)
			{
				return true;
			}

			setVisibility(Panel, false);

			Panel.Visible = true;
			txtUserInfo.Visible = true;

			addUserInfoText("This plugin only works for MC 14.0.160 and up");
			return false;
		}

		/// <summary>
		/// Plugin entry point.
		/// </summary>
		/// <param name="mcRef"></param>
		public void Init(MediaCenter.MCAutomation mcRef)
		{
			try
			{
				// This is the main entry for MC Automation
				MediaCenterAutomation = mcRef;

				// Check the version we're running in
				if (checkVersion())
				{
					// Set up a EventHandler to receive when Events happen
					MediaCenterAutomation.FireMJEvent +=
						new MediaCenter.IMJAutomationEvents_FireMJEventEventHandler(
							mediaCenterAutomation_FireMJEventHandler);
					
					// Init our plugin
					Initialize();

					addUserInfoText("Plugin Initiated OK");
				}
			}
			catch (Exception e)
			{
				errorHandler(e);
			}
		}

		#endregion

		#region Plugin functionality

		private void Initialize()
		{
			// Broadcast MC's current playing state
			UpdateOnPlayerStateChange();
		}

		private void mediaCenterAutomation_FireMJEventHandler(string bstrType, string bstrParam1, string bstrParam2)
        {
            switch (bstrType)
            {
                case "MJEvent type: MCCommand":
                    switch (bstrParam1)
                    {
                        case "MCC: NOTIFY_TRACK_CHANGE":
                            MediaCenter.IMJFileAutomation file = CurrentTrack;
                            if (file != null)
                                SetMSNMusic(true, file.Name, file.Artist, file.Album);
                            break;

                        case "MCC: NOTIFY_PLAYERSTATE_CHANGE":
                            UpdateOnPlayerStateChange();
                            break;

                        default:
                            // Unknown (new?) type
							addUserInfoText("Unknown command: " + bstrType + "-" + bstrParam1 + "-" + bstrParam2);
                            break;
                    }

                    break;

                default:
                    // Unknown (new?) type
					addUserInfoText("Unknown command: " + bstrType + "-" + bstrParam1 + "-" + bstrParam2);
                    break;
            }
        }

        private void UpdateOnPlayerStateChange()
        {
            MediaCenter.IMJFileAutomation file = CurrentTrack;
            if (file != null)
                switch (MediaCenterAutomation.GetPlayback().State)
                {
                    case MediaCenter.MJPlaybackStates.PLAYSTATE_STOPPED:
                        SetMSNMusic(false, "", "", "");
                        break;
                    case MediaCenter.MJPlaybackStates.PLAYSTATE_PLAYING:
                        SetMSNMusic(true, file.Name, file.Artist, file.Album);
                        break;
                    case MediaCenter.MJPlaybackStates.PLAYSTATE_PAUSED:
                        SetMSNMusic(true, file.Name, file.Artist, file.Album);
                        break;
                    default:
                        SetMSNMusic(false, "", "", "");
                        break;
                }
        }

		public static List<IntPtr> FindWindows(string wndclass, string title)
		{
			WindowSearchData sd = new WindowSearchData { Wndclass = wndclass, Title = title };
			EnumWindows(new EnumWindowsProc(EnumProc), ref sd);
			return sd.hWnds;
		}

		public static bool EnumProc(IntPtr hWnd, ref WindowSearchData data)
		{
			StringBuilder sb = new StringBuilder(1024);
			GetClassName(hWnd, sb, sb.Capacity);
			if (data.Wndclass == null || sb.ToString().ToUpperInvariant() == data.Wndclass.ToUpperInvariant())
			{
				sb = new StringBuilder(1024);
				GetWindowText(hWnd, sb, sb.Capacity);
				if (data.Title == null || sb.ToString().ToUpperInvariant() == data.Title.ToUpperInvariant())
				{
					data.hWnds.Add(hWnd);
				}
			}
			return true;
		}

		private void SetMSNMusic(bool enable, string title, string artist, string album)
		{
			string category = "Music";
			string buffer = "\\0" + category + "\\0" + (enable ? "1" : "0") + "\\0{0}-{1}\\0" + title + "\\0" + artist + "\\0" + album + "\\0\\0\0";

			MsnMusicData data;
			data.dwData = (IntPtr)0x0547;
			data.lpData = buffer;
			data.cbData = buffer.Length * sizeof(char);

			// Call method to update IM's - PlayingNow
			//IntPtr TargetWindow = FindWindowEx(IntPtr.Zero, IntPtr.Zero, "MsnMsgrUIManager", null);
			List<IntPtr> windows = FindWindows("MsnMsgrUIManager", null);
			foreach (IntPtr hwnd in windows)
			{
				IntPtr result = SendMessage(hwnd, WM_COPYDATA, IntPtr.Zero, ref data);
				addUserInfoText("SendMessage: " + result.ToString());
			}
		}

		#endregion

		#region ErrorHandler
		private void errorHandler(Exception e)
		{
#if DEBUG
			throw e;
#else
			addUserInfoText("A Fatal error has occured: " + e.Message);
			addUserInfoText("The Failure Occured In Class Object: " + e.Source);
			addUserInfoText("when calling Method " + e.TargetSite);
			addUserInfoText("The following Inner Exception was caused" + e.InnerException);
			addUserInfoText("The Stack Trace Follows:\r\n" + e.StackTrace);

			txtUserInfo.Dock = DockStyle.Fill;

			this.Enabled = false;
#endif
		}
		#endregion

		#region Setting Skin Colors

		private void skinPlugin()
		{
			try
			{
				// MC 12 does not support skinning of C# plugins
				// We do some pseudo skinning by setting the colors used in the skin
				setSkinColors();
			}
			catch (Exception e)
			{
				errorHandler(e);
			}
		}

		// Get the Color for an item and attribute (i.e. "Tree", "BackColor"
		// Look in the wiki for the Metamorphis subject for Items and Attributes
		// http://wiki.jrmediacenter.com/index.php/Metamorphis
		private Color getColor(String strItem, String strAttribute)
		{
			Color colReturned = Color.LightGray;
			int intColor;
			int intR;
			int intG;
			int intB;

			try
			{
				intColor = MediaCenterAutomation.GetSkinInfo(strItem, strAttribute);

				// The color is represented as an int in MC. 
				// Windows requires a ARGB Color object
				// Using bitshifting and masking to get the R, G and B values
				if (intColor != -1)
				{
					intR = intColor & 255;
					intG = (intColor >> 8) & 255;
					intB = (intColor >> 16) & 255;

					colReturned = Color.FromArgb(intR, intG, intB);
				}
			}
			catch (Exception e)
			{
				errorHandler(e);
			}

			return colReturned;
		}

		// Setting the Backcolor of a Control (if different)
		private void setBackColor(Control control, Color color)
		{
			if (!control.BackColor.Equals(color))
			{
				control.BackColor = color;
			}
		}

		// Setting the Forecolor of a Control (if different)
		private void setForeColor(Control control, Color color)
		{
			if (!control.ForeColor.Equals(color))
			{
				control.ForeColor = color;
			}
		}

		// Setting the Fore- and Backcolors of all Controls (if different)
		private void setAllColors(Control control)
		{
			while (control != null)
			{
				setBackColor(control, getColor("Tree", "BackColor"));
				setForeColor(control, getColor("Tree", "TextColor"));

				control = mainPanel.GetNextControl(control, true);
			}
		}

		// Setting the Color for Maininterface
		private void setMainInterfaceColors()
		{
			this.BackColor = getColor("Tree", "BackColor");
			this.ForeColor = getColor("Tree", "TextColor");
		}

		// Pseude Skin our Plugin
		private void setSkinColors()
		{
			try
			{
				setMainInterfaceColors();
				setAllColors(Panel);
			}
			catch (Exception e)
			{
				errorHandler(e);
			}
		}

		#endregion

		#region Event Handling

		// Just for debugging purposes. Fill a text in the txtUserInfo Textbox
		private void addUserInfoText(String strText)
		{
			txtUserInfo.Text = txtUserInfo.Text + strText + "\r\n";
		}

		// This routine is called by MC in case of an Event
		// s1 - String containing the the MC Command.
		// s2 - String containing the the MC Event
		// s3 - String containing supplement information for the Event (not always filled)
		private void MJEvent(String strCommand, String strEvent, String strEventInfo)
		{
			// Debug info
			addUserInfoText(strCommand + "/" + strEvent + "/" + strEventInfo);

			switch (strCommand)
			{
				case "MJEvent type: MCCommand":
					switch (strEvent)
					{
						case "MCC: NOTIFY_TRACK_CHANGE":
							// Your code goes here
							break;

						case "MCC: NOTIFY_PLAYERSTATE_CHANGE":
							// Your code goes here
							break;

						case "MCC: NOTIFY_PLAYLIST_ADDED":
							// Your code goes here
							break;

						case "MCC: NOTIFY_PLAYLIST_INFO_CHANGED":
							// Your code goes here
							break;

						case "MCC: NOTIFY_PLAYLIST_FILES_CHANGED":
							// Your code goes here
							break;

						case "MCC: NOTIFY_PLAYLIST_REMOVED":
							// Your code goes here
							break;

						case "MCC: NOTIFY_PLAYLIST_COLLECTION_CHANGED":
							// Your code goes here
							break;

						case "MCC: NOTIFY_PLAYLIST_PROPERTIES_CHANGED":
							// Your code goes here
							break;

						case "MCC: NOTIFY_SKIN_CHANGED":
							skinPlugin();
							break;
					}

					break;

				default:
					break;
			}
		}

		// At the time this template was created the MCC: NOTIFY_SKIN_CHANGED
		// Event didn't function correctly. Doing it on a PAINT Event from Windows.
		private void mainPanel_Paint(object sender, PaintEventArgs e)
		{
			skinPlugin();
		}

		#endregion

		#region Interop
		[DllImport("user32.dll", CharSet = CharSet.Auto)]
		private static extern IntPtr SendMessage(IntPtr hwnd, uint wMsg, IntPtr wParam, IntPtr lParam);

		[DllImport("user32.dll", EntryPoint = "FindWindowExW", CharSet = CharSet.Unicode)]
		private static extern IntPtr FindWindowEx(IntPtr hWnd1, IntPtr hWnd2, string lpsz1, string lpsz2);

		[StructLayout(LayoutKind.Sequential)]
		private struct COPYDATASTRUCT
		{
			public IntPtr dwData;
			public int cbData;
			public IntPtr lpData;
		}
		private const int WM_COPYDATA = 0x4A;

		private delegate bool EnumWindowsProc(IntPtr hWnd, ref WindowSearchData data);

		public class WindowSearchData
		{
			public string Wndclass;
			public string Title;
			public List<IntPtr> hWnds = new List<IntPtr>();
		}

		[DllImport("user32.dll")]
		[return: MarshalAs(UnmanagedType.Bool)]
		private static extern bool EnumWindows(EnumWindowsProc lpEnumFunc, ref WindowSearchData data);

		[DllImport("user32.dll", SetLastError = true, CharSet = CharSet.Auto)]
		public static extern int GetClassName(IntPtr hWnd, StringBuilder lpClassName, int nMaxCount);

		[DllImport("user32.dll", CharSet = CharSet.Auto, SetLastError = true)]
		public static extern int GetWindowText(IntPtr hWnd, StringBuilder lpString, int nMaxCount);

		[StructLayout(LayoutKind.Sequential, CharSet=CharSet.Unicode)]
		private struct MsnMusicData
		{
			public IntPtr dwData;
			public int cbData;
			public string lpData;
		}

		[DllImport("user32.dll", CharSet = CharSet.Unicode)]
		private static extern IntPtr SendMessage(IntPtr hwnd, uint wMsg, IntPtr wParam,
			ref MsnMusicData lParam);
		#endregion
	}
}
