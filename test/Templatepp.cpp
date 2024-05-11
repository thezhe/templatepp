#ifdef NDEBUG
    #undef NDEBUG // assert in Release
#endif
#include "thezhe/templatepp/Templatepp.hpp"
#include <cassert>
int main()
{
    using namespace thezhe::templatepp; // NOLINT
    assert(Templatepp::returnTrue());
}
