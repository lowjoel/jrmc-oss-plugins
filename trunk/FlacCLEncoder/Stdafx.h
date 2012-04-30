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
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/logic/tribool.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/archive/text_wiarchive.hpp>
#include <boost/archive/text_woarchive.hpp>
#include <boost/serialization/serialization.hpp>
#pragma warning(pop)

#include "JREncoder.h"
