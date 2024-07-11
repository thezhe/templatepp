#undef NDEBUG
#include "thezhe/templatepps/Templatepp.hpp"
#include "thezhe/templatepp.hpp"
#include <cassert>
template<thezhe::templatepp T>
void test_templatepp()
{
    assert(T::returnTrue());
}
int main()
{
    using namespace thezhe::templatepps; // NOLINT
    test_templatepp<Templatepp>();
}
