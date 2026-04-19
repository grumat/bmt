/*
Include this file in your projects main.cpp to implement base elements for the library
*/


extern "C" void USART1_IRQHandler() IRQ OPTIMIZED;
extern "C" void USART1_IRQHandler()
{
	if (Bmt::UsartIntHandler<Bmt::Usart::k1>::func)
		Bmt::UsartIntHandler<Bmt::Usart::k1>::func(Bmt::UsartIntHandler<Bmt::Usart::k1>::cookie);
	else
		__BKPT();
}

extern "C" void USART2_IRQHandler() IRQ OPTIMIZED;
extern "C" void USART2_IRQHandler()
{
	if (Bmt::UsartIntHandler<Bmt::Usart::k2>::func)
		Bmt::UsartIntHandler<Bmt::Usart::k2>::func(Bmt::UsartIntHandler<Bmt::Usart::k2>::cookie);
	else
		__BKPT();
}

extern "C" void USART3_IRQHandler() IRQ OPTIMIZED;
extern "C" void USART3_IRQHandler()
{
	if (Bmt::UsartIntHandler<Bmt::Usart::k3>::func)
		Bmt::UsartIntHandler<Bmt::Usart::k3>::func(Bmt::UsartIntHandler<Bmt::Usart::k3>::cookie);
	else
		__BKPT();
}

#ifdef USART4_BASE
extern "C" void USART4_IRQHandler() IRQ;
extern "C" void USART4_IRQHandler()
{
	if (Bmt::UsartIntHandler<Bmt::Usart::k4>::func)
		Bmt::UsartIntHandler<Bmt::Usart::k4>::func(Bmt::UsartIntHandler<Bmt::Usart::k4>::cookie);
	else
		__BKPT();
}

extern "C" void USART5_IRQHandler() IRQ;
extern "C" void USART5_IRQHandler()
{
	if (Bmt::UsartIntHandler<Bmt::Usart::k5>::func)
		Bmt::UsartIntHandler<Bmt::Usart::k5>::func(Bmt::UsartIntHandler<Bmt::Usart::k5>::cookie);
	else
		__BKPT();
}
#endif



