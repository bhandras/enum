#ifndef _enum_h
#define _enum_h

#include <string>
#include <vector>
#include <sstream>

namespace utils
{
    std::vector<std::string> split(const std::string& s, const std::string& delimiter)
    {
        std::vector<std::string> result;
        std::string::size_type start = 0, end = 0;
        
        while ((end = s.find(delimiter, start)) != std::string::npos) {
            result.push_back(s.substr(start, end - start));
            start = end + delimiter.length();
        }
        
        result.push_back(s.substr(start));
        return result;
    }
}

#define MAKE_ENUM(name, ...)\
struct name {\
    enum name##_e { __VA_ARGS__, undefined };\
    static const std::string& as_string(name##_e e) {\
        return str_items()[e];\
    }\
    static name##_e from_string(const std::string& s) {\
        auto it = std::find(str_items().begin(), str_items().end(), s);\
        if (it != str_items().end()) {\
            return static_cast<name##_e>(std::distance(str_items().begin(), it));\
        }\
        return name##_e::undefined;\
    }\
private:\
    static const std::vector<std::string>& str_items() {\
        static std::vector<std::string> array = utils::split(#__VA_ARGS__, ", ");\
        return array;\
    }\
};

#endif // _enum_h
