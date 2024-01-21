#pragma once
#include <sstream>

inline std::stringstream make_string_stream(int argc, char** argv)
{
    std::stringstream string_stream;
    for (int i = 1; i < argc; ++i)
    {
        string_stream << argv[i] << ' ';
    }

    return string_stream;
}