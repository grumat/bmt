# <big>The Bmt (*Bare Metal Templates*) Library</big>


# Introduction

The **bmt** library has a collection of C++ template classes for 
selected STM32 micro-controllers series and was primarily developed for 
the Glossy MSP430 Project.  
In general all templates were designed to be used in other scenarios.


## Compatibility

Currently the library supports only STM32F103 chip and an very basic 
STM32L432 compatibility is also provided.

On the next topics, a brief usage guide for the library will be 
presented. 


## Dependencies / Compiler Setup

Please see the [INSTALL.md](INSTALL.md) guide.

# Documentation for Library Name-spaces

## Namespace `clocks`

This namespace is responsible for configuring the clock tree of the STM32 
micro-controller.

[See details here](docs/clocks.md).


## SysTick Classes

These classes provides access to the System Tick timer of the MCU. It 
supports classes to setup the SysTick timer in two different modes: a 
free running timer using the full range of the timer and a second version 
that provides ticks at a specified rate, captured by an Interrupt, 
designed to be used in cooperation with a collaborative multi-task 
system. 

