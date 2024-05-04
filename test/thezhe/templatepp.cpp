#undef NDEBUG // assert in Release
#include <cassert>
#include <thezhe/templatepp.hpp>
int main()
{
    using namespace thezhe::templatepp; // NOLINT
    static_assert(Templatepp::staticAssertTrue());
    assert(Templatepp::assertTrue());
}
