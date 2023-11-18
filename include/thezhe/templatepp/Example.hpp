#pragma once
#include "detail/Detail.hpp"
namespace thezhe::templatepp
{
class Example
{
public:
    constexpr void method() noexcept
    {
        ++value;
    }
    [[nodiscard]] constexpr auto getField() const noexcept
    {
        return value;
    }
private:
    double value{};
    [[no_unique_address]] detail::Detail field{};
};
} // namespace thezhe::templatepp
