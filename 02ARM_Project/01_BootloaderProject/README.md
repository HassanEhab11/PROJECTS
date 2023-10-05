# BootloaderProject

In this project, we developed a system for firmware updates using two microcontrollers, MC_1 and MC_2. MC_1 serves as an application microcontroller, and it transmits hex files to MC_2, which contains a bootloader code. This communication is done using USART (Universal Synchronous/Asynchronous Receiver/Transmitter) communication, and a push-button connected to EXTI (External Interrupt) is used to initiate the firmware update process. 

This is a common approach for updating firmware in embedded systems. Here's a breakdown of the key components and steps involved in such a project:

## 1. **MC_1 (Application Microcontroller):**
   - This microcontroller is responsible for running the main application.
   - It has the capability to communicate with MC_2 via USART.
   - It has a push-button connected to an external interrupt pin (EXTI), which is used to trigger the firmware update process.

## 2. **MC_2 (Bootloader Microcontroller):**
   - This microcontroller is dedicated to managing the firmware update process.
   - It contains a bootloader code that can receive and write firmware updates.
   - It communicates with MC_1 through USART to receive hex files.

## 3. **USART Communication:**
   - USART (Universal Synchronous/Asynchronous Receiver/Transmitter) is used for serial communication between MC_1 and MC_2.
   - MC_1 sends the hex files (firmware updates) to MC_2 over the USART interface.

## 4. **Push-Button and EXTI:**
   - A push-button is connected to one of the GPIO pins of MC_1.
   - EXTI (External Interrupt) is configured to trigger when the push-button is pressed.
   - When the push-button is pressed, MC_1 initiates the firmware update process by sending a signal to MC_2 through the EXTI interrupt.

## 5. **Firmware Update Process:**
   - When the push-button is pressed, MC_1 prepares the hex file for the firmware update.
   - MC_1 sends the hex file to MC_2 over USART.
   - MC_2 receives the hex file, verifies it, and writes it to the appropriate memory location.
   - After successful firmware update, MC_2 may reset or signal MC_1 to indicate completion.


