#include <cassert>
#include <cstdlib>
#include <library.hpp>

#define assert_true(condition) assert((condition)) // NOLINT

int main([[maybe_unused]] int argc, [[maybe_unused]] const char** argv) // NOLINT
{
    [[maybe_unused]] CppTemplate::CppTemplate cpp_template{}; // NOLINT
    assert_true(&cpp_template);

    return EXIT_SUCCESS;
}