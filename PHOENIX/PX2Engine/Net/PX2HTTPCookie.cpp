// PX2HTTPCookie.cpp

#include "PX2HTTPCookie.hpp"
#include "PX2NumberParser.hpp"
#include "PX2DateTimeParser.hpp"
#include "PX2Timespan.hpp"
#include "PX2DateTimeFormat.hpp"
#include "PX2DateTimeFormatter.hpp"
#include "PX2NumberFormatter.hpp"
#include "PX2URI.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
HTTPCookie::HTTPCookie() :
_version(0),
_secure(false),
_maxAge(-1),
_httpOnly(false)
{
}
//----------------------------------------------------------------------------
HTTPCookie::HTTPCookie(const std::string& name) :
_version(0),
_name(name),
_secure(false),
_maxAge(-1),
_httpOnly(false)
{
}
//----------------------------------------------------------------------------
HTTPCookie::HTTPCookie(const NameValueCollection& nvc) :
_version(0),
_secure(false),
_maxAge(-1),
_httpOnly(false)
{
	for (NameValueCollection::ConstIterator it = nvc.begin(); it != nvc.end(); ++it)
	{
		const std::string& name = it->first;
		const std::string& value = it->second;
		if (Icompare(name, "comment") == 0)
		{
			setComment(value);
		}
		else if (Icompare(name, "domain") == 0)
		{
			setDomain(value);
		}
		else if (Icompare(name, "path") == 0)
		{
			setPath(value);
		}
		else if (Icompare(name, "priority") == 0)
		{
			setPriority(value);
		}
		else if (Icompare(name, "max-age") == 0)
		{
			setMaxAge(NumberParser::parse(value));
		}
		else if (Icompare(name, "secure") == 0)
		{
			setSecure(true);
		}
		else if (Icompare(name, "expires") == 0)
		{
			int tzd;
			DateTime exp = DateTimeParser::parse(value, tzd);
			Timestamp now;
			setMaxAge((int)((exp.GetTimestamp() - now) / Timestamp::Resolution()));
		}
		else if (Icompare(name, "version") == 0)
		{
			SetVersion(NumberParser::parse(value));
		}
		else if (Icompare(name, "HttpOnly") == 0)
		{
			setHttpOnly(true);
		}
		else
		{
			setName(name);
			setValue(value);
		}
	}
}
//----------------------------------------------------------------------------
HTTPCookie::HTTPCookie(const std::string& name, const std::string& value) :
_version(0),
_name(name),
_value(value),
_secure(false),
_maxAge(-1),
_httpOnly(false)
{
}
//----------------------------------------------------------------------------
HTTPCookie::HTTPCookie(const HTTPCookie& cookie) :
_version(cookie._version),
_name(cookie._name),
_value(cookie._value),
_comment(cookie._comment),
_domain(cookie._domain),
_path(cookie._path),
_priority(cookie._priority),
_secure(cookie._secure),
_maxAge(cookie._maxAge),
_httpOnly(cookie._httpOnly)
{
}
//----------------------------------------------------------------------------
HTTPCookie::~HTTPCookie()
{
}
//----------------------------------------------------------------------------
HTTPCookie& HTTPCookie::operator = (const HTTPCookie& cookie)
{
	if (&cookie != this)
	{
		_version = cookie._version;
		_name = cookie._name;
		_value = cookie._value;
		_comment = cookie._comment;
		_domain = cookie._domain;
		_path = cookie._path;
		_priority = cookie._priority;
		_secure = cookie._secure;
		_maxAge = cookie._maxAge;
		_httpOnly = cookie._httpOnly;
	}
	return *this;
}
//----------------------------------------------------------------------------
void HTTPCookie::SetVersion(int version)
{
	_version = version;
}
//----------------------------------------------------------------------------
void HTTPCookie::setName(const std::string& name)
{
	_name = name;
}
//----------------------------------------------------------------------------
void HTTPCookie::setValue(const std::string& value)
{
	_value = value;
}
//----------------------------------------------------------------------------
void HTTPCookie::setComment(const std::string& comment)
{
	_comment = comment;
}
//----------------------------------------------------------------------------
void HTTPCookie::setDomain(const std::string& domain)
{
	_domain = domain;
}
//----------------------------------------------------------------------------
void HTTPCookie::setPath(const std::string& path)
{
	_path = path;
}
//----------------------------------------------------------------------------
void HTTPCookie::setPriority(const std::string& priority)
{
	_priority = priority;
}
//----------------------------------------------------------------------------
void HTTPCookie::setSecure(bool secure)
{
	_secure = secure;
}
//----------------------------------------------------------------------------
void HTTPCookie::setMaxAge(int maxAge)
{
	_maxAge = maxAge;
}
//----------------------------------------------------------------------------
void HTTPCookie::setHttpOnly(bool flag)
{
	_httpOnly = flag;
}
//----------------------------------------------------------------------------
std::string HTTPCookie::toString() const
{
	std::string result;
	result.reserve(256);
	result.append(_name);
	result.append("=");
	if (_version == 0)
	{
		// Netscape cookie
		result.append(_value);
		if (!_domain.empty())
		{
			result.append("; domain=");
			result.append(_domain);
		}
		if (!_path.empty())
		{
			result.append("; path=");
			result.append(_path);
		}
		if (!_priority.empty())
		{
			result.append("; Priority=");
			result.append(_priority);
		}
		if (_maxAge != -1)
		{
			Timestamp ts;
			ts += _maxAge * Timestamp::Resolution();
			result.append("; expires=");
			DateTimeFormatter::append(result, ts, DateTimeFormat::HTTP_FORMAT);
		}
		if (_secure)
		{
			result.append("; secure");
		}
		if (_httpOnly)
		{
			result.append("; HttpOnly");
		}
	}
	else
	{
		// RFC 2109 cookie
		result.append("\"");
		result.append(_value);
		result.append("\"");
		if (!_comment.empty())
		{
			result.append("; Comment=\"");
			result.append(_comment);
			result.append("\"");
		}
		if (!_domain.empty())
		{
			result.append("; Domain=\"");
			result.append(_domain);
			result.append("\"");
		}
		if (!_path.empty())
		{
			result.append("; Path=\"");
			result.append(_path);
			result.append("\"");
		}
		if (!_priority.empty())
		{
			result.append("; Priority=\"");
			result.append(_priority);
			result.append("\"");
		}

		if (_maxAge != -1)
		{
			result.append("; Max-Age=\"");
			NumberFormatter::append(result, _maxAge);
			result.append("\"");
		}
		if (_secure)
		{
			result.append("; secure");
		}
		if (_httpOnly)
		{
			result.append("; HttpOnly");
		}
		result.append("; Version=\"1\"");
	}
	return result;
}
//----------------------------------------------------------------------------
namespace
{
	static const std::string ILLEGAL_CHARS("()[]/|\\',;");
}
//----------------------------------------------------------------------------
std::string HTTPCookie::escape(const std::string& str)
{
	std::string result;
	URI::encode(str, ILLEGAL_CHARS, result);
	return result;
}
//----------------------------------------------------------------------------
std::string HTTPCookie::unescape(const std::string& str)
{
	std::string result;
	URI::decode(str, result);
	return result;
}
//----------------------------------------------------------------------------