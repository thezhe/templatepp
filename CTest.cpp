#include <cstdlib>
#include <library.hpp>
auto main() -> int
{
    library::Component component{};
    static_assert(static_cast<bool>(&component));
    component.method();
    return static_cast<int>(component.getField() > 0);
}
