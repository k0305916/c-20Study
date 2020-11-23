#include <string>
#include <algorithm>

// concerning a string literals as non-type template parameter
// not all compilers support the std::basic_fixed_string type already. It should be useful to provide the reader with the basic idea behind the type.

namespace std
{
    template struct basic_fixed_string
    {
        constexpr basic_fixed_string(const CharT (&foo)[N + 1U])
        {
            std::copy_n(foo, N + 1U, m_data);
        }

        CharT m_data[N + 1U]{};
    };

    template basic_fixed_string(const CharT (&str)[N])->basic_fixed_string;

    template using fixed_string = basic_fixed_string;
} // namespace std

    // and afterwards the example can look as
    //foo takes non-type template parameter
    // template 
class Foo
{
    static constexpr char const *Name = Str.m_data;

public:
    void hello() const
    {
        std::cout
    }
}

// ????????????
template <std::basic_fixed_string T>
class Foo
    {
        static constexpr char const *Name = T;

    public:
        void hello() const;
    };

    int main()
    {
        Foo<"Hello!"> foo;
        foo.hello();
    }