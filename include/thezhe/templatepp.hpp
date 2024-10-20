#pragma once
#include <concepts>
namespace thezhe
{
/*!
 * @brief Example interface
 */
template<typename T>
concept templatepp = requires(T t) {
    { t.returnTrue() } noexcept -> std::same_as<bool>;
};
} // namespace thezhe
