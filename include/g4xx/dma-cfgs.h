#pragma once

namespace Bmt
{
namespace Dma
{

#if 0

/// A template class to configure ADC with DMA transfer
template<
	const bool kCircular = true
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyAdc1 : public AnyChannel <
	Itf::k1,
	Chan::k1,
#if OPT_DMA_VERSION > 1
	PerifSel::k0,
#endif
	kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem,
	PtrPolicy::kShortPtr,
	kDstPtr,
	kPrio
>
{ };


/// A template class for SPI1 RX transfers of bytes using DMA
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnySpi1Rx : public AnyChannel <
	Itf::k1,
	Chan::k2,
#if OPT_DMA_VERSION > 1
	PerifSel::k1,
#endif
	kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem,
	kSrcPtr,
	kDstPtr,
	kPrio
>
{ };


/// A template class for SPI1 TX transfers of bytes using DMA
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtr
	, const Prio kPrio = Prio::kMedium
>
class AnySpi1Tx : public AnyChannel <
	Itf::k1,
	Chan::k3,
#if OPT_DMA_VERSION > 1
	PerifSel::k1,
#endif
	kCircular ? Dir::kMemToPerCircular : Dir::kMemToPer,
	kSrcPtr,
	kDstPtr,
	kPrio
>
{ };


#ifdef SPI2_BASE
/// A template class for SPI2 RX transfers of bytes using DMA
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnySpi2Rx : public AnyChannel <
	Itf::k1,
	Chan::k4,
#if OPT_DMA_VERSION > 1
	PerifSel::k1,
#endif
	kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem,
	kSrcPtr,
	kDstPtr,
	kPrio
>
{ };


/// A template class for SPI2 TX transfers of bytes using DMA
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtr
	, const Prio kPrio = Prio::kMedium
>
class AnySpi2Tx : public AnyChannel <
	Itf::k1,
	Chan::k5,
#if OPT_DMA_VERSION > 1
	PerifSel::k1,
#endif
	kCircular ? Dir::kMemToPerCircular : Dir::kMemToPer,
	kSrcPtr,
	kDstPtr,
	kPrio
>
{ };
#endif


#ifdef SPI3_BASE
/// A template class for SPI2 RX transfers of bytes using DMA
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnySpi3Rx : public AnyChannel <
	Itf::k2,
	Chan::k1,
#if OPT_DMA_VERSION > 1
	PerifSel::k3,
#endif
	kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem,
	kSrcPtr,
	kDstPtr,
	kPrio
>
{ };


/// A template class for SPI2 TX transfers of bytes using DMA
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtr
	, const Prio kPrio = Prio::kMedium
>
class AnySpi3Tx : public AnyChannel <
	Itf::k2,
	Chan::k2,
#if OPT_DMA_VERSION > 1
	PerifSel::k3,
#endif
	kCircular ? Dir::kMemToPerCircular : Dir::kMemToPer,
	kSrcPtr,
	kDstPtr,
	kPrio
>
{ };
#endif


/// A template class for a DMA operation triggered by Timer 1 TRG event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim1Trig : public AnyChannel<
	Itf::k1, 
	Chan::k4, 
#if OPT_DMA_VERSION > 1
	PerifSel::k7,
#endif
	kDir,
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };


/// A template class for a DMA operation triggered by Timer 1 COM (Commutation) event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim1Com : public AnyChannel<
	Itf::k1, 
	Chan::k4, 
#if OPT_DMA_VERSION > 1
	PerifSel::k7,
#endif
	kDir,
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };


/// A template class for a DMA operation triggered by Timer 1 UP event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim1Up : public AnyChannel<
	Itf::k1, 
#if OPT_DMA_VERSION == 1
	Chan::k5,
#else
	Chan::k6,
	PerifSel::k7,
#endif
	kDir,
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };


/// A template class for a DMA operation triggered by Timer 1 CH1 event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim1Ch1 : public AnyChannel<
	Itf::k1, 
	Chan::k2, 
#if OPT_DMA_VERSION > 1
	PerifSel::k7,
#endif
	kDir,
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };


/// A template class for a DMA operation triggered by Timer 1 CH2 event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim1Ch2 : public AnyChannel<
	Itf::k1, 
#if OPT_DMA_VERSION == 1
	Chan::k4,
#else
	Chan::k3,
	PerifSel::k7,
#endif
	kDir,
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };


/// A template class for a DMA operation triggered by Timer 1 CH3 event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim1Ch3 : public AnyChannel<
	Itf::k1, 
#if OPT_DMA_VERSION == 1
	Chan::k6,
#else
	Chan::k7,
	PerifSel::k7,
#endif
	kDir, 
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };


/// A template class for a DMA operation triggered by Timer 1 CH4 event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim1Ch4 : public AnyChannel<
	Itf::k1, 
	Chan::k4, 
#if OPT_DMA_VERSION > 1
	PerifSel::k7,
#endif
	kDir,
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };


#ifdef TIM2_BASE
/// A template class for a DMA operation triggered by Timer 2 UP event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim2Up : public AnyChannel<
	Itf::k1, 
	Chan::k2, 
#if OPT_DMA_VERSION > 1
	PerifSel::k4,
#endif
	kDir,
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };


/// A template class for a DMA operation triggered by Timer 2 CH1 event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim2Ch1 : public AnyChannel<
	Itf::k1, 
	Chan::k5, 
#if OPT_DMA_VERSION > 1
	PerifSel::k4,
#endif
	kDir,
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };


/// A template class for a DMA operation triggered by Timer 2 CH2 event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim2Ch2 : public AnyChannel<
	Itf::k1, 
	Chan::k7, 
#if OPT_DMA_VERSION > 1
	PerifSel::k4,
#endif
	kDir,
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };


/// A template class for a DMA operation triggered by Timer 2 CH3 event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim2Ch3 : public AnyChannel<
	Itf::k1, 
	Chan::k1, 
#if OPT_DMA_VERSION > 1
	PerifSel::k4,
#endif
	kDir,
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };


/// A template class for a DMA operation triggered by Timer 2 CH4 event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim2Ch4 : public AnyChannel<
	Itf::k1, 
	Chan::k7, 
#if OPT_DMA_VERSION > 1
	PerifSel::k4,
#endif
	kDir,
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };
#endif	// TIM2_BASE


#ifdef TIM3_BASE
/// A template class for a DMA operation triggered by Timer 3 TRIG event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim3Trig : public AnyChannel<
	Itf::k1, 
	Chan::k6, 
#if OPT_DMA_VERSION > 1
	PerifSel::k5,
#endif
	kDir,
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };

/// A template class for a DMA operation triggered by Timer 3 UP event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim3Up : public AnyChannel<
	Itf::k1, 
	Chan::k3, 
#if OPT_DMA_VERSION > 1
	PerifSel::k5,
#endif
	kDir,
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };


/// A template class for a DMA operation triggered by Timer 3 CH1 event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim3Ch1 : public AnyChannel<
	Itf::k1, 
	Chan::k6, 
#if OPT_DMA_VERSION > 1
	PerifSel::k5,
#endif
	kDir,
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };


/// A template class for a DMA operation triggered by Timer 3 CH3 event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim3Ch3 : public AnyChannel<
	Itf::k1, 
	Chan::k2, 
#if OPT_DMA_VERSION > 1
	PerifSel::k5,
#endif
	kDir,
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };


/// A template class for a DMA operation triggered by Timer 3 CH4 event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim3Ch4 : public AnyChannel<
	Itf::k1, 
	Chan::k3, 
#if OPT_DMA_VERSION > 1
#	error Please fix this
#endif
	kDir,
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };
#endif	// TIM3_BASE


#ifdef TIM4_BASE
/// A template class for a DMA operation triggered by Timer 4 UP event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim4Up : public AnyChannel<
	Itf::k1, 
	Chan::k7, 
#if OPT_DMA_VERSION > 1
#	error Please fix this
#endif
	kDir,
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };


/// A template class for a DMA operation triggered by Timer 4 CH1 event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim4Ch1 : public AnyChannel<
	Itf::k1, 
	Chan::k1, 
#if OPT_DMA_VERSION > 1
#	error Please fix this
#endif
	kDir,
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };


/// A template class for a DMA operation triggered by Timer 4 CH3 event
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim4Ch3 : public AnyChannel<
	Itf::k1, 
	Chan::k5, 
#if OPT_DMA_VERSION > 1
#	error Please fix this
#endif
	kDir,
	kSrcPtr, 
	kDstPtr, 
	kPrio
>
{ };
#endif	// TIM4_BASE


/// A template class for USART1 RX transfers of bytes using DMA
template<
	const bool kCircular = true
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyUsart1Rx : public AnyChannel<
	Itf::k1, 
	Chan::k5, 
#if OPT_DMA_VERSION > 1
	PerifSel::k2,
#endif
	kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem,
	PtrPolicy::kBytePtr,
	kDstPtr, 
	kPrio
>
{ };


/// A template class for USART1 TX transfers of bytes using DMA
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyUsart1Tx : public AnyChannel<
	Itf::k1, 
	Chan::k4, 
#if OPT_DMA_VERSION > 1
	PerifSel::k2,
#endif
	kCircular ? Dir::kMemToPerCircular : Dir::kMemToPer,
	kSrcPtr, 
	PtrPolicy::kBytePtr,
	kPrio
>
{ };


#ifdef USART2_BASE
/// A template class for USART2 RX transfers of bytes using DMA
template<
	const bool kCircular = true
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyUsart2Rx : public AnyChannel<
	Itf::k1, 
	Chan::k6, 
#if OPT_DMA_VERSION > 1
	PerifSel::k2,
#endif
	kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem,
	PtrPolicy::kBytePtr,
	kDstPtr, 
	kPrio
>
{ };


/// A template class for USART2 TX transfers of bytes using DMA
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyUsart2Tx : public AnyChannel<
	Itf::k1, 
	Chan::k7, 
#if OPT_DMA_VERSION > 1
	PerifSel::k2,
#endif
	kCircular ? Dir::kMemToPerCircular : Dir::kMemToPer,
	kSrcPtr, 
	PtrPolicy::kBytePtr,
	kPrio
>
{ };
#endif	// USART2_BASE


#ifdef USART3_BASE
/// A template class for USART3 RX transfers of bytes using DMA
template<
	const bool kCircular = true
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyUsart3Rx : public AnyChannel<
	Itf::k1, 
	Chan::k3, 
#if OPT_DMA_VERSION > 1
	PerifSel::k2,
#endif
	kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem,
	PtrPolicy::kBytePtr,
	kDstPtr, 
	kPrio
>
{ };

/// A template class for USART3 TX transfers of bytes using DMA
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyUsart3Tx : public AnyChannel<
	Itf::k1, 
	Chan::k2, 
#if OPT_DMA_VERSION > 1
	PerifSel::k2,
#endif
	kCircular ? Dir::kMemToPerCircular : Dir::kMemToPer,
	kSrcPtr, 
	PtrPolicy::kBytePtr,
	kPrio
>
{ };
#endif // USART2_BASE

#endif

}	// namespace Dma
}	// namespace Bmt
