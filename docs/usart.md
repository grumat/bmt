# <big>`Usart` Template Classes</big>

The **bmt** library provides comprehensive USART (Universal Synchronous/Asynchronous Receiver/Transmitter) support through template classes that enable compile-time configuration of serial communication peripherals. The library supports interrupt-driven operation with FIFO buffers for efficient data handling.

## Overview

USART peripherals in STM32 microcontrollers provide serial communication capabilities. The **bmt** library abstracts hardware complexity through:

- **`UsartTemplate<>`**: Core configuration template
- **`UartFifo<>`**: Double-buffered FIFO for interrupt-driven operation  
- **`UsartIntDriverModel<>`**: Interrupt-driven driver model
- **`UartPolledDriver<>`**: Polling-based driver for simple applications

## Basic Configuration

### Simple Polled UART Example

```cpp
#include "uart.h"

using namespace Bmt;

// Define clock system (assumed to be defined elsewhere)
using SysClk = /* your clock configuration */;

// Configure USART1 at 115200 baud, 8N1
using MyUart = UsartTemplate<
    Usart::k1,      // USART1 peripheral
    SysClk,         // Clock source
    115200,         // Baud rate
    8,              // Word length (bits)
    Parity::kNone,  // No parity
    StopBits::k1    // 1 stop bit
>;

// Polled driver (no interrupts)
using UartDriver = UartPolledDriver<MyUart>;

void InitializeUart()
{
    // Enable USART peripheral clock and configure pins
    MyUart::Init();
    
    // Initialize the driver
    UartDriver::Init();
}

void SendData()
{
    const char* message = "Hello, World!\r\n";
    UartDriver::Write(message, strlen(message));
}

char ReadByte()
{
    return UartDriver::Read();
}
```

## Interrupt-Driven Operation with FIFO Buffers

For efficient data handling, the library provides FIFO-buffered interrupt-driven operation:

```cpp
#include "uart.h"

using namespace Bmt;

// Clock configuration
using SysClk = /* your clock configuration */;

// USART configuration for GDB port (from firmware example)
using UsartGdbSettings = UsartTemplate<
    Usart::k1,      // USART1
    SysClk,         // System clock
    115200,         // 115200 baud
    8,              // 8-bit words
    Parity::kNone,  // No parity
    StopBits::k1    // 1 stop bit
>;

// Dual FIFO buffer: 256 bytes TX, 64 bytes RX
using UsartGdbBuffer = UartFifo<UsartGdbSettings, 256, 64>;

// Interrupt-driven driver model
using UsartGdbDriver = UsartIntDriverModel<UsartGdbBuffer>;

// Singleton instance for the GDB UART
using UsartGdb = UsartIntDriver<UsartGdbDriver>;

void InitializeGdbUart()
{
    // Initialize hardware and interrupts
    UsartGdb::Init();
    
    // Enable global interrupts
    Irq::Enable();
}

void SendToGdb(const char* data, size_t length)
{
    // Write data to TX buffer (handled by interrupts)
    UsartGdb::Write(data, length);
}

size_t ReadFromGdb(char* buffer, size_t maxLength)
{
    // Read available data from RX buffer
    return UsartGdb::Read(buffer, maxLength);
}
```

## Real-World Example from Firmware

The glossy-msp430 firmware uses USART for GDB communication. Here's the actual configuration from `stdproj.h`:

```cpp
// Platform-specific USART selection
#if OPT_GDB_IMPLEMENTATION == OPT_GDB_IMPL_USART1
/// USART1 for GDB port
using UsartGdbSettings = UsartTemplate<Usart::k1, SysClk, 115200>;
#elif OPT_GDB_IMPLEMENTATION == OPT_GDB_IMPL_USART2  
/// USART2 for GDB port
using UsartGdbSettings = UsartTemplate<Usart::k2, SysClk, 115200>;
#elif OPT_GDB_IMPLEMENTATION == OPT_GDB_IMPL_USART3
/// USART3 for GDB port  
using UsartGdbSettings = UsartTemplate<Usart::k3, SysClk, 115200>;
#endif

/// Defines a dual FIFO buffer for GDB UART port
using UsartGdbBuffer = UartFifo<UsartGdbSettings, 256, 64>;

/// The UART driver using interrupts
using UsartGdbDriver = UsartIntDriverModel<UsartGdbBuffer>;

/// Singleton for the GDB UART
using UsartGdb = UsartIntDriver<UsartGdbDriver>;
```

## GPIO Pin Configuration

USART requires proper GPIO configuration. Here's an example from `target.bluepill/platform.h`:

```cpp
using namespace Bmt;

// USART1 pins on PA9 (TX) and PA10 (RX)
using USART1_TX_PA9 = AnyAltOut<Port::PA, 9, AfUsart1TxPa9>;
using USART1_RX_PA10 = AnyAltOut<Port::PA, 10, AfUsart1RxPa10>;

// USART2 pins on PA2 (TX) and PA3 (RX)  
using USART2_TX_PA2 = AnyAltOut<Port::PA, 2, AfUsart2TxPa2>;
using USART2_RX_PA3 = AnyAltOut<Port::PA, 3, AfUsart2RxPa3>;

// Include in port setup
using PORTA = AnyPortSetup <Port::PA
    // ... other pins
    , USART1_TX_PA9     ///< GDB UART port (TX)
    , USART1_RX_PA10    ///< GDB UART port (RX)
    // ... more pins
>;
```

## Advanced Features

### Custom Baud Rate Calculation

The library automatically calculates baud rate divisors based on the clock configuration:

```cpp
using MyUart = UsartTemplate<
    Usart::k1,
    SysClk,         // 80 MHz system clock
    921600,         // High baud rate
    8,
    Parity::kNone,
    StopBits::k1
>;
// Baud rate divisor is calculated at compile-time
```

### Parity and Stop Bit Options

```cpp
// 7-bit words with even parity and 2 stop bits
using Uart7E2 = UsartTemplate<
    Usart::k2,
    SysClk,
    9600,
    7,                  // 7-bit words
    Parity::kEven,      // Even parity
    StopBits::k2        // 2 stop bits
>;

// 8-bit words with odd parity and 1.5 stop bits  
using Uart8O1_5 = UsartTemplate<
    Usart::k3,
    SysClk,
    19200,
    8,                  // 8-bit words
    Parity::kOdd,       // Odd parity
    StopBits::k1_5      // 1.5 stop bits
>;
```

### Multiple USART Instances

You can configure multiple USART peripherals simultaneously:

```cpp
// Debug console on USART1
using DebugUart = UsartTemplate<Usart::k1, SysClk, 115200>;
using DebugBuffer = UartFifo<DebugUart, 128, 128>;
using DebugDriver = UsartIntDriverModel<DebugBuffer>;
using DebugPort = UsartIntDriver<DebugDriver>;

// Sensor communication on USART2
using SensorUart = UsartTemplate<Usart::k2, SysClk, 9600>;
using SensorBuffer = UartFifo<SensorUart, 64, 256>;
using SensorDriver = UsartIntDriverModel<SensorBuffer>;
using SensorPort = UsartIntDriver<SensorDriver>;

// GPS module on USART3
using GpsUart = UsartTemplate<Usart::k3, SysClk, 4800>;
using GpsDriver = UartPolledDriver<GpsUart>;
```

## Error Handling and Status

The driver provides status information:

```cpp
// Check if transmitter is busy
if (UsartGdb::IsTxBusy()) {
    // Wait or handle backpressure
}

// Check available bytes in RX buffer
size_t available = UsartGdb::Available();

// Clear buffers on error
UsartGdb::Clear();

// Get error flags
uint32_t errors = UsartGdb::GetErrors();
```

## DMA Integration (Advanced)

For high-speed data transfer, USART can be combined with DMA:

```cpp
#include "dma.h"

// DMA channel for USART1 TX
using Uart1TxDma = Dma::AnyChannel<Dma::IdUsart1Tx>;

// Configure USART with DMA
UsartGdb::EnableTxDma();
Uart1TxDma::Setup(
    /* source address */ buffer,
    /* destination */ UsartGdb::GetTxDataRegisterAddress(),
    /* length */ bufferSize,
    Dma::Dir::kMemToPeriph
);
Uart1TxDma::Start();
```

## Best Practices

1. **Buffer Sizing**: Choose FIFO sizes based on expected data rates and interrupt latency
   - Small microcontrollers: 64-256 bytes
   - High-speed links: 512+ bytes

2. **Interrupt Priority**: Set appropriate NVIC priority for USART interrupts
   ```cpp
   UsartGdbSettings::UartIrq::SetPriority(0x80); // Medium priority
   ```

3. **Power Management**: Disable USART when not in use to save power
   ```cpp
   UsartGdb::Disable();
   ```

4. **Error Recovery**: Implement timeout and error recovery mechanisms
   ```cpp
   if (UsartGdb::GetErrors() & UsartGdb::kErrorOverrun) {
       UsartGdb::ClearErrors();
       // Handle data loss
   }
   ```

## Common Use Cases

### Debug Console
```cpp
// Simple debug output
template<typename Uart>
class DebugConsole {
public:
    static void Print(const char* message) {
        while (*message) {
            Uart::Write(*message++);
        }
    }
    
    static void PrintHex(uint32_t value) {
        char buffer[9];
        // ... convert to hex
        Print(buffer);
    }
};
```

### Command Line Interface
```cpp
// Simple CLI over UART
class Cli {
    char buffer[128];
    size_t pos = 0;
    
public:
    void Process() {
        while (UsartGdb::Available()) {
            char c = UsartGdb::Read();
            if (c == '\r' || c == '\n') {
                ExecuteCommand(buffer);
                pos = 0;
                buffer[0] = '\0';
            } else if (pos < sizeof(buffer)-1) {
                buffer[pos++] = c;
                buffer[pos] = '\0';
            }
        }
    }
};
```

### Binary Protocol Handler
```cpp
// Frame-based binary protocol
class BinaryProtocol {
    enum { kMaxFrame = 256 };
    uint8_t buffer[kMaxFrame];
    size_t pos = 0;
    
public:
    void Process() {
        while (UsartGdb::Available()) {
            buffer[pos++] = UsartGdb::Read();
            if (pos >= kMaxFrame) {
                // Handle frame
                pos = 0;
            }
        }
    }
};
```

## Troubleshooting

### Common Issues

1. **No Communication**: Verify GPIO alternate function configuration and clock enable
2. **Incorrect Baud Rate**: Check system clock frequency matches configuration
3. **Data Corruption**: Ensure interrupt priorities don't cause missed characters
4. **Buffer Overruns**: Increase FIFO size or optimize data consumption rate

### Debugging Tips

```cpp
// Enable debug output
UsartGdb::EnableDebug(true);

// Check configuration at runtime
uint32_t actualBaud = UsartGdb::GetActualBaudRate();
uint32_t expectedBaud = UsartGdb::GetConfiguredBaudRate();

// Monitor buffer usage
size_t txFree = UsartGdb::GetTxFree();
size_t rxUsed = UsartGdb::GetRxUsed();
```

## Family-Specific Notes

### STM32F1xx Family
- USART1 on APB2, USART2/3 on APB1
- Limited to 3 USART peripherals (USART1-3)
- Simple baud rate calculation

### STM32L4xx Family  
- All USARTs on APB1/APB2 depending on instance
- Support for 7-bit word length with hardware emulation
- Advanced clock synchronization features

### STM32G4xx Family
- Enhanced features including smartcard mode
- Support for oversampling (8x or 16x)
- Advanced error detection

## References

- Reference implementation: `Firmware.shared/stdproj.h`
- GPIO configuration: `target.*/platform.h`
- Hardware headers: `bmt/include/*/uart.h`
- Example projects in `examples/` directory