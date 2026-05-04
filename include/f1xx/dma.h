#pragma once

#include "../shared/RccEnabler.h"	// required for `Clocks::RccTrait`
#include "../shared/BitBand.h"		// for EnableFast()

namespace Bmt
{
namespace Dma
{

/// Trait carrier for a whole DMA controller — list this in `PeripheralEnabler`
/// once per controller used (DMA1, DMA2). Cheaper than listing every channel.
template <Itf kItf>
struct Controller
{
	using RccTrait_ = Clocks::RccTrait<
		Clocks::RccBit<Clocks::RccReg::kAhb1En,
#ifdef RCC_AHBENR_DMA1EN
			(kItf == Itf::k1) ? RCC_AHBENR_DMA1EN
#	ifdef RCC_AHBENR_DMA2EN
			: (kItf == Itf::k2) ? RCC_AHBENR_DMA2EN
#	endif
			: 0
#elif defined(RCC_AHB1ENR_DMA1EN)
			(kItf == Itf::k1) ? RCC_AHB1ENR_DMA1EN
#	ifdef RCC_AHB1ENR_DMA2EN
			: (kItf == Itf::k2) ? RCC_AHB1ENR_DMA2EN
#	endif
			: 0
#else
			0
#endif
		>
	>;
};


/// Template class that describes a DMA configuration
template <
	typename kDmaID						///< The DMA::AnyID<> resource identification
	, const Dir kDir					///< Data direction for this channel
	, const PtrPolicy kSrcPtr			///< Source Pointer behavior
	, const PtrPolicy kDstPtr			///< Target Pointer behavior
	, const Prio kPrio = Prio::kMedium	///< DMA transfer priority
	, const bool doInitNvic = false		///< Should be the NVIC also initialized?
>
class AnyChannel
{
public:
	// A DMA::AnyID<> definition that identifies the DMA
	using DmaID_ = kDmaID;
	/// A constant with the DMA controller instance number
	static constexpr Itf kDma_ = kDmaID::kItf_;
	/// A constant with the DMA channel number
	static constexpr Chan kChan_ = kDmaID::kChan_;
	/// The address base of the DMA peripheral
	static constexpr uint32_t kDmaBase_ =
		(kDma_ == Itf::k1) ? DMA1_BASE
#ifdef DMA2_BASE
		: (kDma_ == Itf::k2) ? DMA2_BASE
#endif
		: 0;
	/// The address base of the DMA channel peripheral
	static constexpr uint32_t kChBase_ =
		(kDma_ == Itf::k1 && kChan_ == Chan::k1) ? DMA1_Channel1_BASE
		: (kDma_ == Itf::k1 && kChan_ == Chan::k2) ? DMA1_Channel2_BASE
		: (kDma_ == Itf::k1 && kChan_ == Chan::k3) ? DMA1_Channel3_BASE
		: (kDma_ == Itf::k1 && kChan_ == Chan::k4) ? DMA1_Channel4_BASE
		: (kDma_ == Itf::k1 && kChan_ == Chan::k5) ? DMA1_Channel5_BASE
		: (kDma_ == Itf::k1 && kChan_ == Chan::k6) ? DMA1_Channel6_BASE
#ifdef DMA1_Channel7_BASE
		: (kDma_ == Itf::k1 && kChan_ == Chan::k7) ? DMA1_Channel7_BASE
#endif
#ifdef DMA1_Channel8_BASE
		: (kDma_ == Itf::k1 && kChan_ == Chan::k8) ? DMA1_Channel8_BASE
#endif
#ifdef DMA2_BASE
		: (kDma_ == Itf::k2 && kChan_ == Chan::k1) ? DMA2_Channel1_BASE
		: (kDma_ == Itf::k2 && kChan_ == Chan::k2) ? DMA2_Channel2_BASE
		: (kDma_ == Itf::k2 && kChan_ == Chan::k3) ? DMA2_Channel3_BASE
		: (kDma_ == Itf::k2 && kChan_ == Chan::k4) ? DMA2_Channel4_BASE
		: (kDma_ == Itf::k2 && kChan_ == Chan::k5) ? DMA2_Channel5_BASE
#endif
#ifdef DMA2_Channel6_BASE
		: (kDma_ == Itf::k2 && kChan_ == Chan::k6) ? DMA2_Channel6_BASE
#endif
#ifdef DMA2_Channel7_BASE
		: (kDma_ == Itf::k2 && kChan_ == Chan::k7) ? DMA2_Channel7_BASE
#endif
#ifdef DMA2_Channel8_BASE
		: (kDma_ == Itf::k2 && kChan_ == Chan::k8) ? DMA2_Channel8_BASE
#endif
		: 0;
	/// Transfer error Interrupt flag for the DMA channel
	static constexpr uint32_t kTeif =
		(kChan_ == Chan::k1) ? DMA_ISR_TEIF1
		: (kChan_ == Chan::k2) ? DMA_ISR_TEIF2
		: (kChan_ == Chan::k3) ? DMA_ISR_TEIF3
		: (kChan_ == Chan::k4) ? DMA_ISR_TEIF4
		: (kChan_ == Chan::k5) ? DMA_ISR_TEIF5
		: (kChan_ == Chan::k6) ? DMA_ISR_TEIF6
#ifdef DMA_ISR_TEIF7
		: (kChan_ == Chan::k7) ? DMA_ISR_TEIF7
#endif
#ifdef DMA_ISR_TEIF8
		: (kChan_ == Chan::k8) ? DMA_ISR_TEIF8
#endif
		: 0;
	/// Half transfer event Interrupt flag for the DMA channel
	static constexpr uint32_t kHtif =
		(kChan_ == Chan::k1) ? DMA_ISR_HTIF1
		: (kChan_ == Chan::k2) ? DMA_ISR_HTIF2
		: (kChan_ == Chan::k3) ? DMA_ISR_HTIF3
		: (kChan_ == Chan::k4) ? DMA_ISR_HTIF4
		: (kChan_ == Chan::k5) ? DMA_ISR_HTIF5
		: (kChan_ == Chan::k6) ? DMA_ISR_HTIF6
#ifdef DMA_ISR_HTIF7
		: (kChan_ == Chan::k7) ? DMA_ISR_HTIF7
#endif
#ifdef DMA_ISR_HTIF8
		: (kChan_ == Chan::k8) ? DMA_ISR_HTIF8
#endif
		: 0;
	/// Transfer complete Interrupt flag for the DMA channel
	static constexpr uint32_t kTcif =
		(kChan_ == Chan::k1) ? DMA_ISR_TCIF1
		: (kChan_ == Chan::k2) ? DMA_ISR_TCIF2
		: (kChan_ == Chan::k3) ? DMA_ISR_TCIF3
		: (kChan_ == Chan::k4) ? DMA_ISR_TCIF4
		: (kChan_ == Chan::k5) ? DMA_ISR_TCIF5
		: (kChan_ == Chan::k6) ? DMA_ISR_TCIF6
#ifdef DMA_ISR_TCIF7
		: (kChan_ == Chan::k7) ? DMA_ISR_TCIF7
#endif
#ifdef DMA_ISR_TCIF8
		: (kChan_ == Chan::k8) ? DMA_ISR_TCIF8
#endif
		: 0;
	/// Global interrupt flag for the DMA channel
	static constexpr uint32_t kGif =
		(kChan_ == Chan::k1) ? DMA_ISR_GIF1
		: (kChan_ == Chan::k2) ? DMA_ISR_GIF2
		: (kChan_ == Chan::k3) ? DMA_ISR_GIF3
		: (kChan_ == Chan::k4) ? DMA_ISR_GIF4
		: (kChan_ == Chan::k5) ? DMA_ISR_GIF5
		: (kChan_ == Chan::k6) ? DMA_ISR_GIF6
#ifdef DMA_ISR_GIF7
		: (kChan_ == Chan::k7) ? DMA_ISR_GIF7
#endif
#ifdef DMA_ISR_GIF8
		: (kChan_ == Chan::k8) ? DMA_ISR_GIF8
#endif
		: 0;
	/// RCC enable trait — DMA on F1 has no reset bit, only AHBENR enable.
	using RccTrait_ = Clocks::RccTrait<
		Clocks::RccBit<Clocks::RccReg::kAhb1En,
#ifdef RCC_AHBENR_DMA1EN
			(kDma_ == Itf::k1) ? RCC_AHBENR_DMA1EN
#	ifdef RCC_AHBENR_DMA2EN
			: (kDma_ == Itf::k2) ? RCC_AHBENR_DMA2EN
#	endif
			: 0
#elif defined(RCC_AHB1ENR_DMA1EN)
			(kDma_ == Itf::k1) ? RCC_AHB1ENR_DMA1EN
#	ifdef RCC_AHB1ENR_DMA2EN
			: (kDma_ == Itf::k2) ? RCC_AHB1ENR_DMA2EN
#	endif
			: 0
#else
			0
#endif
		>
	>;
	/// NVIC initialization flag
	static constexpr bool kDoInitNvic = doInitNvic;
	/// NVIC Interrupt flag for the DMA channel
	static constexpr IRQn_Type kNvicDmaIrqn_ =
		(kDma_ == Itf::k1 && kChan_ == Chan::k1) ? DMA1_Channel1_IRQn
		: (kDma_ == Itf::k1 && kChan_ == Chan::k2) ? DMA1_Channel2_IRQn
		: (kDma_ == Itf::k1 && kChan_ == Chan::k3) ? DMA1_Channel3_IRQn
		: (kDma_ == Itf::k1 && kChan_ == Chan::k4) ? DMA1_Channel4_IRQn
		: (kDma_ == Itf::k1 && kChan_ == Chan::k5) ? DMA1_Channel5_IRQn
		: (kDma_ == Itf::k1 && kChan_ == Chan::k6) ? DMA1_Channel6_IRQn
#ifdef DMA1_Channel7_IRQn
		: (kDma_ == Itf::k1 && kChan_ == Chan::k7) ? DMA1_Channel7_IRQn
#endif
#ifdef DMA1_Channel8_IRQn
		: (kDma_ == Itf::k1 && kChan_ == Chan::k8) ? DMA1_Channel8_IRQn
#endif
#ifdef DMA2_BASE
		: (kDma_ == Itf::k2 && kChan_ == Chan::k1) ? DMA2_Channel1_IRQn
		: (kDma_ == Itf::k2 && kChan_ == Chan::k2) ? DMA2_Channel2_IRQn
		: (kDma_ == Itf::k2 && kChan_ == Chan::k3) ? DMA2_Channel3_IRQn
		: (kDma_ == Itf::k2 && kChan_ == Chan::k4) ? DMA2_Channel4_IRQn
		: (kDma_ == Itf::k2 && kChan_ == Chan::k5) ? DMA2_Channel5_IRQn
#endif
#ifdef DMA2_Channel6_IRQn
		: (kDma_ == Itf::k2 && kChan_ == Chan::k6) ? DMA2_Channel6_IRQn
#endif
#ifdef DMA2_Channel7_IRQn
		: (kDma_ == Itf::k2 && kChan_ == Chan::k7) ? DMA2_Channel7_IRQn
#endif
#ifdef DMA2_Channel8_IRQn
		: (kDma_ == Itf::k2 && kChan_ == Chan::k8) ? DMA2_Channel8_IRQn
#endif
		: DMA1_Channel1_IRQn;
	/// The IRQ configuration template for that DMA channel
	using DmaIrq = IrqTemplate<kNvicDmaIrqn_>;
	/// Returns root device structure
	ALWAYS_INLINE static volatile DMA_TypeDef *GetDeviceRoot() { return (DMA_TypeDef *)kDmaBase_; }
	/// Returns device structure for the channel
	ALWAYS_INLINE static volatile DMA_Channel_TypeDef *GetDevice() { return (DMA_Channel_TypeDef *)kChBase_; }

	/// DEPRECATED — DMA clock is enabled at boot via the platform's
	/// `PeripheralEnabler`. Call `Setup()` (and `EnableNvic()` if needed).
	[[deprecated("Add this DMA channel to platform PeripheralEnabler, then call Setup()")]]
	ALWAYS_INLINE static void Init()
	{
		Clocks::Enabler<AnyChannel>::Enable();
		if (kDoInitNvic)
			EnableNvic();
		Setup();
	}

	/// Enables the channel's NVIC line. Idempotent — safe to call from Setup().
	ALWAYS_INLINE static void EnableNvic()
	{
		DmaIrq::ClearPending();
		DmaIrq::Enable();
	}

	/// Stops the entire DMA controller
	ALWAYS_INLINE static void Stop()
	{
		Clocks::Enabler<AnyChannel>::Disable();
	}

	/// DMA controller initialization
	ALWAYS_INLINE static void Setup()
	{
		static_assert(kDmaBase_ != 0, "Invalid DMA instance selected");
		static_assert(kChBase_ != 0, "Invalid DMA instance selected");
		/*
		** This rather complex logic is reduced at maximum by the optimizing compiler, since
		** everything is declared as constexpr.
		*/
		uint32_t tmp = uint32_t(kPrio) << DMA_CCR_PL_Pos;
		switch (kDir)
		{
		case Dir::kMemToMem:
			tmp |= DMA_CCR_MEM2MEM;
			break;
		case Dir::kPerToMem:
			break;
		case Dir::kPerToMemCircular:
			tmp |= DMA_CCR_CIRC;
			break;
		case Dir::kMemToPer:
			tmp |= DMA_CCR_DIR;
			break;
		case Dir::kMemToPerCircular:
			tmp |= DMA_CCR_DIR | DMA_CCR_CIRC;
			break;
		}
		if (kDir == Dir::kMemToPer || kDir == Dir::kMemToPerCircular)
		{
			switch (kSrcPtr)
			{
			case PtrPolicy::kBytePtr:
				break;
			case PtrPolicy::kBytePtrInc:
				tmp |= DMA_CCR_MINC;
				break;
			case PtrPolicy::kShortPtr:
				tmp |= DMA_CCR_MSIZE_0;
				break;
			case PtrPolicy::kShortPtrInc:
				tmp |= DMA_CCR_MINC | DMA_CCR_MSIZE_0;
				break;
			case PtrPolicy::kLongPtr:
				tmp |= DMA_CCR_MSIZE_1;
				break;
			case PtrPolicy::kLongPtrInc:
				tmp |= DMA_CCR_MINC | DMA_CCR_MSIZE_1;
				break;
			}
			switch (kDstPtr)
			{
			case PtrPolicy::kBytePtr:
				break;
			case PtrPolicy::kBytePtrInc:
				tmp |= DMA_CCR_PINC;
				break;
			case PtrPolicy::kShortPtr:
				tmp |= DMA_CCR_PSIZE_0;
				break;
			case PtrPolicy::kShortPtrInc:
				tmp |= DMA_CCR_PINC | DMA_CCR_PSIZE_0;
				break;
			case PtrPolicy::kLongPtr:
				tmp |= DMA_CCR_PSIZE_1;
				break;
			case PtrPolicy::kLongPtrInc:
				tmp |= DMA_CCR_PINC | DMA_CCR_PSIZE_1;
				break;
			}
		}
		else
		{
			switch (kSrcPtr)
			{
			case PtrPolicy::kBytePtr:
				break;
			case PtrPolicy::kBytePtrInc:
				tmp |= DMA_CCR_PINC;
				break;
			case PtrPolicy::kShortPtr:
				tmp |= DMA_CCR_PSIZE_0;
				break;
			case PtrPolicy::kShortPtrInc:
				tmp |= DMA_CCR_PINC | DMA_CCR_PSIZE_0;
				break;
			case PtrPolicy::kLongPtr:
				tmp |= DMA_CCR_PSIZE_1;
				break;
			case PtrPolicy::kLongPtrInc:
				tmp |= DMA_CCR_PINC | DMA_CCR_PSIZE_1;
				break;
			}
			switch (kDstPtr)
			{
			case PtrPolicy::kBytePtr:
				break;
			case PtrPolicy::kBytePtrInc:
				tmp |= DMA_CCR_MINC;
				break;
			case PtrPolicy::kShortPtr:
				tmp |= DMA_CCR_MSIZE_0;
				break;
			case PtrPolicy::kShortPtrInc:
				tmp |= DMA_CCR_MINC | DMA_CCR_MSIZE_0;
				break;
			case PtrPolicy::kLongPtr:
				tmp |= DMA_CCR_MSIZE_1;
				break;
			case PtrPolicy::kLongPtrInc:
				tmp |= DMA_CCR_MINC | DMA_CCR_MSIZE_1;
				break;
			}
		}
		volatile DMA_Channel_TypeDef *dma = GetDevice();
		dma->CCR = tmp;
	}

	/// Enables the DMA channel
	ALWAYS_INLINE static void Enable()
	{
		volatile DMA_Channel_TypeDef *dma = GetDevice();
		dma->CCR |= DMA_CCR_EN;
	}

	/// Bit-band variant of Enable(): single-cycle store, no read-modify-write.
	/// Use when deterministic timing matters (e.g. phase-locked startup with a timer).
	/// Available on Cortex-M3/M4 only — the static_assert in BitBand::Ref<> will
	/// fail at compile time on cores without a peripheral bit-band region.
	ALWAYS_INLINE static void EnableFast()
	{
		BitBand::Ref<kChBase_ + offsetof(DMA_Channel_TypeDef, CCR), DMA_CCR_EN_Pos>::Set();
	}

	/// Disables the DMA channel
	ALWAYS_INLINE static void Disable()
	{
		volatile DMA_Channel_TypeDef *dma = GetDevice();
		dma->CCR &= ~DMA_CCR_EN;
	}

	/// Sets the number of transfers that will occur
	ALWAYS_INLINE static void SetTransferCount(uint16_t cnt)
	{
		volatile DMA_Channel_TypeDef *dma = GetDevice();
		dma->CNDTR = cnt;
	}

	/// Returns current transfer count
	ALWAYS_INLINE static uint16_t GetTransferCount()
	{
		volatile DMA_Channel_TypeDef *dma = GetDevice();
		return (uint16_t)dma->CNDTR;
	}

	/// Sets the source pointer address
	ALWAYS_INLINE static void SetSourceAddress(const volatile void *addr)
	{
		volatile DMA_Channel_TypeDef *dma = GetDevice();
		if (kDir == Dir::kMemToPer || kDir == Dir::kMemToPerCircular)
			dma->CMAR = (uint32_t)addr;
		else
			dma->CPAR = (uint32_t)addr;
	}

	/// Sets the destination pointer address
	ALWAYS_INLINE static void SetDestAddress(volatile void *addr)
	{
		volatile DMA_Channel_TypeDef *dma = GetDevice();
		if (kDir == Dir::kMemToPer || kDir == Dir::kMemToPerCircular)
			dma->CPAR = (uint32_t)addr;
		else
			dma->CMAR = (uint32_t)addr;
	}

	/// Starts a transfer
	ALWAYS_INLINE static void Start(const volatile void *src, volatile void *dst, uint16_t cnt)
	{
		Disable();
		SetSourceAddress(src);
		SetDestAddress(dst);
		SetTransferCount(cnt);
		Enable();
	}

	/// Enables transfer error interrupt
	ALWAYS_INLINE static void EnableTransferErrorInt()
	{
		volatile DMA_Channel_TypeDef *dma = GetDevice();
		dma->CCR |= DMA_CCR_TEIE;
	}
	/// Disables transfer error interrupt
	ALWAYS_INLINE static void DisableTransferErrorInt()
	{
		volatile DMA_Channel_TypeDef *dma = GetDevice();
		dma->CCR &= ~DMA_CCR_TEIE;
	}
	/// Checks if transfer error interrupt flag is signaled
	ALWAYS_INLINE static bool IsTransferError()
	{
		volatile DMA_TypeDef *dma = GetDeviceRoot();
		return (dma->ISR & kTeif) != 0;
	}
	/// Clears the transfer error interrupt flag
	ALWAYS_INLINE static void ClearTransferErrorFlag()
	{
		volatile DMA_TypeDef *dma = GetDeviceRoot();
		dma->IFCR |= kTeif;
	}

	/// Enables the half transfer interrupt
	ALWAYS_INLINE static void EnableHalfTransferInt()
	{
		volatile DMA_Channel_TypeDef *dma = GetDevice();
		dma->CCR |= DMA_CCR_HTIE;
	}
	/// Disables the half transfer interrupt
	ALWAYS_INLINE static void DisableHalfTransferInt()
	{
		volatile DMA_Channel_TypeDef *dma = GetDevice();
		dma->CCR &= ~DMA_CCR_HTIE;
	}
	/// Checks if the half transfer interrupt flag is signaled
	ALWAYS_INLINE static bool IsHalfTransfer()
	{
		volatile DMA_TypeDef *dma = GetDeviceRoot();
		return (dma->ISR & kHtif) != 0;
	}
	/// Clears the half transfer interrupt flag
	ALWAYS_INLINE static void ClearHalfTransferFlag()
	{
		volatile DMA_TypeDef *dma = GetDeviceRoot();
		dma->IFCR |= kHtif;
	}

	/// Enables the transfer complete interrupt
	ALWAYS_INLINE static void EnableTransferCompleteInt()
	{
		volatile DMA_Channel_TypeDef *dma = GetDevice();
		dma->CCR |= DMA_CCR_TCIE;
	}
	/// Disables the transfer complete interrupt
	ALWAYS_INLINE static void DisableTransferCompleteInt()
	{
		volatile DMA_Channel_TypeDef *dma = GetDevice();
		dma->CCR &= ~DMA_CCR_TCIE;
	}
	/// Checks if the transfer complete interrupt flag was signaled
	ALWAYS_INLINE static bool IsTransferComplete()
	{
		volatile DMA_TypeDef *dma = GetDeviceRoot();
		return (dma->ISR & kTcif) != 0;
	}
	/// Clears the transfer complete interrupt flag
	ALWAYS_INLINE static void ClearTransferCompleteFlag()
	{
		volatile DMA_TypeDef *dma = GetDeviceRoot();
		dma->IFCR |= kTcif;
	}

	/// Disables all interrupts
	ALWAYS_INLINE static void DisableAllInterrupts()
	{
		volatile DMA_Channel_TypeDef *dma = GetDevice();
		dma->CCR &= ~(DMA_CCR_TEIE | DMA_CCR_HTIE | DMA_CCR_TCIE);
	}

	/// Checks if global interrupt flag is signaled
	ALWAYS_INLINE static bool IsGlobalInterrupt()
	{
		volatile DMA_TypeDef *dma = GetDeviceRoot();
		return (dma->ISR & kGif) != 0;
	}
	/// Clears the global interrupt flag
	ALWAYS_INLINE static void ClearGlobalInterruptFlag()
	{
		volatile DMA_TypeDef *dma = GetDeviceRoot();
		dma->IFCR |= kGif;
	}
	/// Clears all interrupt flags for that channel
	ALWAYS_INLINE static void ClearAllFlags()
	{
		volatile DMA_TypeDef *dma = GetDeviceRoot();
		dma->IFCR |= kTeif | kHtif | kTcif | kGif;
	}

	/// Waits until the transfer is complete
	ALWAYS_INLINE static void WaitTransferComplete()
	{
		while (!IsTransferComplete())
		{
		}
		ClearAllFlags();
	}
};


}	// namespace Dma
}	// namespace Bmt

