#pragma once

#include <cstdint>
#include <memory>

/** BASIC TYPES */
typedef std::int8_t int8;
typedef std::int16_t int16;
typedef std::int32_t int32;
typedef std::int64_t int64;

typedef std::uint8_t uint8;
typedef std::uint16_t uint16;
typedef std::uint32_t uint32;
typedef std::uint64_t uint64;

typedef float f32;
typedef double f64;

typedef uint32 flags;

/** SMART POINTERS TYPES */
// Ref (std::shared_ptr)
template<typename T>
using Ref = std::shared_ptr<T>;
template<typename T, typename... Args>
[[nodiscard]] constexpr Ref<T> CreateRef(Args&&... args)
{
	return std::make_shared<T>(std::forward<Args>(args)...);
}

template<typename T>
[[nodiscard]] constexpr Ref<T> MakeRef(T* rawPointer)
{
	return std::shared_ptr<T>(rawPointer);
}

// Scope (std::unique_ptr)
template<typename T>
using Scope = std::unique_ptr<T>;

template<typename T, typename... Args>
[[nodiscard]] constexpr std::unique_ptr<T> CreateScope(Args&&... args)
{
	return std::make_unique<T>(std::forward<Args>(args)...);
}

template<typename T>
[[nodiscard]] constexpr std::unique_ptr<T> MakeScope(T* rawPointer)
{
	return std::unique_ptr<T>(rawPointer);
}