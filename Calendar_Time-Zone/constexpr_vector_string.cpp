#include <string>
#include <iostream>

// 从language support得知，Text formatting的功能。。。好像各大厂商都没有支持的。。。
// 所以是不是就只能从https://github.com/fmtlib/fmt 第三方库来支持。。。。
int main(){
    auto message = std::format("The answer is {}.", 42);

    //Format and use positional arguments
    std::string s = fmt::format("I'd rather be {1} than {0}.", "right", "happy");
    //s == "I'd rather be happy than right."

    //Convert an integer to a string in a safe way
    fmt::memory_buffer buf;
    format_to{buf, "{}", 42}; // replaces itoa(42, buffer, 10)
    format_to(bug, "{:x}", 42); // replaces itoa(42, buffer, 16)
    // access the string with to_string(buf) or buf.data()

    return 1;
}
// // Format user-defined types
// struct date {
//   int year, month, day;
// };

// template <>
// struct fmt::formatter<date> {
//   template <typename ParseContext>
//   constexpr auto parse(ParseContext &ctx) { return ctx.begin(); }

//   template <typename FormatContext>
//   auto format(const date &d, FormatContext &ctx) {
//     return format_to(ctx.out(), "{}-{}-{}", d.year, d.month, d.day);
//   }
// };

// std::string s = fmt::format("The date is {}", date{2012, 12, 9});
// // s == "The date is 2012-12-9"