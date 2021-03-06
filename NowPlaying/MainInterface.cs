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
	[System.Runtime.InteropServices.ProgId("JoelLow.NowPlaying")]
	#endregion

	public partial class MainInterface : UserControl
	{
		#region Properties

		public static MediaCenter.MCAutomation MediaCenterAutomation
		{
			get;
			private set;
		}

		public static MediaCenter.IMJVersionAutomation MediaCenterVersion
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
			if (version.Major == 14 && version.Minor >= 0 && version.Build >= 160 ||
				version.Major > 14)
			{
				return true;
			}

			setVisibility(Panel, false);

			Panel.Visible = true;
			txtUserInfo.Visible = true;

			DebugPrint("This plugin only works for MC 14.0.160 and up");
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
				//Store our automation object.
				MediaCenterAutomation = mcRef;

				//Version check.
				if (checkVersion())
				{
					// Set up a EventHandler to receive when Events happen
					MediaCenterAutomation.FireMJEvent += OnMCEventRaised;
					
					// Init our plugin
					Initialize();

					DebugPrint("Plugin Initiated OK");
				}
			}
			catch (Exception e)
			{
				ErrorHandler(e);
			}
		}

		// Just for debugging purposes. Fill a text in the txtUserInfo Textbox
		private void DebugPrint(String strText)
		{
			txtUserInfo.Text = txtUserInfo.Text + strText + "\r\n";
		}

		private void ErrorHandler(Exception e)
		{
#if DEBUG
			throw e;
#else
			DebugPrint("A Fatal error has occured: " + e.Message);
			DebugPrint("The Failure Occured In Class Object: " + e.Source);
			DebugPrint("when calling Method " + e.TargetSite);
			DebugPrint("The following Inner Exception was caused" + e.InnerException);
			DebugPrint("The Stack Trace Follows:\r\n" + e.StackTrace);

			txtUserInfo.Dock = DockStyle.Fill;

			this.Enabled = false;
#endif
		}

		// At the time this template was created the MCC: NOTIFY_SKIN_CHANGED
		// Event didn't function correctly. Doing it on a PAINT Event from Windows.
		private void mainPanel_Paint(object sender, PaintEventArgs e)
		{
			SkinPlugin();
		}

		#endregion

		#region Plugin functionality

		/// <summary>
		/// Initialises the plugin functionality.
		/// </summary>
		private void Initialize()
		{
			//Broadcast MC's current playing state
			UpdateNowPlaying();
		}

		/// <summary>
		/// Handle's Media Center's events.
		/// </summary>
		/// <param name="bstrType">String containing the the MC Command.</param>
		/// <param name="bstrParam1">String containing the the MC Event</param>
		/// <param name="bstrParam2">String containing supplement information for
		/// the Event (not always filled)</param>
		private void OnMCEventRaised(string bstrType, string bstrParam1, string bstrParam2)
        {
            switch (bstrType)
            {
                case "MJEvent type: MCCommand":
                    switch (bstrParam1)
                    {
                        case "MCC: NOTIFY_TRACK_CHANGE":
                        case "MCC: NOTIFY_PLAYERSTATE_CHANGE":
							UpdateNowPlaying();
                            break;

						case "MCC: NOTIFY_SKIN_CHANGED":
							SkinPlugin();
							break;

						//Events we aren't interested in.
						case "MCC: NOTIFY_PLAYLIST_ADDED":
						case "MCC: NOTIFY_PLAYLIST_INFO_CHANGED":
						case "MCC: NOTIFY_PLAYLIST_FILES_CHANGED":
						case "MCC: NOTIFY_PLAYLIST_REMOVED":
						case "MCC: NOTIFY_PLAYLIST_COLLECTION_CHANGED":
						case "MCC: NOTIFY_PLAYLIST_PROPERTIES_CHANGED":
						case "MCC: NOTIFY_VOLUME_CHANGED":
						case "MCC: NOTIFY_EQ_CHANGED":
							break;

                        default:
							System.Diagnostics.Debug.Assert(false, "Unknown Event type");
							DebugPrint("Unknown command: " + bstrType + "-" + bstrParam1 + "-" + bstrParam2);
                            break;
                    }

                    break;

                default:
					System.Diagnostics.Debug.Assert(false, "Unknown Event type");
					DebugPrint("Unknown command: " + bstrType + "-" + bstrParam1 + "-" + bstrParam2);
                    break;
            }
        }

		/// <summary>
		/// Calls when the <see cref="RefreshTimer"/> ticks. This allows us to periodically
		/// send out the currently playing song so that if the event recipient is registered
		/// after MC starts, they will still get the message.
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		private void RefreshTimer_Tick(object sender, EventArgs e)
		{
			UpdateNowPlaying();
		}

		/// <summary>
		/// Updates clients on the currently playing file.
		/// </summary>
		private void UpdateNowPlaying()
		{
			switch (MediaCenterAutomation.GetPlayback().State)
			{
				case MediaCenter.MJPlaybackStates.PLAYSTATE_PLAYING:
				case MediaCenter.MJPlaybackStates.PLAYSTATE_PAUSED:
					MediaCenter.IMJFileAutomation file = CurrentTrack;
					if (file == null)
						return;

					//If we are no longer listening to audio, we should unset what's playing now.
					if (file.Get("Media Type", false) != "Audio") //Can be "Video" or "Image"
					{
						WlmNowPlaying.SetNowPlaying(false, null, null, null, null, null);
					}
					else
					{
						WlmNowPlaying.SetNowPlaying(true, file.Artist, file.Album, file.Name,
							null, null);
					}
					break;
				case MediaCenter.MJPlaybackStates.PLAYSTATE_STOPPED:
					WlmNowPlaying.SetNowPlaying(false, null, null, null, null, null);
					break;
			}
		}

		#endregion

		#region Skinning

		private void SkinPlugin()
		{
			try
			{
				// MC 12 does not support skinning of C# plugins
				// We do some pseudo skinning by setting the colors used in the skin
				setSkinColors();
			}
			catch (Exception e)
			{
				ErrorHandler(e);
			}
		}

		/// <summary>
		/// Get the Color for an item and attribute (i.e. "Tree", "BackColor"
		/// Look in the wiki for the Metamorphis subject for Items and Attributes
		/// http://wiki.jrmediacenter.com/index.php/Metamorphis
		/// </summary>
		/// <param name="strItem"></param>
		/// <param name="strAttribute"></param>
		/// <returns></returns>
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
				ErrorHandler(e);
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
			setMainInterfaceColors();
			setAllColors(Panel);
		}

		#endregion
	}
}
