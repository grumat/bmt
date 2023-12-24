#pragma once


namespace Bmt
{

// A class designed for common BMT interface compatibility, but a dummy
struct DummyInit
{
	static constexpr ALWAYS_INLINE void Init() {}
	static constexpr ALWAYS_INLINE void Setup() {}
	static constexpr ALWAYS_INLINE void Enable() {}
	static constexpr ALWAYS_INLINE void Disable() {}
};

}
