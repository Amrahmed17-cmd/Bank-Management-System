# Bank Management System (BMSneo)

A C++ console application for managing banking operations with different user roles and account management capabilities.

## Features

### Multi-User System
- **Admin Role**: System management and oversight
- **Staff Role**: Client management and banking operations
- **Client Role**: Personal account management

### Account Management
- Account creation and deletion
- User authentication (username/password)
- Profile management

### Banking Operations
- Deposits and withdrawals
- Fund transfers between accounts
- Balance inquiry
- Transaction history

### Admin Capabilities
- Add/delete client and staff accounts
- View all client and staff information
- Search for specific clients or staff members

### Staff Capabilities
- Manage client accounts
- Process transactions
- Search for client information

### Client Capabilities
- View personal account details
- Perform transactions
- Update personal information

## Technical Information
- Written in C++
- File-based data storage
- Console-based user interface
- Visual Studio project

## Project Structure
- `main.cpp`: Main application code containing all functionality
- `Admin Database.txt`: Admin account information
- `Stuff Database.txt`: Staff account information
- `Client Database.txt`: Client account information
- Visual Studio project files (.sln, .vcxproj)

## Getting Started
1. Open the project in Visual Studio
2. Build the solution
3. Run the application
4. Choose your user role (Admin, Staff, or Client)
5. Login with appropriate credentials

## Security Features
- Password masking
- Role-based access control
- Input validation

## Developer Notes
This application demonstrates:
- C++ File I/O operations
- Object-oriented programming principles
- User interface design
- Data management and persistence 