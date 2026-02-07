# CAR-RENTAL-SYSTEM--C-programming-Language
A console-based Car Rental Management System in C with booking, billing and receipt generation features.
Car Rental System in C

This project is a console based Car Rental Management System developed using the C programming language. The main objective of this project is to demonstrate fundamental programming concepts such as structures, file handling, conditional statements, loops, and user interaction through a menu driven interface. The system simulates a basic car rental service where users can book cars, manage vehicle availability, and generate rental receipts.

Project Overview

The program allows users to view available cars, rent a car by entering customer details, add new cars to the system, remove cars from availability, view booking records, and generate a rental bill based on the number of days the vehicle was used. It also stores booking details and receipts in text files so that records are maintained even after the program execution ends.

Features

The system displays available cars along with their cost per day. Users can book a car by entering their personal details and rental duration. Administrators can add new cars to the system and update availability. Booking information is saved in a text file named carbo.txt, while generated receipts are saved in receipt.txt. The system calculates rental cost automatically and adds extra charges if the car is returned late.

Technologies Used

The project is implemented in the C programming language using standard libraries such as stdio.h, string.h, and time.h. File handling is used to store booking data and billing records persistently.

How to Run the Program

Compile the program using a C compiler such as GCC. After compilation, run the executable file and follow the on screen menu instructions to interact with the system. The required text files will be created automatically when the program is executed.

Learning Outcomes

This project helped in understanding structured programming in C, file operations, handling real world style data, and building a simple management system through a command line interface. It serves as a foundational project for students beginning their journey in programming and software development.

Future Improvements

Possible future enhancements include adding a graphical interface, integrating a database instead of text files, implementing user authentication, and improving input validation to make the system more robust and scalable
