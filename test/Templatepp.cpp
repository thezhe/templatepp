#undef NDEBUG // assert in Release
#include <cassert>
#include <thezhe/templatepp.hpp>
int main()
{
    using namespace thezhe::templatepp; // NOLINT
    const Templatepp templatepp{};
    assert(Templatepp::assertTrue());
}
