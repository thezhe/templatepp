// Allow `assert` in release builds
#ifdef NDEBUG
    #undef NDEBUG
#endif
#include "thezhe/templatepp.hpp"
#include <cassert>
#include <cstdlib>
/*!
 * @brief Example interface implementation
 */
class Example final
{
public:
    [[nodiscard]] static bool returnTrue() noexcept
    {
        return true;
    }
};
/*!
 * @brief Interface test fixture
 */
template<thezhe::templatepp T>
void test_templatepp()
{
    static_assert(thezhe::templatepp<T>);
    assert(T::returnTrue());
}
/*!
 * @brief Test driver
 */
int main()
{
    test_templatepp<Example>();
    return EXIT_SUCCESS;
}
