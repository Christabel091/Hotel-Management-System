# Hotel Management System

A comprehensive hotel management system built with C++ on the command line, with plans to transition to a GUI interface. This project is a collaborative effort, with contributions from Tomi and other contributors.

## Project Overview

The Hotel Management System aims to streamline hotel operations such as booking rooms, checking availability, viewing reservations, managing customer details, and logging out. The system is designed to be robust and user-friendly, starting with a command-line interface and eventually moving to a graphical user interface (GUI).

## Features

1. **Booking Rooms**: Allow users to book available rooms.
2. **Checking Availability**: Check the availability of rooms.
3. **Viewing Reservations**: View current reservations.
4. **Managing Customer Details**: Add, update, and delete customer details.
5. **Logging Out**: Securely log out from the system.

## Development Environment Setup

1. **Install a C++ Compiler**: Ensure you have a C++ compiler installed (e.g., GCC, Clang, or MSVC).
2. **Choose an IDE/Text Editor**: Select an IDE like Visual Studio, CLion, or a text editor like VSCode.
3. **Install Necessary Libraries**: If you plan to use a GUI in the future, you may need libraries like Qt or wxWidgets.

## Basic Components of the System

### Classes and Data Structures

#### Class Room

- **Attributes**: `roomNumber`, `type` (single, double, suite), `isAvailable`, `price`
- **Methods**: `checkAvailability()`, `bookRoom()`, `releaseRoom()`

#### Class Customer

- **Attributes**: `customerId`, `name`, `contactDetails`
- **Methods**: `updateDetails()`

#### Class Reservation

- **Attributes**: `reservationId`, `room`, `customer`, `checkInDate`, `checkOutDate`
- **Methods**: `createReservation()`, `cancelReservation()`, `viewReservation()`

### File Handling

Store data persistently using file I/O operations. Use text files or binary files to store information about rooms, customers, and reservations.

- **Example files**: `rooms.txt`, `customers.txt`, `reservations.txt`

### User Interface

#### Console-based Application

Use a menu-driven approach to navigate different functionalities.

#### GUI Application

For the future GUI application, use a library like Qt to design forms and handle user input.

## Implementation Steps

### Set Up the Project

1. **Create a new project** in your IDE.
2. **Set up the file structure**: `main.cpp`, `Room.h/Room.cpp`, `Customer.h/Customer.cpp`, `Reservation.h/Reservation.cpp`.

### Implement Classes

Define the classes with their attributes and methods.

### Contributing

Contributions are welcome! Please fork this repository and submit pull requests for any features or bug fixes. If you're collaborating with others, make sure to communicate and coordinate effectively.

### Acknowledgements

- [Qt](https://www.qt.io/) for future GUI development.
- [wxWidgets](https://www.wxwidgets.org/) for future GUI development.
- Contributors:

## Future Plans

- **Transition to GUI**: After the command-line version is stable, transition the project to a graphical user interface if you want.
- **Expand Features**: Continuously improve and add new features based on user feedback and requirements.

## Project Status

This project is currently in progress. We are actively working on implementing core features and ensuring the system is robust and user-friendly. Contributions and suggestions are welcome as we continue to develop this project.
