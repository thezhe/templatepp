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
private:
    double field{};
};
} // namespace library
