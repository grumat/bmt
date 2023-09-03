#pragma once

namespace Bmt
{
namespace Dma
{


template<
	typename kDmaID						///< The DMA::AnyID<> resource identification
> class AnyMux
{
public:
	// A DMA::AnyID<> definition that identifies the DMA
	typedef kDmaID DmaID_;
	/// A constant with the DMA controller instance number
	static constexpr Itf kDma_ = kDmaID::kItf_;
	/// A constant with the DMA channel number
	static constexpr Chan kChan_ = kDmaID::kChan_;
	/// A constant with the DMA channel number
	static constexpr PerifSel kChSel_ = kDmaID::kChSel_;
	/// The address base of the DMA peripheral
	static constexpr uint32_t kMuxBase_ =
		(kDma_ == Itf::k1) ? DMAMUX1_Channel0_BASE + 4*uint32_t(kChan_)
#ifdef DMA2_BASE
		: (kDma_ == Itf::k2) ? DMAMUX1_Channel8_BASE + 4*uint32_t(kChan_)
#endif
		: 0;

	/// Returns root device structure
	ALWAYS_INLINE static DMAMUX_Channel_TypeDef *GetDevice() { return (DMAMUX_Channel_TypeDef *)kMuxBase_; }

	ALWAYS_INLINE static constexpr void Init()
	{
#ifdef RCC_AHB1ENR_DMAMUX1EN
		RCC->AHB1ENR |= RCC_AHB1ENR_DMAMUX1EN;
#endif
	}

	ALWAYS_INLINE static constexpr void Setup()
	{
		DMAMUX_Channel_TypeDef *mux = GetDevice();
		mux->CCR = (mux->CCR & DMAMUX_CxCR_DMAREQ_ID_Msk) 
			| ((uint32_t)kChSel_ << DMAMUX_CxCR_DMAREQ_ID_Pos)
			;
	}
};



}	// namespace Dma
}	// namespace Bmt

