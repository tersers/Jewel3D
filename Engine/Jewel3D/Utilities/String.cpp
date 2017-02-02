// Copyright (c) 2017 Emilian Cioca
#include "Jewel3D/Precompiled.h"
#include "String.h"

#include <algorithm>
#include <cctype>

namespace
{
	static constexpr unsigned BUFFER_SIZE = 1024;
	static char buffer[BUFFER_SIZE] = { '\0' };
}

namespace Jwl
{
	void RemoveWhitespace(std::string& str)
	{
		str.erase(std::remove_if(str.begin(), str.end(), [](char x) {
			return std::isspace(x);
		}), str.end());
	}

	void RemoveRedundantWhitespace(std::string& str)
	{
		bool skipTabs = false;

		for (auto itr = str.begin(); itr < str.end() - 1; itr++)
		{
			char lhs = *itr;
			char rhs = *(itr + 1);

			if (skipTabs)
			{
				if (lhs == '\t')
				{
					continue;
				}
				else
				{
					skipTabs = false;
				}
			}

			// Subsequent tabs are allowed at the start of a line.
			if (lhs == '\n' && rhs == '\t')
			{
				skipTabs = true;
				continue;
			}

			// Never delete a single newline character.
			if (lhs == '\n' && rhs != '\n' ||
				lhs != '\n' && rhs == '\n')
			{
				continue;
			}

			if (std::isspace(lhs) && std::isspace(rhs))
			{
				str.erase(itr--);
			}
		}
	}

	std::string FormatString(const char* format, ...)
	{
		std::string result;

		va_list argptr;
		va_start(argptr, format);
		result = FormatString(format, argptr);
		va_end(argptr);

		return result;
	}
	
	std::string FormatString(const char* format, va_list args)
	{
		if (vsnprintf(buffer, BUFFER_SIZE, format, args) < 0)
		{
			return std::string();
		}
		else
		{
			return buffer;
		}
	}
}
