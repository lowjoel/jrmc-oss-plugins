using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace JoelLow.NowPlaying
{
	class NativeMethods
	{
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
		public const int WM_COPYDATA = 0x4A;

		public delegate bool EnumWindowsProc(IntPtr hWnd, ref WindowSearchData data);

		public class WindowSearchData
		{
			public string Wndclass;
			public string Title;
			public List<IntPtr> hWnds = new List<IntPtr>();
		}

		[DllImport("user32.dll")]
		[return: MarshalAs(UnmanagedType.Bool)]
		public static extern bool EnumWindows(EnumWindowsProc lpEnumFunc, ref WindowSearchData data);

		[DllImport("user32.dll", SetLastError = true, CharSet = CharSet.Auto)]
		public static extern int GetClassName(IntPtr hWnd, StringBuilder lpClassName, int nMaxCount);

		[DllImport("user32.dll", CharSet = CharSet.Auto, SetLastError = true)]
		public static extern int GetWindowText(IntPtr hWnd, StringBuilder lpString, int nMaxCount);

		[StructLayout(LayoutKind.Sequential, CharSet = CharSet.Unicode)]
		public struct MsnMusicData
		{
			public IntPtr dwData;
			public int cbData;
			public string lpData;
		}

		[DllImport("user32.dll", CharSet = CharSet.Unicode)]
		public static extern IntPtr SendMessage(IntPtr hwnd, uint wMsg, IntPtr wParam,
			ref MsnMusicData lParam);
	}
}
