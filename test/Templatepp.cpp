#ifdef NDEBUG
    #undef NDEBUG // assert in Release
#endif
#include <cassert>
#include <thezhe/templatepp/Templatepp.hpp>
int main()
{
    using namespace thezhe::templatepp; // NOLINT
    assert(Templatepp::returnTrue());
}
