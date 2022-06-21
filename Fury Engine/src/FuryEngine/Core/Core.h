#pragma once

#include <memory>

#ifdef FURY_PLATFORM_WINDOWS
	#ifdef FURY_BUILD_DLL
		#define FURY_API __declspec(dllexport)
	#else
		#define FURY_API __declspec(dllimport)
	#endif
#else
	#error Fury Engine only supports Windows!
#endif

#define BIT(x) (1 << x)

namespace FuryEngine {
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	using Data = const void*;
	using u8 = uint8_t;
	using u16 = uint16_t;
	using u32 = uint32_t;
	using u64 = uint64_t;
}