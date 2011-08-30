using System;
using System.Collections.Generic;
using System.Text;

namespace JoelLow.NowPlaying
{
	class Util
	{
		public static List<IntPtr> FindWindows(string wndclass, string title)
		{
			NativeMethods.WindowSearchData sd = new NativeMethods.WindowSearchData {
				Wndclass = wndclass,
				Title = title
			};

			NativeMethods.EnumWindows(EnumProc, ref sd);
			return sd.hWnds;
		}

		private static bool EnumProc(IntPtr hWnd, ref NativeMethods.WindowSearchData data)
		{
			StringBuilder sb = new StringBuilder(1024);
			NativeMethods.GetClassName(hWnd, sb, sb.Capacity);

			if (data.Wndclass == null || sb.ToString().ToUpperInvariant() == data.Wndclass.ToUpperInvariant())
			{
				sb = new StringBuilder(1024);
				NativeMethods.GetWindowText(hWnd, sb, sb.Capacity);
				if (data.Title == null || sb.ToString().ToUpperInvariant() == data.Title.ToUpperInvariant())
				{
					data.hWnds.Add(hWnd);
				}
			}

			return true;
		}
	}
}
