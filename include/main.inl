/*
Include this file in your projects main.cpp to implement base elements for the library
*/


// The 'interrupt' attribute does NOT save/restore the VFP registers, so on
// hard-float targets (Cortex-M4F — g4/l4) GCC warns "FP registers might be
// clobbered despite 'interrupt' attribute". general-regs-only forbids FP in these
// handlers: a compile-time GUARANTEE they touch no FPU state (not mere warning
// suppression), so there is nothing to clobber. It propagates from the
// declaration to the definition, and keeps the FPU available for all non-ISR
// code (a global -mgeneral-regs-only would break <cmath>'s FP declarations).
// NOTE: the function `target()` attribute is ignored for this on 32-bit ARM — only
// the pragma drives the ISR check. Harmless no-op on Cortex-M3 (f1, no FPU).
#pragma GCC push_options
#pragma GCC target("general-regs-only")

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

#pragma GCC pop_options



