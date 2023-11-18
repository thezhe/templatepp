#include <cstdlib>
#include <thezhe/templatepp.hpp>
auto main() -> int
{
    thezhe::templatepp::Example example{};
    static_assert(static_cast<bool>(&example));
    example.method();
    const auto retval{ static_cast<int>(example.getField() == 0) };
    return retval;
}
