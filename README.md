# ePortfolio
**CS-499 Computer Science Capstone**


#
**Professional self-assessment**

#
**Milestone One: Code Review**


https://youtu.be/Yoavnz4OL_0
#

**Milestone Two: Enhancement One: Software Design and Engineering**

One of the most enjoyable experiences during my studies was the construction of the thermostat control board model, gpiointerrupt.c, for the final project in the CS-350 class. This project, which involved a timer, GPIO interrupt, UART, an I2C sensor, and temperature-based LED control, was a testament to my programming abilities. The management of GPIO pins, timers, and peripherals (GPIO_init, initTimer) demonstrated my understanding of embedded system performance and reliability. This artifact, a result of an excellent course, is now a part of my ePortfolio. 
Directly initializing all global variables improved and clarified the code. Enclosing global variables in functions or restricting their scope to specific regions lowers their influence. Error management and recovery in I2C and UART must be reliable. They use UART instead of printf and UART_write for debugging output, which aids in error detection. Regularly utilizing UART_write instead of printf for debug output implies that you can communicate with embedded systems and TI-RTOS. Write interrupt handlers and sensor settings with comments that clarify ambiguous logic and briefly outline functions, including parameters, purpose, and return values. To implement the variable, update the button logic (gpioButtonFxn0 and gpioButtonFxn1) based on the current state. By testing the timing logic for application requirements, we prevented delays and overlaps. All peripherals, including timers and GPIO pins, are released when idle. Changing the thing was both instructive and life-changing. Software development taught me the importance of proper error management. Handling errors gracefully avoids crashes and ambiguity. Incorrect sensor readings and failed I2C transactions were difficult to resolve. The fault could be in software, wiring, or hardware; diagnosis necessitates a thorough approach. Detailed preparation, including understanding system needs and potential challenges, was required to ensure project success. Improving the artifact demonstrated the value of modular architecture, error control, and rigorous testing in software engineering. It emphasized hardware challenges, preparation, and thorough debugging.
#

**Milestone Three: Enhancement Two: Algorithms and Data Structure**

#

**Milestone Four: Enhancement Three: Databases**

I improved AnimalShelter.py, a course final assignment. MongoDB's AnimalShelter class CRUDs animals. This code initializes the MongoDB connection and implements read, update, delete, and create. Numerous adjustments can improve code. The init method gives a username and password to the connection variables to secure database access. The new method creation replaced insert_one, enhancing code efficiency and performance. The read method returns a list of documents in addition to printing them, improving code readability. Return statements ensure data integrity. Thus, the method update included one. A return statement in the Delete Method makes code more consistent and predictable. The AnimalShelter class handles issues better and logs more thoroughly with this enhancement request, making troubleshooting and maintenance easier.

The AnimalShelter.py artifact is a significant contribution to my ePortfolio. It serves as a testament to my expertise in database management, CRUD operations, secure coding, and other critical software engineering and development project areas. It also demonstrates my talents and knowledge, as shown below.
• Add new documents to the database. 
• Read: Retrieve documents using precise criteria.
• Update: Modify existing documentation.
• Delete documents from the database.

 
Using MongoDB, a popular NoSQL database, shows my database expertise. This is especially true for future technology and system designs. I can securely manage usernames and passwords when accessing databases after learning safe coding and credential management in CS 405: Code Security. When a fundamental problem occurs, such as trying to execute an action on null data, the script promptly fixes it. Effective software development requires this. The script handles database operations with an AnimalShelter class, following object-oriented programming. The class code allows future adjustments and extensions with its scalable and easy-to-maintain modular architecture. This challenge is critical for scalable system design and matches my ePortfolio skills. 

My ePortfolio includes AnimalShelter.py, which showcases my software engineering talents and ability to build a backend service. This fulfills the software engineering and design artifact criteria for my CS 499 project. AnimalShelter.py also demonstrates my skills in database management, secure coding, object-oriented design, and the real-world application of complex programming ideas. This area of my ePortfolio is vital since it demonstrates my class and activity knowledge and skills.

I updated my outcome coverage plans to reflect AnimalShelter.py developments to meet course goals. This alignment gives my software systems additional security and makes my ePortfolio stand out. It proves I know modern database management, program architecture, and safe coding. I improved my secure coding, database administration, and program design skills by changing the AnimalShelter.py artifact. My challenges helped me improve my problem-solving and apply industry best practices, making the implementation stronger and safer. This strategy has also shown the importance of iterative and continuous software development to ensure reliable and easy-to-manage systems.

#


https://github.com/victoria880/ePortfolio/tree/c8e6681eec701128079c95871363da27fce95a7c/CS%20499%20Milestone%20Two
https://github.com/victoria880/ePortfolio/tree/31a0faacd976d911523b7f8f2ccdd224d23f679b/CS%20499%20Milestone%20Three
https://github.com/victoria880/ePortfolio/tree/31a0faacd976d911523b7f8f2ccdd224d23f679b/CS%20499%20Milestone%20Four
