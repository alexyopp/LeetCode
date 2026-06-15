#pragma once

#include <vector>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

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

    // RunTestCase for functions that take one input parameter
    // helper to detect std::tuple types
    template <typename T>
    struct is_tuple : std::false_type {};

    template <typename... Ts>
    struct is_tuple<std::tuple<Ts...>> : std::true_type {};

    // RunTestCase for functions that take one input parameter (disabled when Input is a tuple)
    template <typename Func, typename Input, typename Output,
              typename = std::enable_if_t<!is_tuple<std::decay_t<Input>>::value>>
    static inline bool RunTestCase(Func testFunction, const Input& input, const Output& expectedOutput)
    {
        auto result = testFunction(input);
        return result == expectedOutput;
    }

    // RunTestCase for functions that take no parameters
    template <typename Func, typename Output>
    static inline bool RunTestCase(Func testFunction, const Output& expectedOutput)
    {
        auto result = testFunction();
        return result == expectedOutput;
    }

    // RunTestCase for functions that take multiple parameters packed in a std::tuple
    template <typename Func, typename... Inputs, typename Output>
    static inline bool RunTestCase(Func testFunction, const std::tuple<Inputs...>& inputs, const Output& expectedOutput)
    {
        auto result = std::apply(testFunction, inputs);
        return result == expectedOutput;
    }
};
