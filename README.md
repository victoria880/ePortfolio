# **ePortfolio**

Greetings! 

My name is Victoria Franklin, and I am a dedicated computer science student at SNHU. In October 2018, I embarked on a journey to earn my Bachelor of Science degree in computer science, and I am thrilled to share my progress with you through this GitHub account. Here, I will showcase my work for CS-499 and other projects contributing to my academic journey. 

---
# **CS-499 Computer Science Capstone**

<img src="https://github.com/victoria880/ePortfolio/blob/34b5c89d359b2a50ddfe9c961f1d8cf76a572031/pictures/source.jpg" alt="Source Image" width="2000" height="300" />

---

## **Professional Self-Assessment**

During my pursuit of a BS in computer science from Southern New Hampshire University with a software engineering concentration, I have acquired a diverse set of skills. These include proficiency in various programming languages, an understanding of computer hardware and software, and familiarity with the different phases of the software development life cycle. I have demonstrated my expertise in database management with SQL and MongoDB and my understanding of programming languages like C++, Python, and Java. This comprehensive program has equipped me to excel in a career in software engineering.


SDLC projects like the thermostat control board model `gpiointerrupt.c` have helped me learn embedded system software development and operation. I'm good at hardware interactions, code reuse, and program stability. I worked on `BufferOverflow.cpp` in CS 405: Secure Coding to learn about security problems and how to address them. Fixing buffer overflows and using secure code has enhanced my software's reliability and safety. Information Models and Programs: I used AnimalShelter.py to demonstrate my data operations and algorithm design skills in CS340: Advanced Programming Concepts. This project showed I can handle complex data structures and apply theoretical concepts. `AnimalShelter.py` helped individuals handle MongoDB NoSQL databases. This project investigated database access security, data integrity, and CRUD. 

Through the program and culminating project, I have gained valuable skills beyond technical knowledge, significantly enhancing my career development. It was recommended to take a systematic approach to finding and fixing complex issues for data processing, code debugging, and security vulnerabilities. I have honed my project management abilities by submitting my work on time. These abilities enable me to organize, carry out, and assess my tasks. Communication is vital in teamwork and business, and code reviews and detailed documentation have helped me enhance this skill. The curriculum has fostered a spirit of continuous learning and technical relevance through its experiences and challenges.
Because of my experience in the computer science program and the CS-499 Capstone project, I am more prepared for the workforce. With the information and knowledge presented in this ePortfolio, I am confident in my ability to make a positive impact in the field of computer science. As a software developer, I can't wait to use these skills in the real world. 

---

## **Milestone One: Code Review**
<img src="https://github.com/victoria880/ePortfolio/blob/55474edca4d468bc25105a0e85ebab390b292464/pictures/Picture2.png" alt="Source Image" width="50" height="50" />

As part of my first strategy, I recorded myself reviewing the code for each artifact. This code review details my strategy for improving the code by analyzing it for constraints, flaws, and vulnerabilities. These code reviews show each category's essential features as they travel through the current code and proposed improvements.

This code review evaluates three artifacts: software engineering and design, algorithms and data structures, and databases. The first artifact, `gpiointerrupt.c`, is a model for a thermostat control board written in C and run in Code Composer Studio. It showcases the process of interacting with hardware components like LEDs, buttons, UART, I2C, and timers. The code could use improvements such as reduced redundancy, refactored button handling, consistent code formatting, enhanced error handling and logging, improved comments, unit tests, and breaking down functions into smaller modules.

The second artifact, `BufferOverflow.cpp`, is C++ code from the CS 405: Secure Coding course. It has a buffer overflow vulnerability, which can be addressed by applying `std::setw(20)` correctly, implementing error handling, and implementing thorough unit tests.

The third artifact, `AnimalShelter.py`, is a final project from CS 340: Advanced Programming Concepts. It creates an `AnimalShelter` class in MongoDB that performs CRUD actions on an animal collection. The code snippet defines the `AnimalShelter` class, which includes methods for creating, reading, updating, and deleting data. Improvements include adding unit tests for CRUD operations and typing hints for better readability and maintainability.

[Watch the Code Review on YouTube](https://youtu.be/Yoavnz4OL_0)

---

## **Milestone Two: Enhancement One: Software Design and Engineering**
<img src="https://github.com/victoria880/ePortfolio/blob/92632b90b84c9b4b852a579c4a9c81a6214657f6/pictures/software%20.png" alt="Source Image" width="50" height="50" />

One of the most enjoyable experiences during my studies was the construction of the thermostat control board model, `gpiointerrupt.c`, for the final project in the CS-350 class. This project, which involved a timer, GPIO interrupt, UART, an I2C sensor, and temperature-based LED control, was a testament to my programming abilities. The management of GPIO pins, timers, and peripherals (`GPIO_init`, `initTimer`) demonstrated my understanding of embedded system performance and reliability. This artifact, a result of an excellent course, is now a part of my ePortfolio. Directly initializing all global variables improved and clarified the code. Enclosing global variables in functions or restricting their scope to specific regions lowers their influence. Error management and recovery in I2C and UART must be reliable. They use UART instead of `printf` and `UART_write` for debugging output, which aids in error detection. Regularly utilizing `UART_write` instead of `printf` for debug output implies that you can communicate with embedded systems and TI-RTOS. Write interrupt handlers and sensor settings with comments that clarify ambiguous logic and briefly outline functions, including parameters, purpose, and return values. To implement the variable, update the button logic (`gpioButtonFxn0` and `gpioButtonFxn1`) based on the current state. By testing the timing logic for application requirements, we prevented delays and overlaps. All peripherals, including timers and GPIO pins, are released when idle. Changing the thing was both instructive and life-changing. Software development taught me the importance of proper error management. Handling errors gracefully avoids crashes and ambiguity. Incorrect sensor readings and failed I2C transactions were difficult to resolve. The fault could be in software, wiring, or hardware; diagnosis necessitates a thorough approach. Detailed preparation, including understanding system needs and potential challenges, was required to ensure project success. Improving the artifact demonstrated the value of modular architecture, error control, and rigorous testing in software engineering. It emphasized hardware challenges, preparation, and thorough debugging.

[View the Enhancement on GitHub](https://github.com/victoria880/ePortfolio/tree/6a7c200dd488dd7387909454143adc3c48bc4cda/CS%20499%20Milestone%20Two)

---

## **Milestone Three: Enhancement Two: Algorithms and Data Structures**
<img src="https://github.com/victoria880/ePortfolio/blob/19649b33bf8578215bea4dc52c89b7f4e3ce70e3/pictures/algorithm.png" alt="Source Image" width="50" height="50" />

The `BufferOverflow.cpp` artifact from CS 405: Secure Coding is crucial to my enhancement. It's a classic runtime error: a buffer overflow, which occurs when a program writes past an array or buffer's end, corrupting nearby memory. This artifact is important because it shows my profound grasp of such vulnerabilities commonly caused by unexpected user input. For several reasons, CS 405: Secure Coding and `BufferOverflow.cpp` must be on my ePortfolio. Buffer overflows are among the worst software security concerns, and `BufferOverflow.cpp` shows my knowledge of them. Secure coding approaches include a theoretical notion and a practical tool to detect, analyze, and resolve these concerns in real-world scenarios. I can code securely and implement protections to avoid standard security holes. Finding and fixing a buffer overflow vulnerability requires advanced problem-solving skills. I apply a systematic strategy to analyze security vulnerabilities, determine their sources, and execute successful remedies. Standardization bodies and safe coding guidelines have extensively addressed buffer overflow issues. This artifact proves that I am ready to work professionally and that my secure software development skills meet industry standards.

Buffer overflow issues need memory management and low-level programming knowledge. My artifact shows my technical talents in these areas, which are vital for secure software development. This item shows my real-world secure coding experience. It shows that I participated in hands-on activities and projects to improve my skills, strengthening my ePortfolio and credibility. By incorporating `BufferOverflow.cpp`, I can describe my learning experience in CS 405 and my ongoing pursuit of improvement. I may discuss my learning goals, challenges, and knowledge to contextualize my skills and experiences.

Enhanced `BufferOverflow.cpp` handles input correctly and provides user feedback when input is incorrect to prevent buffer overflow. The input size shouldn't exceed the buffer size. A warning is given if the input exceeds the buffer. A for-loop continually asks the user for the proper information to manage any remaining inaccurate data in the input stream. Using `std::cin.getline` as your input reader handles null terminators correctly. The input stream's status is checked for interruptions. The user is constantly reminded to supply valid data to avoid buffer overflow. Remove erroneous input from the stream with `std::cin.clear()` and `ignore()`. This procedure eliminates buffer overflow and shows my security expertise, ability to solve security issues, and devotion to industry standards, making `BufferOverflow.cpp` a significant contribution to my ePortfolio.

As promised in the first module, I improved `BufferOverflow.cpp`. This artifact is part of my ePortfolio and helped me meet course goals. I modified my outcome-coverage strategies and listed the targets below. I upgraded `BufferOverflow.cpp` in Module One to demonstrate my knowledge of security risks, secure coding, and problem-solving. This helped me meet course goals. My future result coverage goals include practical applications, clear documentation, gradual upgrades, a more comprehensive range of security ideas, and interactive demos. These changes better showcase my secure coding skills in my ePortfolio.

Improving and changing `BufferOverflow.cpp` taught me a lot. Secure coding, testing, and documentation are essential to prevent buffer overflow vulnerabilities. Finding hidden vulnerabilities, balancing performance and security, and dealing with complex edge cases helped me become a better software developer. This experience strengthened my secure coding skills and prepared me to manage security difficulties in software development.

[View the Enhancement on GitHub](https://github.com/victoria880/ePortfolio/tree/5b56d78b780bbb0726b050e3f276e2efdb2f777f/CS%20499%20Milestone%20Three)

---

## **Milestone Four: Enhancement Three: Databases**
<img src="https://github.com/victoria880/ePortfolio/blob/cd8a787eb38216d9cef593e608824682d885836f/pictures/database.png" alt="Source Image" width="50" height="50" />

I improved `AnimalShelter.py`, a course final assignment. MongoDB's `AnimalShelter` class CRUDs animals. This code initializes the MongoDB connection and implements read, update, delete, and create. Numerous adjustments can improve code. The `init` method gives a username and password to the connection variables to secure database access. The new method creation replaced `insert_one`, enhancing code efficiency and performance. The `read` method returns a list of documents in addition to printing them, improving code readability. Return statements ensure data integrity. Thus, the method `update` included one. A return statement in the `Delete` Method makes code more consistent and predictable. The `AnimalShelter` class handles issues better and logs more thoroughly with this enhancement request, making troubleshooting and maintenance easier.

The `AnimalShelter.py` artifact is a significant contribution to my ePortfolio. It serves as a testament to my expertise in database management, CRUD operations, secure coding, and other critical software engineering and development project areas. It also demonstrates my talents and knowledge, as shown below.

- `Add new documents to the database.`
- `Read: Retrieve documents using precise criteria.`
- `Update: Modify existing documentation.`
- `Delete documents from the database.`

Using MongoDB, a popular NoSQL database, shows my database expertise. This is especially true for future technology and system designs. I can securely manage usernames and passwords when accessing databases after learning safe coding and credential management in CS 405: Code Security. When a fundamental problem occurs, such as trying to execute an action on null data, the script promptly fixes it. Effective software development requires this. The script handles database operations with an `AnimalShelter` class, following object-oriented programming. The class code allows future adjustments and extensions with its scalable and easy-to-maintain modular architecture. This challenge is critical for scalable system design and matches my ePortfolio skills.

My ePortfolio includes `AnimalShelter.py`, which showcases my software engineering talents and ability to build a backend service. This fulfills the software engineering and design artifact criteria for my CS 499 project. `AnimalShelter.py` also demonstrates my skills in database management, secure coding, object-oriented design, and the real-world application of complex programming ideas. This area of my ePortfolio is vital since it demonstrates my class and activity knowledge and skills.

I updated my outcome coverage plans to reflect `AnimalShelter.py` developments to meet course goals. This alignment gives my software systems additional security and makes my ePortfolio stand out. It proves I know modern database management, program architecture, and safe coding. I improved my secure coding, database administration, and program design skills by
changing the `AnimalShelter.py` artifact. My challenges helped me improve my problem-solving and apply industry best practices, making the implementation stronger and safer. This strategy has also shown the importance of iterative and continuous software development to ensure reliable and easy-to-manage systems.

[View the Enhancement on GitHub](https://github.com/victoria880/ePortfolio/tree/6a7c200dd488dd7387909454143adc3c48bc4cda/CS%20499%20Milestone%20Four)

---

## **ePorfolio Links**

[GitHub.io](https://victoria880.github.io/ePortfolio/)

[Journals](https://github.com/victoria880/ePortfolio/tree/c9a7c3edd1808dc45704e325ab32ca2a0536588a/Journals)

[Professional Self-Assessment ](https://github.com/victoria880/ePortfolio/blob/a4b72e38b29074b7d7c2cee4bc80da24ba9e1a5c/Professional%20Self.pdf)


---
