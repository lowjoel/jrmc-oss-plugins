#pragma once

class BStr
{
public:
	BStr(BSTR str)
		: String(str)
	{
	}

	~BStr()
	{
		SysFreeString(String);
	}

	operator BSTR()
	{
		return String;
	}

	operator std::wstring()
	{
		return std::wstring(String, SysStringLen(String));
	}

private:
	BSTR String;
};
