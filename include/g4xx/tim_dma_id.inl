// This was added for backward compatibility. G4 features a powerful MUX and this 
// file should be ignored for native projects

// Generic template for the DMA configuration for a given timer
template<
	const Unit kTimerNum
>
struct DmaInfo
{
	// Update Event
	using Update = Dma::IdNone;
	// Trigger event
	using Trigger = Dma::IdNone;
	// Communtation event
	using Commutation = Dma::IdNone;
};

template<
	const Unit kTimerNum
	, const Channel kChannel
>
struct DmaChInfo : Dma::IdNone
{
};

#ifdef TIM1_BASE
// Template specialization for DMA settings of TIM1>
template<> struct DmaInfo<kTim1>
{
	using Update = Dma::IdTim1Up;
	using Trigger = Dma::IdTim1Trig;
	using Commutation = Dma::IdTim1Com;
};

// Template specialization for DMA Channel settings for TIM1_CH1>
template<> struct DmaChInfo<kTim1, Channel::k1> : Dma::IdTim1Ch1
{
};

// Template specialization for DMA Channel settings for TIM1_CH2>
template<> struct DmaChInfo<kTim1, Channel::k2> : Dma::IdTim1Ch2
{
};

// Template specialization for DMA Channel settings for TIM1_CH3>
template<> struct DmaChInfo<kTim1, Channel::k3> : Dma::IdTim1Ch3
{
};

// Template specialization for DMA Channel settings for TIM1_CH4>
template<> struct DmaChInfo<kTim1, Channel::k4> : Dma::IdTim1Ch4
{
};

#endif	// TIM1_BASE

#ifdef TIM2_BASE
// Template specialization for DMA settings of TIM2>
template<> struct DmaInfo<kTim2>
{
	using Update = Dma::IdTim2Up;
	using Trigger = Dma::IdNone;
	using Commutation = Dma::IdNone;
};

// Template specialization for DMA Channel settings for TIM2_CH1>
template<> struct DmaChInfo<kTim2, Channel::k1> : Dma::IdTim2Ch1
{
};

// Template specialization for DMA Channel settings for TIM2_CH2>
template<> struct DmaChInfo<kTim2, Channel::k2> : Dma::IdTim2Ch2
{
};

// Template specialization for DMA Channel settings for TIM2_CH3>
template<> struct DmaChInfo<kTim2, Channel::k3> : Dma::IdTim2Ch3
{
};

// Template specialization for DMA Channel settings for TIM2_CH4>
template<> struct DmaChInfo<kTim2, Channel::k4> : Dma::IdTim2Ch4
{
};

#endif	// TIM2_BASE

#ifdef TIM3_BASE
// Template specialization for DMA settings of TIM3>
template<> struct DmaInfo<kTim3>
{
	using Update = Dma::IdTim3Up;
	using Trigger = Dma::IdTim3Trig;
	using Commutation = Dma::IdNone;
};

// Template specialization for DMA Channel settings for TIM3_CH1>
template<> struct DmaChInfo<kTim3, Channel::k1> : Dma::IdTim3Ch1
{
};

// Template specialization for DMA Channel settings for TIM3_CH2>
template<> struct DmaChInfo<kTim3, Channel::k2> : Dma::IdTim3Ch2
{
};

// Template specialization for DMA Channel settings for TIM3_CH3>
template<> struct DmaChInfo<kTim3, Channel::k3> : Dma::IdTim3Ch3
{
};

// Template specialization for DMA Channel settings for TIM3_CH4>
template<> struct DmaChInfo<kTim3, Channel::k4> : Dma::IdTim3Ch4
{
};

#endif	// TIM3_BASE

#ifdef TIM4_BASE
// Template specialization for DMA settings of TIM4>
template<> struct DmaInfo<kTim4>
{
	using Update = Dma::IdTim4Up;
	using Trigger = Dma::IdNone;
	using Commutation = Dma::IdNone;
};

// Template specialization for DMA Channel settings for TIM4_CH1>
template<> struct DmaChInfo<kTim4, Channel::k1> : Dma::IdTim4Ch1
{
};

// Template specialization for DMA Channel settings for TIM4_CH2>
template<> struct DmaChInfo<kTim4, Channel::k2> : Dma::IdTim4Ch2
{
};

// Template specialization for DMA Channel settings for TIM4_CH3>
template<> struct DmaChInfo<kTim4, Channel::k3> : Dma::IdTim4Ch3
{
};

// Template specialization for DMA Channel settings for TIM4_CH4>
template<> struct DmaChInfo<kTim4, Channel::k4> : Dma::IdTim4Ch4
{
};

#endif	// TIM4_BASE

#ifdef TIM5_BASE
// Template specialization for DMA settings of TIM5>
template<> struct DmaInfo<kTim5>
{
	using Update = Dma::IdTim5Up;
	using Trigger = Dma::IdTim5Trig;
	using Commutation = Dma::IdNone;
};

// Template specialization for DMA Channel settings for TIM5_CH1>
template<> struct DmaChInfo<kTim5, Channel::k1> : Dma::IdTim5Ch1
{
};

// Template specialization for DMA Channel settings for TIM5_CH2>
template<> struct DmaChInfo<kTim5, Channel::k2> : Dma::IdTim5Ch2
{
};

// Template specialization for DMA Channel settings for TIM5_CH3>
template<> struct DmaChInfo<kTim5, Channel::k3> : Dma::IdTim5Ch3
{
};

// Template specialization for DMA Channel settings for TIM5_CH4>
template<> struct DmaChInfo<kTim5, Channel::k4> : Dma::IdTim5Ch4
{
};

#endif	// TIM5_BASE

#ifdef TIM6_BASE
// Template specialization for DMA settings of TIM6>
template<> struct DmaInfo<kTim6>
{
	using Update = Dma::IdTim6Up;
	using Trigger = Dma::IdNone;
	using Commutation = Dma::IdNone;
};

#endif	// TIM6_BASE

#ifdef TIM7_BASE
// Template specialization for DMA settings of TIM7>
template<> struct DmaInfo<kTim7>
{
	using Update = Dma::IdTim7Up;
	using Trigger = Dma::IdNone;
	using Commutation = Dma::IdNone;
};

#endif	// TIM7_BASE

#ifdef TIM8_BASE
// Template specialization for DMA settings of TIM8>
template<> struct DmaInfo<kTim8>
{
	using Update = Dma::IdTim8Up;
	using Trigger = Dma::IdTim8Trig;
	using Commutation = Dma::IdTim8Com;
};

// Template specialization for DMA Channel settings for TIM8_CH1>
template<> struct DmaChInfo<kTim8, Channel::k1> : Dma::IdTim8Ch1
{
};

// Template specialization for DMA Channel settings for TIM8_CH2>
template<> struct DmaChInfo<kTim8, Channel::k2> : Dma::IdTim8Ch2
{
};

// Template specialization for DMA Channel settings for TIM8_CH3>
template<> struct DmaChInfo<kTim8, Channel::k3> : Dma::IdTim8Ch3
{
};

// Template specialization for DMA Channel settings for TIM8_CH4>
template<> struct DmaChInfo<kTim8, Channel::k4> : Dma::IdTim8Ch4
{
};

#endif	// TIM8_BASE

#ifdef TIM15_BASE
// Template specialization for DMA settings of TIM15>
template<> struct DmaInfo<kTim15>
{
	using Update = Dma::IdTim15Up;
	using Trigger = Dma::IdTim15Trig;
	using Commutation = Dma::IdTim15Com;
};

// Template specialization for DMA Channel settings for TIM15_CH1>
template<> struct DmaChInfo<kTim15, Channel::k1> : Dma::IdTim15Ch1
{
};

#endif	// TIM15_BASE

#ifdef TIM16_BASE
// Template specialization for DMA settings of TIM16>
template<> struct DmaInfo<kTim16>
{
	using Update = Dma::IdTim16Up;
	using Trigger = Dma::IdNone;
	using Commutation = Dma::IdNone;
};

// Template specialization for DMA Channel settings for TIM16_CH1>
template<> struct DmaChInfo<kTim16, Channel::k1> : Dma::IdTim16Ch1
{
};

#endif	// TIM16_BASE

#ifdef TIM17_BASE
// Template specialization for DMA settings of TIM17>
template<> struct DmaInfo<kTim17>
{
	using Update = Dma::IdTim17Up;
	using Trigger = Dma::IdNone;
	using Commutation = Dma::IdNone;
};

// Template specialization for DMA Channel settings for TIM17_CH1>
template<> struct DmaChInfo<kTim17, Channel::k1> : Dma::IdTim17Ch1
{
};

#endif	// TIM17_BASE

#ifdef TIM20_BASE
// Template specialization for DMA settings of TIM20>
template<> struct DmaInfo<kTim20>
{
	using Update = Dma::IdTim20Up;
	using Trigger = Dma::IdTim20Trig;
	using Commutation = Dma::IdTim20Com;
};

// Template specialization for DMA Channel settings for TIM20_CH1>
template<> struct DmaChInfo<kTim20, Channel::k1> : Dma::IdTim20Ch1
{
};

// Template specialization for DMA Channel settings for TIM20_CH2>
template<> struct DmaChInfo<kTim20, Channel::k2> : Dma::IdTim20Ch2
{
};

// Template specialization for DMA Channel settings for TIM20_CH3>
template<> struct DmaChInfo<kTim20, Channel::k3> : Dma::IdTim20Ch3
{
};

// Template specialization for DMA Channel settings for TIM20_CH4>
template<> struct DmaChInfo<kTim20, Channel::k4> : Dma::IdTim20Ch4
{
};

#endif	// TIM20_BASE



