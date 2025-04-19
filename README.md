# 🏦 Bank Management System (BMSneo)  

A C++ console application for managing banking operations with different user roles and account management capabilities.  

## ✨ Features  

### 👥 Multi-User System  
- **👨💼 Admin Role**: Full system control & oversight  
- **👩💻 Staff Role**: Client management & transactions  
- 👤 **Client Role**: Personal account management  

### 💳 Account Management  
- ✅ Account creation/deletion  
- 🔐 User authentication (username/password)  
- 📝 Profile management  

### 💰 Banking Operations  
- ➕ Deposits/withdrawals  
- 🔄 Fund transfers  
- 📊 Balance inquiry  
- 📜 Transaction history  

### 🛠️ Technical Info  
- **Language**: C++  
- **Storage**: File-based  
- **UI**: Console-based  
- **IDE**: Visual Studio  

## 🚀 Getting Started  
1. Open project in Visual Studio  
2. Build the solution  
3. Run the application  
4. Choose role:  
   - Admin (default creds in `Admin Database.txt`)  
   - Staff  
   - Client  

## 🔒 Security  
- 🎭 Password masking  
- 🚪 Role-based access  
- ✔️ Input validation  

## 📂 Project Structure  
📦 BMSneo
- `main.cpp` – Main source file for the system
- `Client Database.txt` – Client account records
- `Stuff Database.txt` – Staff account records
- `Admin Database.txt` – Admin account records

## 📝 Account ID Format
- Admin accounts must start with: AD
- Staff accounts must start with: ST
- Client accounts must start with: AC

## 📌 Requirements
- Windows OS (uses `conio.h`, `system("cls")`, etc.)
- C++ compiler (G++, MSVC, CodeBlocks, etc.) with C++11 or higher support

## 🚀 How to Run
1. Place all `.txt` database files in the same directory as `main.cpp`
2. Compile the project:
   ```bash
   g++ main.cpp -o BankSystem
 or Use C++ IDE

## 👨‍💻 Developer
- Created by: Amr

## 📜 License
- This project is open-source and available for educational use.
