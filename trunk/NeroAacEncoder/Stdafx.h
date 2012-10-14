// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#include <map>

#include <Windows.h>
#include <OleCtl.h>

#include <tchar.h>
#include <vcclr.h>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

#pragma warning(push)
#pragma warning(disable: 4793 4835)
#include <boost/lexical_cast.hpp>
#include <boost/archive/text_wiarchive.hpp>
#include <boost/archive/text_woarchive.hpp>
#include <boost/serialization/serialization.hpp>
#pragma warning(pop)
