#pragma once

#include "irq.h"

#if DMAMUX_BASE
	// Latest DMA specification: a flexible DMAMUX is present
#	define OPT_DMA_VERSION	3
#elif defined(DMA1_CSELR_BASE) || defined(DMA2_CSELR_BASE)
	// Improved DMA specs: Devices are still hardwired to Channels
#	define OPT_DMA_VERSION	2
#else
	// DMA specs for oldest STM32 models: devices are or'ed to Channels
#	define OPT_DMA_VERSION	1
#endif

namespace Bmt
{
namespace Dma
{

/// The DMA Peripheral
enum class Itf : uint8_t
{
	k1				///< DMA1 controller
#ifdef DMA2_BASE
	, k2			///< DMA2 controller
#endif
};

/// Channel of the DMA controller
enum class Chan : uint8_t
{
	k1			///< Channel 1 of the DMA controller
	, k2		///< Channel 2 of the DMA controller
	, k3		///< Channel 3 of the DMA controller
	, k4		///< Channel 4 of the DMA controller
	, k5		///< Channel 5 of the DMA controller
	, k6		///< Channel 6 of the DMA controller
	, k7		///< Channel 7 of the DMA controller
	, k8		///< Channel 8 of the DMA controller
	, kNone		///< Indicates configuration not available
};

#if OPT_DMA_VERSION == 2
enum class PerifSel : uint8_t
{
	k0,			///< DMA request selection 0b0000
	k1,			///< DMA request selection 0b0001
	k2,			///< DMA request selection 0b0010
	k3,			///< DMA request selection 0b0011
	k4,			///< DMA request selection 0b0100
	k5,			///< DMA request selection 0b0101
	k6,			///< DMA request selection 0b0110
	k7,			///< DMA request selection 0b0111
};
#endif

/// Key specifying a DMA channel selection for any served peripheral
template <
	Itf kItf
#if OPT_DMA_VERSION < 3
	, Chan kChan
#endif
#if OPT_DMA_VERSION == 2
	, PerifSel kChSel
#endif
> struct AnyID
{
	// Interface
	static constexpr Itf kItf_ = kItf;
#if OPT_DMA_VERSION < 3
	// Channel to be used
	static constexpr Chan kChan_ = kChan;
#endif
#if OPT_DMA_VERSION == 2
	// Channel selection
	static constexpr PerifSel kChSel_ = kChSel;
#endif
};


/// Data direction of the DMA operation
enum class Dir
{
	kMemToMem			///< Memory to memory
	, kPerToMem			///< Peripheral to memory
	, kPerToMemCircular	///< Peripheral to memory circular mode
	, kMemToPer			///< Memory to peripheral
	, kMemToPerCircular	///< Memory to peripheral circular mode
};

/// Policy used for the source/target pointer
enum class PtrPolicy
{
	kBytePtr			///< Performs a *pByte operation
	, kBytePtrInc		///< Performs a *pByte++ operation
	, kShortPtr			///< Performs a *pShort operation
	, kShortPtrInc		///< Performs a *pShort++ operation
	, kLongPtr			///< Performs a *pLong operation
	, kLongPtrInc		///< Performs a *pLong++ operation
};

/// The DMA priority
enum class Prio
{
	kLow				///< Low channel priority
	, kMedium			///< Medium channel priority
	, kHigh				///< High channel priority
	, kVeryHigh			///< Very high channel priority
};


}	// namespace Dma
}	// namespace Bmt


#if defined(STM32L4)
#	include "l4xx/dma.h"
#elif defined(STM32G4)
#	include "g4xx/dma.h"
#elif defined(STM32F1)
#	include "f1xx/dma.h"
#else
#	error Unsupported target MCU
#endif

