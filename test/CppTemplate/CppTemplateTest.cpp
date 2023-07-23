#include <CppTemplate/CppTemplate.hpp>
#include <cassert>
#include <cstdlib>

#define assert_true(condition) assert((condition)) // NOLINT

auto main([[maybe_unused]] int argc, [[maybe_unused]] const char** argv) -> int
{
    CppTemplate::CppTemplate cpp_template{};
    assert_true(&cpp_template);

    return EXIT_SUCCESS;
}
