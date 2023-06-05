
// Generic template for the DMA configuration for a given timer
template<
	const Unit kTimerNum
>
struct DmaInfo
{
	// Update Event
	typedef Dma::IdNone Update;
	// Trigger event
	typedef Dma::IdNone Trigger;
	// Communtation event
	typedef Dma::IdNone Commutation;
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
	typedef Dma::IdTim1Up Update;
	typedef Dma::IdTim1Trig Trigger;
	typedef Dma::IdTim1Com Commutation;
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
	typedef Dma::IdTim2Up Update;
	typedef Dma::IdNone Trigger;
	typedef Dma::IdNone Commutation;
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
	typedef Dma::IdTim3Up Update;
	typedef Dma::IdTim3Trig Trigger;
	typedef Dma::IdNone Commutation;
};

// Template specialization for DMA Channel settings for TIM3_CH1>
template<> struct DmaChInfo<kTim3, Channel::k1> : Dma::IdTim3Ch1
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
	typedef Dma::IdTim4Up Update;
	typedef Dma::IdNone Trigger;
	typedef Dma::IdNone Commutation;
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

#endif	// TIM4_BASE

#ifdef TIM5_BASE
// Template specialization for DMA settings of TIM5>
template<> struct DmaInfo<kTim5>
{
	typedef Dma::IdTim5Up Update;
	typedef Dma::IdTim5Trig Trigger;
	typedef Dma::IdNone Commutation;
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
	typedef Dma::IdTim6Up Update;
	typedef Dma::IdNone Trigger;
	typedef Dma::IdNone Commutation;
};

#endif	// TIM6_BASE

#ifdef TIM7_BASE
// Template specialization for DMA settings of TIM7>
template<> struct DmaInfo<kTim7>
{
	typedef Dma::IdTim7Up Update;
	typedef Dma::IdNone Trigger;
	typedef Dma::IdNone Commutation;
};

#endif	// TIM7_BASE

#ifdef TIM8_BASE
// Template specialization for DMA settings of TIM8>
template<> struct DmaInfo<kTim8>
{
	typedef Dma::IdTim8Up Update;
	typedef Dma::IdTim8Trig Trigger;
	typedef Dma::IdTim8Com Commutation;
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
	typedef Dma::IdTim15Up Update;
	typedef Dma::IdTim15Trig Trigger;
	typedef Dma::IdTim15Com Commutation;
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
	typedef Dma::IdTim16Up Update;
	typedef Dma::IdNone Trigger;
	typedef Dma::IdNone Commutation;
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
	typedef Dma::IdTim17Up Update;
	typedef Dma::IdNone Trigger;
	typedef Dma::IdNone Commutation;
};

// Template specialization for DMA Channel settings for TIM17_CH1>
template<> struct DmaChInfo<kTim17, Channel::k1> : Dma::IdTim17Ch1
{
};

#endif	// TIM17_BASE



