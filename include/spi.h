#pragma once

#include "dma.h"
#include "irq.h"
#include "shared/RccEnabler.h"	// required for `Clocks::RccTrait`
#include "shared/BitBand.h"		// for EnableFast()

namespace Bmt
{
namespace Spi
{

/// Instance of the SPI peripheral
enum class Iface
{
	k1 = 0			///< SPI1 peripheral
#ifdef SPI2_BASE
	, k2			///< SPI2 peripheral
#endif
#ifdef SPI3_BASE
	, k3			///< SPI3 peripheral
#endif
};


/// Trait carrier for one SPI peripheral — list this in `PeripheralEnabler`
/// (spares you the SpiTemplate<...> template-argument cascade).
template <Iface kSpi>
struct Hardware
{
	using RccTrait_ = Clocks::RccTrait<
		Clocks::RccBit<(kSpi == Iface::k1) ? Clocks::RccReg::kApb2En : Clocks::RccReg::kApb1En,
			(kSpi == Iface::k1) ? RCC_APB2ENR_SPI1EN
#if defined(RCC_APB1ENR_SPI2EN)
			: (kSpi == Iface::k2) ? RCC_APB1ENR_SPI2EN
#elif defined(RCC_APB1ENR1_SPI2EN)
			: (kSpi == Iface::k2) ? RCC_APB1ENR1_SPI2EN
#endif
#if defined(RCC_APB1ENR_SPI3EN)
			: (kSpi == Iface::k3) ? RCC_APB1ENR_SPI3EN
#elif defined(RCC_APB1ENR1_SPI3EN)
			: (kSpi == Iface::k3) ? RCC_APB1ENR1_SPI3EN
#endif
			: 0>,
		Clocks::RccBit<(kSpi == Iface::k1) ? Clocks::RccReg::kApb2Rst : Clocks::RccReg::kApb1Rst,
			(kSpi == Iface::k1) ? RCC_APB2ENR_SPI1EN
#if defined(RCC_APB1ENR_SPI2EN)
			: (kSpi == Iface::k2) ? RCC_APB1ENR_SPI2EN
#elif defined(RCC_APB1ENR1_SPI2EN)
			: (kSpi == Iface::k2) ? RCC_APB1ENR1_SPI2EN
#endif
#if defined(RCC_APB1ENR_SPI3EN)
			: (kSpi == Iface::k3) ? RCC_APB1ENR_SPI3EN
#elif defined(RCC_APB1ENR1_SPI3EN)
			: (kSpi == Iface::k3) ? RCC_APB1ENR1_SPI3EN
#endif
			: 0>
	>;
};


/// SPI polarity/phase of signals
enum class ClkPol
{
	kMode0			///< CPOL: 0, CPHA: 0
	, kMode1		///< CPOL: 0, CPHA: 1
	, kMode2		///< CPOL: 1, CPHA: 0
	, kMode3		///< CPOL: 1, CPHA: 1
};


/// SPI operation mode
enum class Role
{
	kMaster			///< Master mode
	, kMultiMaster	///< MultiMaster mode
	, kSlaveSW		///< Slave, flow controlled by software
	, kSlaveHW		///< Slave, flow controlled by hardware NSS pin
};


/// SPI bidirectional configuration
enum class BiDi
{
	kFullDuplex			///< Normal mode (clk + 2 data lines)
	, kReceiveOnly		///< 2 lines; output disable
	, kHalfDuplexOut	///< Half duplex mode (clk and out lines)
	, kHalfDuplexIn		///< Half duplex mode (clk and in lines)
};


/// Format of the SPI frame
enum class Bits
{
	k4=3,				///< 4-bit data frame MSB first
	k5,					///< 5-bit data frame MSB first
	k6,					///< 6-bit data frame MSB first
	k7,					///< 7-bit data frame MSB first
	k8,					///< 8-bit data frame MSB first
	k9,					///< 9-bit data frame MSB first
	k10,				///< 10-bit data frame MSB first
	k11,				///< 11-bit data frame MSB first
	k12,				///< 12-bit data frame MSB first
	k13,				///< 13-bit data frame MSB first
	k14,				///< 14-bit data frame MSB first
	k15,				///< 15-bit data frame MSB first
	k16,				///< 16-bit data frame MSB first
};

enum class Props
{
	kDefault,
	kUseIrq		= 0b00000001,	///! Configure IRQ function
	kLsbFirst	= 0b00000010,	///! Sends lsb first
	kTiMode		= 0b00000100,	///! Frame format: TI mode
};

constexpr Props operator|(const Props l, const Props r)
{
	return Props((uint32_t)l | (uint32_t)r);
}
constexpr Props operator&(const Props l, const Props r)
{
	return Props((uint32_t)l & (uint32_t)r);
}


enum class RawSpiSpeed : uint32_t;


/// Maps an SPI instance to its DMA channel pair; specialised per-peripheral using the platform IdSpiXRx/Tx aliases
template<Iface kSpi>
struct DmaSpiInfo
{
	using Rx = Dma::IdNone;
	using Tx = Dma::IdNone;
};
#ifdef SPI1_BASE
template<> struct DmaSpiInfo<Iface::k1>
{
	using Rx = Dma::IdSpi1Rx;
	using Tx = Dma::IdSpi1Tx;
};
#endif
#ifdef SPI2_BASE
template<> struct DmaSpiInfo<Iface::k2>
{
	using Rx = Dma::IdSpi2Rx;
	using Tx = Dma::IdSpi2Tx;
};
#endif
#ifdef SPI3_BASE
template<> struct DmaSpiInfo<Iface::k3>
{
	using Rx = Dma::IdSpi3Rx;
	using Tx = Dma::IdSpi3Tx;
};
#endif


/// A template class for an SPI peripheral configuration
template<
	const Iface kSpi						///< The SPI instance
	, typename kClock						///< Clock data type driving the system
	, const int kSpeed = 1000000			///< The desired speed (effective speed is the truncated value)
	, const Role kRole = Role::kMaster		///< Mode of operation
	, const ClkPol kPol = ClkPol::kMode3	///< Polarity and phase
	, const Bits kBits = Bits::k8			///< Frame format
	, const Props kProps = Props::kDefault	///< Configure peripheral for polling
	, const BiDi kDuplex = BiDi::kFullDuplex ///< SPI lines direction
>
struct SpiTemplate
{
	/// The interface
	static constexpr Iface kSpi_ = kSpi;
	/// The peripheral base address as a constant
	static constexpr uintptr_t kSpiBase_ =
		(kSpi == Iface::k1) ? SPI1_BASE
#ifdef SPI2_BASE
		: (kSpi == Iface::k2) ? SPI2_BASE
#endif
#ifdef SPI3_BASE
		: (kSpi == Iface::k3) ? SPI3_BASE
#endif
		: 0 ;
	/// This constant refers to the ABP that owns the peripheral
	static constexpr uint32_t kInputClock_ =
		(kSpi == Iface::k1) ? kClock::kApb2Clock_
		: kClock::kApb1Clock_;
	/// The constant representing the effective speed of the peripheral
	static constexpr uint32_t kFrequency_ =
		(kSpeed >= kInputClock_ / 2) ? kInputClock_ / 2
		: (kSpeed >= kInputClock_ / 4) ? kInputClock_ / 4
		: (kSpeed >= kInputClock_ / 8) ? kInputClock_ / 8
		: (kSpeed >= kInputClock_ / 16) ? kInputClock_ / 16
		: (kSpeed >= kInputClock_ / 32) ? kInputClock_ / 32
		: (kSpeed >= kInputClock_ / 64) ? kInputClock_ / 64
		: (kSpeed >= kInputClock_ / 128) ? kInputClock_ / 128
		: kInputClock_ / 256;
	/// The constant to be applied to the CR1 register
	static constexpr uint32_t kCr1Speed_ =
		(kSpeed >= kInputClock_ / 2) ? 0
		: (kSpeed >= kInputClock_ / 4) ? 1
		: (kSpeed >= kInputClock_ / 8) ? 2
		: (kSpeed >= kInputClock_ / 16) ? 3
		: (kSpeed >= kInputClock_ / 32) ? 4
		: (kSpeed >= kInputClock_ / 64) ? 5
		: (kSpeed >= kInputClock_ / 128) ? 6
		: 7;
	/// The constant with the IRQ type for this particular peripheral
	static constexpr IRQn_Type kNvicSpiIrqn_ =
		(kSpi == Iface::k1) ? SPI1_IRQn :
#ifdef SPI2_BASE
		(kSpi == Iface::k2) ? SPI2_IRQn :
#endif
#ifdef SPI3_BASE
		(kSpi == Iface::k3) ? SPI3_IRQn :
#endif
		SPI1_IRQn
		;
	/// A data-type to control IRQ settings
	using SpiIrq = IrqTemplate<kNvicSpiIrqn_>;
	/// RCC enable + reset trait. SPI1 lives on APB2; SPI2/SPI3 on APB1.
	/// Enable and reset bit positions match on F1 — `kSpi*EN` doubles as the mask.
	using RccTrait_ = Clocks::RccTrait<
		Clocks::RccBit<(kSpi == Iface::k1) ? Clocks::RccReg::kApb2En : Clocks::RccReg::kApb1En,
			(kSpi == Iface::k1) ? RCC_APB2ENR_SPI1EN
#if defined(RCC_APB1ENR_SPI2EN)
			: (kSpi == Iface::k2) ? RCC_APB1ENR_SPI2EN
#elif defined(RCC_APB1ENR1_SPI2EN)
			: (kSpi == Iface::k2) ? RCC_APB1ENR1_SPI2EN
#endif
#if defined(RCC_APB1ENR_SPI3EN)
			: (kSpi == Iface::k3) ? RCC_APB1ENR_SPI3EN
#elif defined(RCC_APB1ENR1_SPI3EN)
			: (kSpi == Iface::k3) ? RCC_APB1ENR1_SPI3EN
#endif
			: 0>,
		Clocks::RccBit<(kSpi == Iface::k1) ? Clocks::RccReg::kApb2Rst : Clocks::RccReg::kApb1Rst,
			(kSpi == Iface::k1) ? RCC_APB2ENR_SPI1EN
#if defined(RCC_APB1ENR_SPI2EN)
			: (kSpi == Iface::k2) ? RCC_APB1ENR_SPI2EN
#elif defined(RCC_APB1ENR1_SPI2EN)
			: (kSpi == Iface::k2) ? RCC_APB1ENR1_SPI2EN
#endif
#if defined(RCC_APB1ENR_SPI3EN)
			: (kSpi == Iface::k3) ? RCC_APB1ENR_SPI3EN
#elif defined(RCC_APB1ENR1_SPI3EN)
			: (kSpi == Iface::k3) ? RCC_APB1ENR1_SPI3EN
#endif
			: 0>
	>;

	/// Data type with DMA information for the TX channel
	using DmaChInfoTx_ = typename DmaSpiInfo<kSpi>::Tx;
	/// Data type with DMA information for the RX channel
	using DmaChInfoRx_ = typename DmaSpiInfo<kSpi>::Rx;
	/// The DMA instance for the peripheral
	static constexpr Dma::Itf DmaInstance_ = DmaChInfoRx_::kItf_;
	/// The DMA channel Transmit instance for the peripheral
	static constexpr Dma::Chan DmaTxCh_ = DmaChInfoTx_::kChan_;
	/// The DMA channel Receive instance for the peripheral
	static constexpr Dma::Chan DmaRxCh_ = DmaChInfoRx_::kChan_;

	/// Returns peripheral register structure
	ALWAYS_INLINE static volatile SPI_TypeDef * GetDevice() { return (volatile SPI_TypeDef *)kSpiBase_; }

	/// DEPRECATED — SPI clock + reset are now done at boot via the platform's
	/// `PeripheralEnabler`. Call `Setup()` directly. NVIC is still managed here
	/// when `Props::kUseIrq` is set.
	[[deprecated("Add this SPI to platform PeripheralEnabler, then call Setup()")]]
	ALWAYS_INLINE static void Init()
	{
		static_assert(kSpiBase_ != 0, "An invalid SPI device was selected");
		Clocks::Enabler<SpiTemplate>::Init();
		if ((kProps & Props::kUseIrq) == Props::kUseIrq)
		{
			SpiIrq::ClearPending();
			SpiIrq::Enable();
		}
		Setup();
	}

	/// Setup the SPI device. Clock-enable is owned by the platform's
	/// `PeripheralEnabler` — make sure this SpiTemplate is listed there.
	ALWAYS_INLINE static void Setup()
	{
		volatile SPI_TypeDef *spi = GetDevice();
		// Clock Polarity, phase, speed
		uint32_t tmp = ((uint32_t(kPol) & 0x1) ? SPI_CR1_CPHA : 0)
			| ((uint32_t(kPol) & 0x2) ? SPI_CR1_CPOL : 0)
			| kCr1Speed_ << SPI_CR1_BR_Pos
			;
		// Frame format
		if ((kProps & Props::kLsbFirst) == Props::kLsbFirst)
			tmp |= SPI_CR1_LSBFIRST;
#ifdef SPI_CR1_DFF
		//! Old SPI hardware supports restricted to 8 or 16 bits
		static_assert(kBits == Bits::k16 || kBits == Bits::k8, "SPI hardware supports only 8 or 16-bit payloads.");
		if (kBits == Bits::k16)
			tmp |= SPI_CR1_DFF;
#endif
		// Master slave
		switch (kRole)
		{
		case Role::kMaster:
			tmp |= SPI_CR1_MSTR | SPI_CR1_SSM | SPI_CR1_SSI;
			break;
		case Role::kMultiMaster:
			tmp |= SPI_CR1_MSTR;
			break;
		case Role::kSlaveSW:
			tmp |= SPI_CR1_SSM | SPI_CR1_SSI;
			break;
		case Role::kSlaveHW:
			break;
		}
		// TODO: Duplex mode (docs are like spaghetti in this topic!!!)
		switch (kDuplex)
		{
		case BiDi::kFullDuplex:
			break;
		case BiDi::kReceiveOnly:
			tmp |= SPI_CR1_RXONLY;
			break;
		case BiDi::kHalfDuplexOut:
			tmp |= SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE;
			break;
		case BiDi::kHalfDuplexIn:
			tmp |= SPI_CR1_BIDIMODE;
			break;
		}
		spi->CR1 = tmp;

		// Register CR2
		tmp = 0;
		switch (kRole)
		{
		case Role::kMaster:
			tmp |= SPI_CR2_SSOE;
			break;
		case Role::kMultiMaster:
			break;
		case Role::kSlaveSW:
			break;
		case Role::kSlaveHW:
			break;
		}
#ifdef SPI_CR2_DS
		tmp |= (uint32_t(kBits) << SPI_CR2_DS_Pos);
#endif
#ifdef SPI_CR2_FRF
		if ((kProps & Props::kTiMode) == Props::kTiMode)
			tmp |= SPI_CR2_FRF;
#else
		static_assert((kProps & Props::kTiMode) == Props::kDefault, "Props::kTiMode is not supported by hardware");
#endif
		spi->CR2 = tmp;

		/*
		** Use the following software sequence to clear the MODF bit:
		** 1. Make a read or write access to the SPI_SR register while the MODF bit is set.
		** 2. Then write to the SPI_CR1 register.
		*/
		if (spi->SR & SPI_SR_MODF)
			spi->CR1 = spi->CR1;
		// Enable device
		spi->CR1 |= SPI_CR1_SPE;
	}

	//! Efficiently changes the speed
	ALWAYS_INLINE static RawSpiSpeed SetupSpeed()
	{
		volatile SPI_TypeDef* spi = GetDevice();
		// Clock Polarity, phase, speed
		uint32_t tmp = ((uint32_t(kPol) & 0x1) ? SPI_CR1_CPHA : 0)
			| ((uint32_t(kPol) & 0x2) ? SPI_CR1_CPOL : 0)
			| kCr1Speed_ << SPI_CR1_BR_Pos
			;
		// Frame format
		if ((kProps & Props::kLsbFirst) == Props::kLsbFirst)
			tmp |= SPI_CR1_LSBFIRST;
#ifdef SPI_CR1_DFF
		if (kBits == Bits::k16)
			tmp |= SPI_CR1_DFF;
#endif
		// Master slave
		switch (kRole)
		{
		case Role::kMaster:
			tmp |= SPI_CR1_MSTR | SPI_CR1_SSM | SPI_CR1_SSI;
			break;
		case Role::kMultiMaster:
			tmp |= SPI_CR1_MSTR;
			break;
		case Role::kSlaveSW:
			tmp |= SPI_CR1_SSM | SPI_CR1_SSI;
			break;
		case Role::kSlaveHW:
			break;
		}
		// TODO: Duplex mode (docs are like spaghetti in this topic!!!)
		switch (kDuplex)
		{
		case BiDi::kFullDuplex:
			break;
		case BiDi::kReceiveOnly:
			tmp |= SPI_CR1_RXONLY;
			break;
		case BiDi::kHalfDuplexOut:
			tmp |= SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE;
			break;
		case BiDi::kHalfDuplexIn:
			tmp |= SPI_CR1_BIDIMODE;
			break;
		}
		uint32_t old = spi->CR1;
		spi->CR1 = tmp;
		return (RawSpiSpeed)old;
	}

	ALWAYS_INLINE static void RestoreSpeed(RawSpiSpeed raw)
	{
		GetDevice()->CR1 = (uint32_t)raw;
	}

	/// Enables the SPI device
	ALWAYS_INLINE static void Enable()
	{
		volatile SPI_TypeDef*spi = GetDevice();
		spi->CR1 |= SPI_CR1_SPE;
	}

	/// Bit-band variant of Enable(): single-cycle store, no read-modify-write.
	/// Use when deterministic timing matters (e.g. phase-locked startup with TIM1).
	/// Available on Cortex-M3/M4 only — the static_assert in BitBand::Ref<> will
	/// fail at compile time on cores without a peripheral bit-band region.
	ALWAYS_INLINE static void EnableFast()
	{
		BitBand::Ref<kSpiBase_ + offsetof(SPI_TypeDef, CR1), SPI_CR1_SPE_Pos>::Set();
	}

	/// Disables the SPI device
	static void Disable()
	{
		volatile SPI_TypeDef*spi = GetDevice();
		while ((spi->SR & SPI_SR_BSY) != 0)
			;
		spi->CR1 &= ~SPI_CR1_SPE;
	}

	/// Disables the SPI device, removing pending bytes
	static void DisableSafe() NO_INLINE
	{
		volatile SPI_TypeDef*spi = GetDevice();
		if (kBits <= Bits::k8)
			ReadChar();
		else
			ReadWord();
		while ((spi->SR & SPI_SR_TXE) == 0)
			;
		while ((spi->SR & SPI_SR_BSY) != 0)
			;
		spi->CR1 &= ~SPI_CR1_SPE;
	}

	/// Stops the device, turning clock off
	ALWAYS_INLINE static void Stop()
	{
		Disable();
		Clocks::Enabler<SpiTemplate>::Disable();
	}

	/// Activates all IRQs for device
	ALWAYS_INLINE static void EnableIrq()
	{
		volatile SPI_TypeDef*spi = GetDevice();
		spi->CR2 |= SPI_CR2_RXNEIE | SPI_CR2_TXEIE | SPI_CR2_ERRIE;
	}

	/// Activates RXNE IRQ for device
	ALWAYS_INLINE static void EnableRxIrq()
	{
		volatile SPI_TypeDef*spi = GetDevice();
		spi->CR2 |= SPI_CR2_RXNEIE;
	}

	/// Activates RXNE+ERR IRQs for device
	ALWAYS_INLINE static void EnableRxErrIrq()
	{
		volatile SPI_TypeDef*spi = GetDevice();
		spi->CR2 |= SPI_CR2_RXNEIE | SPI_CR2_ERRIE;
	}

	/// Disables all IRQs from device
	ALWAYS_INLINE static void DisableIrq()
	{
		volatile SPI_TypeDef*spi = GetDevice();
		spi->CR2 &= ~(SPI_CR2_RXNEIE | SPI_CR2_TXEIE | SPI_CR2_ERRIE);
	}

	/// Enables both receive and transmit DMA
	ALWAYS_INLINE static void EnableDma()
	{
		volatile SPI_TypeDef*spi = GetDevice();
		spi->CR2 |= SPI_CR2_RXDMAEN | SPI_CR2_TXDMAEN;
	}

	/// Enables RX DMA
	ALWAYS_INLINE static void EnableRxDma()
	{
		volatile SPI_TypeDef*spi = GetDevice();
		spi->CR2 |= SPI_CR2_RXDMAEN;
	}

	/// Enables TX DMA
	ALWAYS_INLINE static void EnableTxDma()
	{
		volatile SPI_TypeDef*spi = GetDevice();
		spi->CR2 |= SPI_CR2_TXDMAEN;
	}

	/// Disables all DMA
	ALWAYS_INLINE static void DisableDma()
	{
		volatile SPI_TypeDef*spi = GetDevice();
		spi->CR2 &= ~(SPI_CR2_RXDMAEN | SPI_CR2_TXDMAEN);
	}

	/// Checks if busy bit is active
	ALWAYS_INLINE static bool IsBusy()
	{
		volatile SPI_TypeDef*spi = GetDevice();
		return spi->SR & SPI_SR_BSY;
	}

	/// Writes a byte to the device
	ALWAYS_INLINE static void WriteChar(uint8_t ch)
	{
		volatile SPI_TypeDef*spi = GetDevice();
		while (!(spi->SR & SPI_SR_TXE))
			;
		spi->DR = ch;
	}

	/// Writes a half-word to the device
	ALWAYS_INLINE static void WriteWord(uint16_t w)
	{
		volatile SPI_TypeDef*spi = GetDevice();
		while (!(spi->SR & SPI_SR_TXE))
			;
		spi->DR = w;
	}

	/// Reads a byte from the device
	ALWAYS_INLINE static uint8_t ReadChar()
	{
		volatile SPI_TypeDef*spi = GetDevice();
		while (!(spi->SR & SPI_SR_RXNE))
			;
		return spi->DR;
	}

	/// Reads a byte from the device
	ALWAYS_INLINE static void DummyRead()
	{
		(void)GetDevice()->DR;
	}

	/// Writes a half-word from the device
	ALWAYS_INLINE static uint16_t ReadWord()
	{
		volatile SPI_TypeDef*spi = GetDevice();
		while (!(spi->SR & SPI_SR_RXNE))
			;
		return spi->DR;
	}

	/// Reads status register
	ALWAYS_INLINE static uint8_t ReadStatus()
	{
		volatile SPI_TypeDef*spi = GetDevice();
		return spi->SR;
	}

	/// Sends and receives a byte on the SPI bus
	static uint8_t PutChar(uint8_t ch) NO_INLINE
	{
		WriteChar(ch);
		return ReadChar();
	}

	/// Sends and receive a half-word on the SPI bus
	static uint16_t PutWord(uint16_t w) NO_INLINE
	{
		WriteWord(w);
		return ReadWord();
	}

	/// Sends and receive a data stream on the SPI bus
	static void PutStream(const void* src_, uint32_t cnt) NO_INLINE OPTIMIZED
	{
		const uint8_t* src = (const uint8_t*)src_;
		volatile SPI_TypeDef* spi = GetDevice();
		while (cnt)
		{
			if (cnt != 0 && (spi->SR & SPI_SR_TXE))
			{
				spi->DR = *src++;
				--cnt;
			}
			if (spi->SR & SPI_SR_RXNE)
			{
				(void)spi->DR;
			}
		}
	}

	/// Sends and receive a data stream on the SPI bus
	static void PutStream(const void *src_, void *dest_, uint32_t cnt) NO_INLINE OPTIMIZED
	{
		const uint8_t *src = (const uint8_t *)src_;
		uint8_t *dest = (uint8_t *)dest_;
		volatile SPI_TypeDef*spi = GetDevice();
		uint32_t cnt2 = cnt;
		while (cnt2)
		{
			if (cnt != 0 && (spi->SR & SPI_SR_TXE))
			{
				spi->DR = *src++;
				--cnt;
			}
			if (spi->SR & SPI_SR_RXNE)
			{
				*dest++ = spi->DR;
				--cnt2;
			}
		}
	}

	//! Writes a constant byte repeatedly. Input data is ignored
	static void Repeat(uint8_t byte, uint32_t cnt) NO_INLINE OPTIMIZED
	{
		volatile SPI_TypeDef*spi = GetDevice();
		uint32_t cnt2 = cnt;
		while (cnt2)
		{
			if (cnt != 0 && (spi->SR & SPI_SR_TXE))
			{
				spi->DR = byte;
				--cnt;
			}
			if (spi->SR & SPI_SR_RXNE)
			{
				uint8_t unused = spi->DR;
				(void)unused;
				--cnt2;
			}
		}
	}
};


}	// namespace Spi
}	// namespace Bmt
