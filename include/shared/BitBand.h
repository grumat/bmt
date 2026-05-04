#pragma once

#include <cstdint>
#include <cstddef>


namespace Bmt
{
namespace BitBand
{


/// True when `addr` lies in a region that has a bit-band alias on this core.
/// SRAM:       0x20000000 – 0x200FFFFF  →  alias 0x22000000
/// Peripheral: 0x40000000 – 0x400FFFFF  →  alias 0x42000000
constexpr bool IsBitBandable(uintptr_t addr)
{
#if defined(__CORTEX_M) && (__CORTEX_M == 3 || __CORTEX_M == 4)
	return (addr >= 0x40000000U && addr < 0x40100000U)
		|| (addr >= 0x20000000U && addr < 0x20100000U);
#else
	(void)addr;
	return false;
#endif
}


/// Computes the alias word address for bit `bit` (0..31) of the word at `addr`.
/// Works for both SRAM and peripheral regions in one expression.
constexpr uintptr_t Alias(uintptr_t addr, unsigned bit)
{
	return ((addr & 0xF00FFFFFU) | 0x02000000U)
		+ ((addr & 0x000FFFFFU) << 5)
		+ (bit << 2);
}


/// Single-bit reference into the bit-band region. A read or write of the alias
/// word is converted by hardware into an atomic single-bit RMW on the underlying
/// register — replacing a 3-cycle load/modify/store with a 1-cycle store.
template <uintptr_t kAddr, unsigned kBit>
struct Ref
{
	static_assert(IsBitBandable(kAddr),
		"Address is not in a bit-band region on this core");
	static_assert(kBit < 32, "Bit position out of range");

	static constexpr uintptr_t kAlias_ = Alias(kAddr, kBit);

	ALWAYS_INLINE static void Set()         { *reinterpret_cast<volatile uint32_t*>(kAlias_) = 1U; }
	ALWAYS_INLINE static void Clear()       { *reinterpret_cast<volatile uint32_t*>(kAlias_) = 0U; }
	ALWAYS_INLINE static void Write(bool v) { *reinterpret_cast<volatile uint32_t*>(kAlias_) = v ? 1U : 0U; }
	ALWAYS_INLINE static bool Get()         { return *reinterpret_cast<volatile uint32_t*>(kAlias_) != 0U; }
};


}	// namespace BitBand
}	// namespace Bmt
