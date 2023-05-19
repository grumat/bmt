# <big>Installation Procedure</big>

To use the **bmt** library a series of dependencies needs to be resolved, 
as covered by this documentation file.

# Extra Tools and Packages

There are quite a lot packages to be installed so that one can perform 
development of MCU projects, as covered by this topic.

## General View

The following table illustrates all required tools/packages:

| Tool/Package      | Recommended Install Method           |
|-------------------|--------------------------------------|
| VSCode            | Chocolatey                           |
| STM32CubeMX       | Setup File; alternative to VisualGDB |
| VisualGDB         | Optional; only for licensed owners   |
| GCC ARM Compiler  | VisualGDB website (free to use)      |
| CMake             | Chocolatey                           |
| Ninja             | Chocolatey                           |
| PlantUML          | Chocolatey (for documentation only)  |
| **VSCode Plugins** | |
| C/C++             | Editor extension for C/C++           |
| CMake Tools       | Project build                        |
| Cortex-Debug      | Debug extension for ARM MCU          |
| **Debug Hardware** | |
| STLink            | Optional: STM32CubeIDE setup file    |
| JLink             | Setup File                           |
| Black Magic Probe | Native supported VCOM                |


## VSCode

The easiest way is to use the Chocolatey package manager, as it allows 
one to keep everything updated. Alternatively, download the setup file 
from the Internet and install it manually.


## STM32CubeMX

> If you own a licensed copy of VIsualGDB, you can skip this tool and
> install BSP packages using VisualGDB. Please check the next topic for 
> this option.

You have to install either STM32CubeMX or VisualGDB to obtain the BSP 
packages, that contains important include files describing the hardware 
register map and boot code for each target.

The intention of these repository is to provide the **bmt** without 
strictly depending on licensed software. So, you have to download this 
package from the ST website and install it using the instructions of the 
package.

Then open the tool and download support packages for the STM32F1xx, 
STM32L4xx and STM32G4xx devices.

Install paths should look something like this:

```
%USERPROFILE%\STM32Cube\Repository\STM32Cube_FW_F1_V1.8.4\Drivers
%USERPROFILE%\STM32Cube\Repository\STM32Cube_FW_L4_V1.17.2\Drivers
%USERPROFILE%\STM32Cube\Repository\STM32Cube_FW_G4_V1.5.1\Drivers
```

> As new versions of these packages are released you may need to tune 
> this paths for the exact installed version. You can set this on the 
> `cmake-variants.yaml` file. In these case restart VSCode so that 
> changes are properly updated.


## VisualGDB

> **NOTICE:** If you opt to use the STM32CUbeMX packages, you can skip 
> this topic.

VisualGDB is a tool designed to operate with **Visual Studio** and not 
**Visual Studio Code**. But for this repo we need the BSP files that 
describing MCU ports, boot and linker files. So, in the case you own a 
legitimate copy, you don't need to install STM32CubeMX just to obtain
these BSP packages. You can reuse the installation provided with 
**VisualGDB**.

Here you will use VisualGDB only as a download tool to receive MCU 
packages and drivers. 

For VisualGDB, you have to install the STM32 BSP packages, for the
STM32F1, STM32L4 and STM32G4 families. The installation of the
BSP packages for this toolkit is:

```
%USERPROFILE%\AppData\Local\VisualGDB\EmbeddedBSPs\arm-eabi\com.sysprogs.arm.stm32
```

The `CMakeFile.txt` was developed with two scenarios in mind:
- STM32 CubeMX installation
- Standard VisualGDB installation

To chose between one of these options you will have to open the 
`CMakeFile.txt` of the root directory and edit the 
**`OPT_USE_VISUALGDB`** flag properly.


## GCC ARM Compiler

The recommended GCC compiler is the one provided with VisualGDB. For the 
owners of a licensed copy you install it using the convenient package 
manager.

If you chose the STM32CubeMX tool, please go to 
[https://gnutoolchains.com/download/](https://gnutoolchains.com/download/) 
to obtain a setup file of the **arm-eabi** compiler. It is recommended to 
use the latest version.


## CMake

CMake is used as build tool. The best way to install CMake is through the 
**Chocolatey** package manager. But you are free to download and install 
the tool manually.


## Ninja

Ninja is a requirement for CMake and you can install it also using 
**Chocolatey**.


## PlantUML

PlantUML is required to generate some of the graphics of the 
documentation. For a regular build and test this is not needed.
Again, use **Chocolatey** if you want to install it.


## VSCode Plugins

This operation is very easy to be performed using the plugins manager 
of **Visual Studio Code**. Follow the list provided on the table
and install all required plugins.


## Debug Hardware

Using Debug Hardware with **Cortex Debug** can be very tricky, since 
installing the plugin does not install all required support file (most 
are licensed ones).


# General Configuration of VSCode for Debug

Configuring **VSCode** and **Cortex Debug** is not exactly trivial. 
**Cortex Debug** is multi platform and able to handle a very complete set of 
options. This flexibility makes it very difficult when combining specific 
configurations.

In the repository you will find the `.vscode` folder which contains a 
configuration that worked with me. It is a good starting point.
Tested debuggers are **STLink**, **JLink** and the **Black Magic Probe**.
The **Black Magic Probe** is by far the easiest to configure. You just 
need to configure a single communication port. The other options will 
require you to install the required middleware and sometimes inform the 
path where they are installed.


# Tips with the Installed BSP

To use of the installed BSP files we need to provide the correct path and 
a `#define` label with the desired target.

This is programmed into the `CMakeFile.txt`, but are disclosed in the 
following table:

|     MCU     | Path                                             | Define |
|-------------|--------------------------------------------------|--------|
| STM32F103CB | `.\STM32F1xxxx\CMSIS_HAL\Device\ST\STM32F1xx\Include\stm32f1xx.h` | `STM32F103xB` |
| STM32L432KC | `.\STM32L4xxxx\CMSIS_HAL\Device\ST\STM32L4xx\Include\stm32l4xx.h` | `STM32L432xx` |
| STM32G431KB | `.\STM32L4xxxx\CMSIS_HAL\Device\ST\STM32G4xx\Include\stm32g4xx.h` | `STM32G431xx` |


A typical gcc command line would look like this:

```
arm-none-eabi-gcc.exe -DSTM32F103xB -I "%USERPROFILE%\AppData\Local\VisualGDB\EmbeddedBSPs\arm-eabi\com.sysprogs.arm.stm32\STM32F1xxxx\CMSIS_HAL\Device\ST\STM32F1xx\Include\stm32f1xx.h" ...etc...
```
