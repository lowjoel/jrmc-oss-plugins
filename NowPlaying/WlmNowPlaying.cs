﻿using System;
using System.Collections.Generic;
using System.Text;

namespace JoelLow.NowPlaying
{
	static class WlmNowPlaying
	{
		public static void SetNowPlaying(bool playing, string artist, string album, string title,
			string trackDuration, string elapsedTrackTime)
		{
			string message = string.Format(@"\0{0}\0{1}\0{2}\0{3}\0{4}\0{5}\0WMContentID\0" + '\0',
				"Music",														//Category
				playing ? 1 : 0,												//Enabled
				"{0}-{1} ({2})",												//Display format string
				title,															//Title of the track
				artist,															//Artist of the track
				album															//Album
			);
			
			NativeMethods.MsnMusicData data;
			data.dwData = (IntPtr)0x0547;
			data.lpData = message;
			data.cbData = message.Length * sizeof(char);

			//Find the target windows to send the messages to (can be more than one)
			List<IntPtr> windows = Util.FindWindows("MsnMsgrUIManager", null);

			//Send the message.
			foreach (IntPtr hwnd in windows)
				NativeMethods.SendMessage(hwnd, NativeMethods.WM_COPYDATA, IntPtr.Zero, ref data);
		}
	}
}
