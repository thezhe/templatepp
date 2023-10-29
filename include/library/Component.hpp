#pragma once
#include "detail/Detail.hpp"
namespace library
{
class Component : public detail::Detail
{
public:
    void method() noexcept
    {
        ++field;
    }
    void m2() {}
private:
    double field{};
};
} // namespace library
