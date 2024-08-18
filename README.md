# ePortfolio
**CS-499 Computer Science Capstone**


#
**Professional self-assessment**

#
**Code Review**


https://youtu.be/Yoavnz4OL_0
#
**Milestone One: Code Review**

#
**Milestone Two: Enhancement One: Software Design and Engineering**

One of the most enjoyable experiences during my studies was the construction of the thermostat control board model, gpiointerrupt.c, for the final project in the CS-350 class. This project, which involved a timer, GPIO interrupt, UART, an I2C sensor, and temperature-based LED control, was a testament to my programming abilities. The management of GPIO pins, timers, and peripherals (GPIO_init, initTimer) demonstrated my understanding of embedded system performance and reliability. This artifact, a result of an excellent course, is now a part of my ePortfolio. 
Directly initializing all global variables improved and clarified the code. Enclosing global variables in functions or restricting their scope to specific regions lowers their influence. Error management and recovery in I2C and UART must be reliable. They use UART instead of printf and UART_write for debugging output, which aids in error detection. Regularly utilizing UART_write instead of printf for debug output implies that you can communicate with embedded systems and TI-RTOS. Write interrupt handlers and sensor settings with comments that clarify ambiguous logic and briefly outline functions, including parameters, purpose, and return values. To implement the variable, update the button logic (gpioButtonFxn0 and gpioButtonFxn1) based on the current state. By testing the timing logic for application requirements, we prevented delays and overlaps. All peripherals, including timers and GPIO pins, are released when idle. Changing the thing was both instructive and life-changing. Software development taught me the importance of proper error management. Handling errors gracefully avoids crashes and ambiguity. Incorrect sensor readings and failed I2C transactions were difficult to resolve. The fault could be in software, wiring, or hardware; diagnosis necessitates a thorough approach. Detailed preparation, including understanding system needs and potential challenges, was required to ensure project success. Improving the artifact demonstrated the value of modular architecture, error control, and rigorous testing in software engineering. It emphasized hardware challenges, preparation, and thorough debugging.
#

**Milestone Three: Enhancement Two: Algorithms and Data Structure**

#

**Milestone Four: Enhancement Three: Databases**

#


https://github.com/victoria880/ePortfolio/tree/c8e6681eec701128079c95871363da27fce95a7c/CS%20499%20Milestone%20Two
https://github.com/victoria880/ePortfolio/tree/31a0faacd976d911523b7f8f2ccdd224d23f679b/CS%20499%20Milestone%20Three
https://github.com/victoria880/ePortfolio/tree/31a0faacd976d911523b7f8f2ccdd224d23f679b/CS%20499%20Milestone%20Four
