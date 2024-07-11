#pragma once
#include <concepts>
#include <type_traits>
namespace thezhe
{
template<typename T>
concept templatepp = requires(T t) {
    { t.returnTrue() } noexcept -> std::same_as<bool>;
};
} // namespace thezhe
