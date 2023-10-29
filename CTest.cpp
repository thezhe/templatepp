#include <cassert>
#include <cstdlib>
#include <library.hpp>
#define assert_true(condition) assert((condition)) // NOLINT
auto main() -> int
{
    library::Component component{};
    assert_true(&component);
    return EXIT_SUCCESS;
}
