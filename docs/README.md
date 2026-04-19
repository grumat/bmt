# Bare Metal Templates (BMT) Documentation

## Overview

Bare Metal Templates (BMT) is a C++17 template library for STM32 microcontroller development that leverages `constexpr` and template metaprogramming to generate optimal bare-metal code at compile time.

## Key Features

- **Zero-overhead abstractions**: All configurations resolved at compile time
- **Hardware-aware templates**: Family-specific optimizations for STM32F1xx, L4xx, G4xx
- **Modern C++17**: Extensive use of `constexpr`, templates, and type safety
- **Interrupt-safe**: Built-in critical section management
- **Resource efficient**: Minimal runtime overhead, small code footprint

## Documentation Structure

### Core Concepts
- **[CONCEPTS.md](CONCEPTS.md)** - Library philosophy, template data models, and `constexpr` advantages
- **[INSTALL.md](INSTALL.md)** - Installation and toolchain setup

### Peripheral Documentation
- **[clocks.md](clocks.md)** - Clock tree configuration (HSE, PLL, system clocks)
- **[gpio.md](gpio.md)** - GPIO pin configuration and management
- **[usart.md](usart.md)** - UART/USART serial communication
- **[timers.md](timers.md)** - Timer peripherals and PWM generation
- **[dma.md](dma.md)** - Direct Memory Access controllers

## Quick Start Example

### Basic Project Setup

```cpp
#include "mcu-system.h"
#include "clocks.h"
#include "gpio.h"

using namespace Bmt;

// Clock configuration
constexpr uint32_t kCrystal = 8000000UL;
constexpr uint32_t kSysClk = 72000000UL;

using HSE = Clocks::AnyHse<kCrystal>;
using PLL = Clocks::AnyPll<HSE, kSysClk, Clocks::Range1>;
using SysClk = Clocks::AnySysClk<PLL>;

// GPIO configuration
using Led = Gpio::AnyOut<Gpio::Port::PC, 13>;

// System initialization
extern "C" void SystemInit()
{
    System::Init();
    SysClk::Init();
    Led::Init();
}

int main()
{
    while (true) {
        Led::Toggle();
        System::Delay(500); // 500ms delay
    }
}
```

## Design Philosophy

### Template Data Models
BMT uses C++ templates to create hardware configuration as type definitions rather than runtime structures. This enables:

- **Compile-time validation**: Configuration errors caught during compilation
- **Zero runtime cost**: All calculations performed at compile time
- **Type safety**: Hardware constraints enforced by the type system

### Example: Clock Dependency Chain

```cpp
using HSE = Clocks::AnyHse<8000000UL>;           // 8 MHz crystal
using PLL = Clocks::AnyPll<HSE, 72000000UL>;     // 72 MHz PLL
using SysClk = Clocks::AnySysClk<PLL>;           // System clock

// Single call configures entire clock tree
SysClk::Init();
```

## Real-World Usage

The BMT library powers the **glossy-msp430** project - an open-source MSP430 JTAG debugger firmware. Key implementations include:

- **Clock configuration** for STM32F103, L432, G431 targets
- **GPIO management** for JTAG, UART, and control signals
- **USART drivers** for GDB-RSP communication
- **Timer/DMA** for high-speed JTAG operations

## Family Support

| Family | Features | Status |
|--------|----------|--------|
| **STM32F1xx** | Basic peripherals, 72 MHz max | ✅ Production |
| **STM32L4xx** | Low-power features, USB clock | ✅ Production |
| **STM32G4xx** | Advanced peripherals, 170 MHz | ✅ Production |

## Getting Help

### Common Issues

1. **Compilation errors**: Ensure C++17 mode is enabled (`-std=c++17`)
2. **Linker errors**: Check BSP paths in CMake configuration
3. **Runtime issues**: Verify clock configuration matches hardware

### Debugging Tips

```cpp
// Enable debug output
#include "debug.h"

// Check configuration at runtime
Debug::Print("System clock: %lu Hz\n", System::GetSystemClock());
Debug::Print("GPIO state: %s\n", Led::IsHigh() ? "HIGH" : "LOW");
```

## Contributing

See the main repository for contribution guidelines. The documentation in this folder is generated from:

- Source code comments in `bmt/include/`
- Example implementations in `Firmware.shared/`
- Target configurations in `target.*/platform.h`

## License

BMT is open-source software. Refer to the main repository for licensing information.