#pragma once
#include <string>
namespace thezhe::templatepp
{
class Templatepp
{
public:
    [[nodiscard]] static constexpr bool staticAssertTrue() noexcept
    {
        return true;
    }
    [[nodiscard]] static bool assertTrue()
    {
        return !std::string("1").empty();
    }
private:
    constexpr Templatepp() noexcept = default;
};
} // namespace thezhe::templatepp
