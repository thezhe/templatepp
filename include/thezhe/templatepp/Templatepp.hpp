#pragma once
namespace thezhe::templatepp
{
/*!
 * @brief Template library class
 */
class Templatepp
{
public:
    Templatepp() noexcept;
    /*!
     * @brief Always returns `true`
     */
    [[nodiscard]] static bool assertTrue() noexcept;
};
} // namespace thezhe::templatepp
