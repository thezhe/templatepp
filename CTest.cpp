#include <cstdlib>
#include <thezhe/cpp_template.hpp>
auto main() -> int
{
    thezhe::cpp_template::Example example{};
    static_assert(static_cast<bool>(&example));
    example.method();
    const auto retval{ static_cast<int>(example.getField() == 0) };
    return retval;
}
