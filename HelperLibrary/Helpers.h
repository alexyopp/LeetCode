#pragma once

#include <vector>
#include <string>

class Helpers
{
public:
    template <typename T>
    static inline std::string VectorToString(const std::vector<T>& vec)
    {
        std::string result = "[";
        for (size_t i = 0; i < vec.size(); ++i)
        {
            result += std::to_string(vec[i]);
            if (i < vec.size() - 1)
            {
                result += ", ";
            }
        }
        result += "]";
        return result;
    }
};
