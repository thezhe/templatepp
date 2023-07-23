#include <CppTemplate/CppTemplate.hpp>
#include <cassert>
#include <cstdlib>

#define assert_true(condition) assert((condition)) // NOLINT

int main(int argc, const char** argv) // NOLINT
{
    CppTemplate::CppTemplate cpp_template{}; // NOLINT
    assert_true(&cpp_template);

    return EXIT_SUCCESS;
}
