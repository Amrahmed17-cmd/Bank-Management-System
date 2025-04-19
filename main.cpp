#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <cstdio>
#include <limits>
using namespace std;

struct Client 
{
    string Fname;
    string Lname;
    string gender;
    string address;
    string mail;
    string AccId;
    long long NId;
    long long age;
    long long phone;
    long long balance;
    string username;
    string password;

    Client(string Fname, string Lname, string gender, string address, string mail, string AccId,
        long long NId, long long age, long long phone, long long balance, string username, string password)
        : Fname(Fname), Lname(Lname), gender(gender), address(address), mail(mail), AccId(AccId),
        NId(NId), age(age), phone(phone), balance(balance), username(username), password(password) {}
};

void loadAdminFile(vector<Client>& database)
{
    ifstream adminFile("Admin Database.txt");
    if (!adminFile.is_open())
    {
        cerr << "Error: Unable to open Admin Database file." << endl;
        return;
    }

    string Fname, Lname, gender, address, mail, AccId, username, password;
    long long NId, age, phone, balance;
    while (adminFile >> AccId >> Fname >> Lname >> gender >> NId >> age >> phone >> address >> mail >> balance >> username >> password) 
    {
        Client accessData(Fname, Lname, gender, address, mail, AccId, NId, age, phone, balance, username, password);
        database.push_back(accessData);
    }

    adminFile.close();
}

void loadStuffFile(vector<Client>& database)
{
    ifstream stuffFile("Stuff Database.txt");
    if (!stuffFile.is_open())
    {
        cerr << "Error: Unable to open Stuff database file." << endl;
        return;
    }

    string Fname, Lname, gender, address, mail, AccId, username, password;
    long long NId, age, phone, balance;
    while (stuffFile >> AccId >> Fname >> Lname >> gender >> NId >> age >> phone >> address >> mail >> balance >> username >> password) 
    {
        Client accessData(Fname, Lname, gender, address, mail, AccId, NId, age, phone, balance, username, password);
        database.push_back(accessData);
    }

    stuffFile.close();
}

void loadClientsFile(vector<Client>& database)
{
    ifstream clientFile("Client Database.txt");
    if (!clientFile.is_open())
    {
        cerr << "Error: Unable to open database file." << endl;
        return;
    }

    string Fname, Lname, gender, address, mail, AccId, username, password;
    long long NId, age, phone, balance;
    while (clientFile >> AccId >> Fname >> Lname >> gender >> NId >> age >> phone >> address >> mail >> balance >> username >> password) 
    {
        Client accessData(Fname, Lname, gender, address, mail, AccId, NId, age, phone, balance, username, password);
        database.push_back(accessData);
    }

    clientFile.close();
}

void messagesLoad()
{
    cout << "Loading..." << endl;
    system("pause");
    system("cls");
    cout << "Admin Data loaded from file successfully." << endl;
    system("pause");
    cout << endl;
    cout << "Stuff Data loaded from file successfully." << endl;
    system("pause");
    cout << endl;
    cout << "Clients Data loaded from file successfully." << endl;
    system("pause");
    cout << endl;
    cout << "Bank Management System Loaded Successful.." << endl;
    system("pause");
    system("cls");
}

void allLoadFunction(vector<Client>& database)
{
    loadAdminFile(database);
    loadStuffFile(database);
    loadClientsFile(database);
}

bool adminLogin(vector<Client>& database) 
{
    bool loggedIn = false;
    while (!loggedIn) 
    {
        cout << "Enter username: ";
        string username;
        cin.ignore();
        getline(cin, username);

        cout << endl;

        cout << "Enter password: ";
        string password;
        char ch;
        while ((ch = _getch()) != '\r') 
        {
            if (ch == '\b') 
            {
                if (!password.empty()) 
                {
                    cout << "\b \b";
                    password.pop_back();
                }
            }
            else 
            {
                cout << '*';
                password.push_back(ch);
            }
        }
        cout << endl;

        for (const auto& client : database) 
        {
            if (client.username == username && client.password == password && client.AccId.substr(0, 2) != "ST" && client.AccId.substr(0, 2) != "AC") 
            {
                cout << endl;
                cout << "Login successful!" << endl;
                system("pause");
                system("cls");
                loggedIn = true;
                break;
            }
        }

        if (!loggedIn) 
        {
            cout << endl;
            cout << "Login failed. Incorrect username or password. Please try again." << endl;
            system("pause");
            system("cls");
            return false;
        }
    }

    return true;
}

bool stuffLogin(vector<Client>& database) 
{
    bool loggedIn = false;
    while (!loggedIn) 
    {
        cout << "Enter username: ";
        string username;
        cin.ignore();
        getline(cin, username);

        cout << "Enter password: ";
        string password;
        char ch;
        while ((ch = _getch()) != '\r') 
        {
            if (ch == '\b') {
                if (!password.empty()) 
                {
                    cout << "\b \b";
                    password.pop_back();
                }
            }
            else 
            {
                cout << '*';
                password.push_back(ch);
            }
        }
        cout << endl;

        for (const auto& client : database) 
        {
            if (client.username == username && client.password == password && client.AccId.substr(0, 2) != "AC" && client.AccId.substr(0, 2) != "AD") 
            {
                cout << endl;
                cout << "Login successful!" << endl;
                system("pause");
                system("cls");
                loggedIn = true;
                break;
            }
        }

        if (!loggedIn) 
        {
            cout << endl;
            cout << "Login failed. Incorrect username or password. Please try again." << endl;
            system("pause");
            system("cls");
            return false;
        }
    }

    return true;
}

bool clientLogin(vector<Client>& database, size_t& loggedInClientIndex)
{
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    char ch;
    password = "";
    while ((ch = _getch()) != '\r') {
        password.push_back(ch);
        cout << '*';
    }
    cout << endl;

    // Find the index of the logged-in client in the database
    auto clientIter = find_if(database.begin(), database.end(), [&](const Client& client) {
        return client.username == username && client.password == password && client.AccId.substr(0, 2) != "ST" && client.AccId.substr(0, 2) != "AD";
        });

    if (clientIter != database.end()) {
        // Client found, store the index
        loggedInClientIndex = distance(database.begin(), clientIter);
        cout << endl;
        cout << "Login successful!"<< endl;
        system("pause");
        return true;
    }

    cout << endl;
    cout << "Login failed. Incorrect username or password. Please try again." << endl;
    system("pause");
    system("cls");
    return false;
}

void adminSearchClient(vector<Client>& database, const string& searchID)
{
    bool found = false;
    for (const auto& client : database) 
    {
        if (client.AccId == searchID && client.AccId.substr(0, 2) != "AD" && client.AccId.substr(0, 2) != "ST")
        {
            found = true;
            system("cls");
            cout << "Client found:\n";
            cout << endl;
            cout << endl;
            cout << "AccID      First Name   Last Name    Gender       NationalID        Age          Phone                 Address                 Mail                 Balance " << endl;
            cout << "===========================================================================================================================================================" << endl;
            cout << endl;
            cout << client.AccId << "  "
                << setw(11) << client.Fname << "  "
                << setw(12) << client.Lname << "  "
                << setw(11) << client.gender << "  "
                << setw(15) << client.NId << "  "
                << setw(6) << client.age << "  "
                << setw(16) << client.phone << "  "
                << setw(19) << client.address << "  "
                << setw(25) << client.mail << "  "
                << setw(17) << client.balance << "  " << endl;
            break;
        }
    }
    cout << endl;
    if (!found) 
    {
        cout << "Client not found." << endl;
    }
    system("pause");
}

void adminSearchStuff(vector<Client>& database, const string& searchID)
{
    bool found = false;
    for (const auto& stuff : database)
    {
        if (stuff.AccId == searchID && stuff.AccId.substr(0, 2) != "AC" && stuff.AccId.substr(0, 2) != "AD")
        {
            found = true;
            system("cls");
            cout << "Stuff found:\n";
            cout << endl;
            cout << endl;
            cout << "AccID      First Name   Last Name    Gender       NationalID        Age          Phone                 Address                 Mail           " << endl;
            cout << "==============================================================================================================================================" << endl;
            cout << endl;
            cout << stuff.AccId << "  "
                << setw(11) << stuff.Fname << "  "
                << setw(12) << stuff.Lname << "  "
                << setw(11) << stuff.gender << "  "
                << setw(15) << stuff.NId << "  "
                << setw(6) << stuff.age << "  "
                << setw(16) << stuff.phone << "  "
                << setw(19) << stuff.address << "  "
                << setw(25) << stuff.mail << "  " << endl;
            break;
        }
    }
    cout << endl;
    if (!found)
    {
        cout << "Client not found." << endl;
    }
    system("pause");
}

void adminDisplayAllClients(vector<Client>& database)
{
    sort(database.begin(), database.end(), [](const Client& a, const Client& b) {
        return a.AccId < b.AccId;
        });

    system("cls");
    cout << "Clients List:\n";
    cout << endl;
    cout << "AccID      First Name   Last Name    Gender       NationalID        Age          Phone                 Address                 Mail                 Balance " << endl;
    cout << "===========================================================================================================================================================" << endl;

    for (auto& client : database) 
    {
        if (client.AccId.substr(0, 2) != "AD" && client.AccId.substr(0, 2) != "ST") 
        {
            cout << client.AccId << "  "
                << setw(11) << client.Fname << "  "
                << setw(12) << client.Lname << "  "
                << setw(11) << client.gender << "  "
                << setw(15) << client.NId << "  "
                << setw(6) << client.age << "  "
                << setw(16) << client.phone << "  "
                << setw(19) << client.address << "  "
                << setw(25) << client.mail << "  "
                << setw(17) << client.balance << "  " << endl;
        }
    }
    cout << endl;
    system("pause");
}

void adminDisplayAllStuffs(vector<Client>& database)
{
    sort(database.begin(), database.end(), [](const Client& a, const Client& b) {
        return a.AccId < b.AccId;
        });

    system("cls");
    cout << "Stuffs List:\n";
    cout << endl;
    cout << "AccID      First Name   Last Name    Gender       NationalID        Age          Phone                 Address                 Mail           " << endl;
    cout << "==============================================================================================================================================" << endl;

    for (auto& stuff : database)
    {
        if (stuff.AccId.substr(0, 2) != "AD" && stuff.AccId.substr(0, 2) != "AC")
        {
            cout << stuff.AccId << "  "
                << setw(11) << stuff.Fname << "  "
                << setw(12) << stuff.Lname << "  "
                << setw(11) << stuff.gender << "  "
                << setw(15) << stuff.NId << "  "
                << setw(6) << stuff.age << "  "
                << setw(16) << stuff.phone << "  "
                << setw(19) << stuff.address << "  "
                << setw(25) << stuff.mail << "  " << endl;
        }
    }
    cout << endl;
    system("pause");
}

void updateClientsDatabase(vector<Client>& database);  // FORWARD DECLARED FUNCTION

void adminDeleteClientAccount(const string& accId, vector<Client>& database)
{
    if (accId.substr(0, 2) == "ST")
    {
        cout << endl;
        cerr << "Error: Cannot delete Staff accounts in this portion." << endl;
        system("pause");
        return;
    }
    if (accId.substr(0, 2) == "AD")
    {
        cout << endl;
        cerr << "Error: Cannot delete Admin accounts." << endl;
        system("pause");
        return;
    }

    ifstream inFile("Client Database.txt");
    if (!inFile)
    {
        cerr << "Error: Unable to open database file." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile)
    {
        cerr << "Error: Unable to create temporary file." << endl;
        inFile.close();
        return;
    }

    string line;
    bool found = false;

    while (getline(inFile, line))
    {
        // Check if the line contains the account ID
        if (line.find(accId) != string::npos)
        {
            // Check if the account ID starts with "AC"
            if (line.substr(0, 2) == "AC")
            {
                found = true;
                continue; // Skip writing this line to temp file
            }
            else
            {
                cerr << "Error: Cannot delete Staff accounts." << endl;
                inFile.close();
                tempFile.close();
                remove("temp.txt");
                return;
            }
        }
        tempFile << line << endl; // Write line to temp file
    }

    inFile.close();
    tempFile.close();

    if (!found)
    {
        cout << endl;
        cout << "Account with AccId '" << accId << "' not found in the database." << endl;
        remove("temp.txt");
        system("pause");
        return;
    }

    if (remove("Client Database.txt") != 0)
    {
        cerr << "Error: Unable to delete original database file." << endl;
        return;
    }

    if (rename("temp.txt", "Client Database.txt") != 0)
    {
        cerr << "Error: Unable to rename temporary file." << endl;
        return;
    }

    cout << endl;
    cout << "Account with AccId '" << accId << "' successfully deleted from the database." << endl;
    system("pause");

    database.clear();
    loadClientsFile(database);
    updateClientsDatabase(database);
}

void adminDeleteStuffAccount(const string& accId, vector<Client>& database)
{
    if (accId.substr(0, 2) == "AC")
    {
        cout << endl;
        cerr << "Error: Cannot delete Client accounts in this portion." << endl;
        system("pause");
        return;
    }
    if (accId.substr(0, 2) == "AD")
    {
        cout << endl;
        cerr << "Error: Cannot delete Admin accounts." << endl;
        system("pause");
        return;
    }

    ifstream inFile("Stuff Database.txt");
    if (!inFile)
    {
        cerr << "Error: Unable to open database file." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile)
    {
        cerr << "Error: Unable to create temporary file." << endl;
        inFile.close();
        return;
    }

    string line;
    bool found = false;

    while (getline(inFile, line))
    {
        // Check if the line contains the account ID
        if (line.find(accId) != string::npos)
        {
            // Check if the account ID starts with "ST"
            if (line.substr(0, 2) == "ST")
            {
                found = true;
                continue; // Skip writing this line to temp file
            }
            else
            {
                cerr << "Error: Cannot delete Client accounts." << endl;
                inFile.close();
                tempFile.close();
                remove("temp.txt");
                return;
            }
        }
        tempFile << line << endl; // Write line to temp file
    }

    inFile.close();
    tempFile.close();

    if (!found)
    {
        cout << endl;
        cout << "Account with AccId '" << accId << "' not found in the database." << endl;
        remove("temp.txt");
        system("pause");
        return;
    }

    if (remove("Stuff Database.txt") != 0)
    {
        cerr << "Error: Unable to delete original database file." << endl;
        return;
    }

    if (rename("temp.txt", "Stuff Database.txt") != 0)
    {
        cerr << "Error: Unable to rename temporary file." << endl;
        return;
    }

    cout << endl;
    cout << "Account with AccId '" << accId << "' successfully deleted from the database." << endl;
    system("pause");

    database.clear();
    loadStuffFile(database);
}

void adminMenu(vector<Client>& database)
{
    bool loggedIn = adminLogin(database);

    if (!loggedIn) 
    {
        return;
    }

    int choice;
    do
    {
        system("cls");
        cout << "================================================================\n";
        cout << "======================= Admin's Portion ========================\n";
        cout << "================================================================\n";
        cout << endl;
        cout << "1. Search for a specific Client by ID\n";
        cout << "2. Search for a specific Stuff by ID\n";
        cout << "3. Display all Clients\n";
        cout << "4. Display all Stuffs\n";
        cout << "5. Delete Client account\n";
        cout << "6. Delete Stuff account\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string searchID;
            cout << endl;
            cout << "Enter the Client AccID of the client you want to search for (Must Start AC): ";
            cin >> searchID;
            adminSearchClient(database, searchID);
            break;
        }
        case 2:
        {
            string searchID;
            cout << endl;
            cout << "Enter the Stuff AccID of the stuff you want to search for (Must Start ST): ";
            cin >> searchID;
            adminSearchStuff(database, searchID);
            break;
        }
        case 3:
            adminDisplayAllClients(database);
            break;
        case 4:
            adminDisplayAllStuffs(database);
            break;
        case 5:
        {
            string AccIdDelete;
            cout << endl;
            cout << "Enter the Client AccID of the account you want to delete: ";
            cin >> AccIdDelete;
            adminDeleteClientAccount(AccIdDelete, database);
            break;
        }
        case 6:
        {
            string AccIdDelete;
            cout << endl;
            cout << "Enter the Stuff AccID of the account you want to delete: ";
            cin >> AccIdDelete;
            adminDeleteStuffAccount(AccIdDelete, database);
            break;
        }
        case 7:
            system("cls");
            cout << "Exiting admin menu..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            system("pause");
            break;
        }
    } while (choice != 7);
}

void adminMain()
{
    vector<Client> database;
    allLoadFunction(database);
    adminMenu(database);

    system("pause");
    system("cls");
}

string genderInput() 
{
    string gender;
    while (true) 
    {
        cout << "Gender (M/F): ";
        cin >> gender;
        if (gender == "M" || gender == "F") 
        {
            return gender == "M" ? "male" : "female";
        }
        cout << "Invalid input. Please enter 'M' for male or 'F' for female: ";
    }
}

long long nationalIdInput() 
{
    string nationalId;
    while (true) 
    {
        cout << "National ID: ";
        cin >> nationalId;
        if (nationalId.length() <= 18) 
        {
            return stoll(nationalId);
        }
        cout << "National ID cannot exceed 18 digits. Please enter a valid NID: ";
    }
}

long long ageInput() 
{
    long long age;
    while (true) 
    {
        cout << "Age: ";
        cin >> age;
        if (age >= 18) 
        {
            return age;
        }
        cout << "Minimum age requirement is 18 years old. Please enter a valid age: ";
    }
}

long long phoneNumberInput() 
{
    string phoneNumber;
    while (true) 
    {
        cout << "Phone Number (10 digits - Zero not counted): ";
        cin >> phoneNumber;
        if (phoneNumber.length() == 10 && phoneNumber[0] != '0') 
        {
            return stoll(phoneNumber);
        }
        cout << "Phone number must be exactly 10 digits long without zero. Please enter a valid phone number: ";
    }
}

long long initialDepositInput() 
{
    long long balance;
    while (true) 
    {
        cout << "Enter the amount you want to deposit firstly (minimum 50 LE): ";
        cin >> balance;
        if (balance >= 50) 
        {
            return balance;
        }
        cout << "Minimum deposit amount is 50 LE. Please enter a valid amount: ";
    }
}

string usernameInput() 
{
    string username;
    cout << "Enter username: ";
    cin >> username;
    return username;
}

string passwordInput() 
{
    string password;
    cout << "Enter password: ";
    cin >> password;
    return password;
}

void writeClientToFile(vector<Client>& database) 
{
    // Sort clients by AccId in ascending order
    sort(database.begin(), database.end(), [](const Client& a, const Client& b) 
        {
        return a.AccId < b.AccId;
        }
    );

    ofstream outFile("Client Database.txt");
    if (!outFile) 
    {
        cerr << "Error: Unable to open database file for writing." << endl;
        exit(1);
    }

    for (const auto& client : database) {
        outFile << client.AccId << " " << client.Fname << " " << client.Lname << " " << client.gender << " " << client.NId << " " << client.age << " " << client.phone << " " << client.address << " " << client.mail << " " << client.balance << " " << client.username << " " << client.password << endl;
    }

    outFile.close();
}

void addNewAccount(vector<Client>& database)
{
    string Fname, Lname, gender, address, mail, AccId, username, password;
    long long NId, age, phone, balance;

    cout << endl;
    cout << "Please enter the new client's details:" << endl;
    cout << endl;
    cout << "Account ID (Must start with AC code): ";
    cin >> AccId;

    cout << "First Name: ";
    cin >> Fname;

    cout << "Last Name: ";
    cin >> Lname;

    gender = genderInput();

    NId = nationalIdInput();

    age = ageInput();

    phone = phoneNumberInput();

    cout << "Address: ";
    cin.ignore();
    getline(cin, address);

    cout << "Mail: ";
    getline(cin, mail);

    balance = initialDepositInput();

    username = usernameInput();
    password = passwordInput();

    Client newClient{ Fname, Lname, gender, address, mail, AccId, NId, age, phone, balance, username, password };
    database.push_back(newClient);

    writeClientToFile(database);

    cout << endl;
    cout << "New client added successfully to Database!" << endl;
    system("pause");
    system("cls");
}

void stuffDeleteClientAccount(const string& accId, vector<Client>& database)
{
    if (accId.substr(0, 2) == "ST")
    {
        cout << endl;
        cerr << "Error: Cannot delete Staff accounts in this portion." << endl;
        system("pause");
        return;
    }
    if (accId.substr(0, 2) == "AD")
    {
        cout << endl;
        cerr << "Error: Cannot delete Admin accounts." << endl;
        system("pause");
        return;
    }

    ifstream inFile("Client Database.txt");
    if (!inFile)
    {
        cerr << "Error: Unable to open database file." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile)
    {
        cerr << "Error: Unable to create temporary file." << endl;
        inFile.close();
        return;
    }

    string line;
    bool found = false;

    while (getline(inFile, line))
    {
        // Check if the line contains the account ID
        if (line.find(accId) != string::npos)
        {
            // Check if the account ID starts with "AC"
            if (line.substr(0, 2) == "AC")
            {
                found = true;
                continue; // Skip writing this line to temp file
            }
            else
            {
                cerr << "Error: Cannot delete Staff accounts." << endl;
                inFile.close();
                tempFile.close();
                remove("temp.txt");
                return;
            }
        }
        tempFile << line << endl; // Write line to temp file
    }

    inFile.close();
    tempFile.close();

    if (!found)
    {
        cout << endl;
        cout << "Account with AccId '" << accId << "' not found in the database." << endl;
        remove("temp.txt");
        system("pause");
        return;
    }

    if (remove("Client Database.txt") != 0)
    {
        cerr << "Error: Unable to delete original database file." << endl;
        return;
    }

    if (rename("temp.txt", "Client Database.txt") != 0)
    {
        cerr << "Error: Unable to rename temporary file." << endl;
        return;
    }

    cout << endl;
    cout << "Account with AccId '" << accId << "' successfully deleted from the database." << endl;
    system("pause");

    database.clear();
    loadClientsFile(database);
    updateClientsDatabase(database);
}

void deposit(long long& balance)
{
    long long amount;
    cout << endl;
    cout << "Enter the amount to deposit: ";
    cin >> amount;
    if (amount < 50)
    {
        cout << "Minimum deposit amount is 50." << endl;
    }
    else
    {
        balance += amount;
        cout << endl;
        cout << "Deposit successful. Your new balance is: " << balance << endl;
        system("pause");
    }
}

void withdraw(long long& balance)
{
    long long amount;
    cout << endl;
    cout << "Enter the amount to withdraw: ";
    cin >> amount;
    if (amount > balance)
    {
        cout << endl;
        cout << "Insufficient balance." << endl;
        system("pause");
    }
    else if (amount > 15000)
    {
        cout << endl;
        cout << "Maximum withdrawal amount per day is 15000." << endl;
        system("pause");
    }
    else
    {
        balance -= amount;
        cout << endl;
        cout << "Withdrawal successful. Your new balance is: " << balance << endl;
        system("pause");
    }
}

void updateClientsDatabase(vector<Client>& database) {
    ofstream cDatabase("Client Database.txt");
    if (!cDatabase.is_open()) {
        cerr << "Error: Unable to open database file for writing." << endl;
        return;
    }

    for (const auto& client : database) {
        cDatabase << client.AccId << " "
            << client.Fname << " "
            << client.Lname << " "
            << client.gender << " "
            << client.NId << " "
            << client.age << " "
            << client.phone << " "
            << client.address << " "
            << client.mail << " "
            << client.balance << " "
            << client.username << " "
            << client.password << endl;
        if (client.AccId.substr(0, 2) != "ST" && client.AccId.substr(0, 2) != "AD")
        {
            continue;
        }
    }

    cDatabase.close();
}

void transfer(vector<Client>& database, Client& sender) 
{
    cout << endl;
    cout << "Enter the Account ID of the recipient: ";
    string recipientAccId;
    cin >> recipientAccId;

    // Search for the recipient in the clients vector
    auto recipientIter = find_if(database.begin(), database.end(), [&](const Client& client) 
        {
        return client.AccId == recipientAccId;
        });

    if (recipientIter != database.end()) 
    {
        // Found the recipient, now proceed with the transfer
        long long transferAmount;
        cout << endl;
        cout << "Enter the amount to transfer: ";
        cin >> transferAmount;

        if (transferAmount > sender.balance) 
        {
            cout << endl;
            cout << "Insufficient balance for transfer." << endl;
            system("pause");
        }
        else 
        {
            sender.balance -= transferAmount;
            recipientIter->balance += transferAmount;
            cout << endl;
            cout << "Transfer successful. Your new balance is: " << sender.balance << endl;
            system("pause");
        }
    }
    else 
    {
        cout << endl;
        cout << "Recipient not found." << endl;
        system("pause");
    }
}

void clientTransactions(Client& client, vector<Client>& database) 
{
    cout << endl;
    int choice;
    do 
    {
        cout << endl;
        cout << "Client Transactions\n";
        cout << endl;
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer to another client\n";
        cout << "4. Return to main menu\n";
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            deposit(client.balance);
            updateClientsDatabase(database); // Update the database after deposit
            break;
        case 2:
            withdraw(client.balance);
            updateClientsDatabase(database); // Update the database after withdrawal
            break;
        case 3:
            transfer(database, client);
            updateClientsDatabase(database); // Update the database after transfer
            break;
        case 4:
            cout << "Returning to main menu..." << endl;
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

        // Ask the user if they want to perform another transaction
        char anotherTransaction;
        cout << "\nDo you want to perform another transaction? (Y/N): ";
        cin >> anotherTransaction;
        if (toupper(anotherTransaction) != 'Y' || anotherTransaction != 'y')
        {
            break; // Exit the loop if the user does not want to continue
        }

        // Clear input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (true);
}

void searchClient(vector<Client>& database, const string& searchID) {
    bool found = false;
    for (auto& client : database) {
        if (client.AccId == searchID && client.AccId.substr(0, 2) != "AD" && client.AccId.substr(0, 2) != "ST") {
            found = true;
            system("cls"); // Clear console screen
            cout << "\nClient found:\n";
            cout << endl;
            cout << "AccID      First Name   Last Name    Gender       NationalID        Age          Phone                 Address                 Mail                 Balance " << endl;
            cout << "============================================================================================================================================================" << endl;
            cout << endl;
            cout << client.AccId << "  "
                << setw(11) << client.Fname << "  "
                << setw(12) << client.Lname << "  "
                << setw(8) << client.gender << "  "
                << setw(18) << client.NId << "  "
                << setw(6) << client.age << "  "
                << setw(17) << client.phone << "  "
                << setw(19) << client.address << "  "
                << setw(25) << client.mail << "  "
                << setw(17) << client.balance << "  " << endl;

            // Call clientTransactions function for this client
            clientTransactions(client, database); // Pass the clients vector as the second argument
            break; // Exit the loop once the client is found
        }
    }
    cout << endl;
    if (!found) {
        cout << "Client not found." << endl;
    }
    system("pause"); // Pause console screen
    system("cls");
}

void stuffMenu(vector<Client>& database)
{
    bool loggedIn = stuffLogin(database);

    if (!loggedIn) 
    {
        return;
    }

    int choice;
    do
    {
        system("cls");
        cout << "================================================================\n";
        cout << "======================= Stuff's Portion ========================\n";
        cout << "================================================================\n";
        cout << endl;
        cout << "1. Search for a specific client by ID\n";
        cout << "2. Add a new account\n";
        cout << "3. Delete an account\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string searchID;
            cout << endl;
            cout << "Enter the AccID of the client you want to search for: ";
            cin >> searchID;
            searchClient(database, searchID);
            break;
        }
        case 2:
            addNewAccount(database);
            break;
        case 3:
        {
            string AccIdDelete;
            cout << endl;
            cout << "Enter the AccID of the account you want to delete: ";
            cin >> AccIdDelete;
            stuffDeleteClientAccount(AccIdDelete, database);
            break;
        }
        case 4:
            system("cls");
            cout << "Exiting Stuff menu..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            system("pause");
            break;
        }
    } while (choice != 4);
}

void stuffMain()
{
    vector<Client> database;
    allLoadFunction(database);
    stuffMenu(database);

    system("pause");
    system("cls");
}

void displayClientDetails(const Client& database) 
{
    cout << "\nClient details:\n";
    cout << "First Name: " << database.Fname << endl;
    cout << "Last Name: " << database.Lname << endl;
    cout << "Gender: " << database.gender << endl;
    cout << "Address: " << database.address << endl;
    cout << "Mail: " << database.mail << endl;
    cout << "Account ID: " << database.AccId << endl;
    cout << "National ID: " << database.NId << endl;
    cout << "Age: " << database.age << endl;
    cout << "Phone: " << database.phone << endl;
    cout << "Balance: " << database.balance << endl;
}

void clientMenu(vector<Client>& database, size_t loggedInClientIndex)
{
    int choice;
    if (loggedInClientIndex >= database.size())
    {
        cout << "Invalid client index. Exiting menu." << endl;
        return;
    }

    char anotherTransaction;
    do
    {
        system("cls");
        cout << "================================================================\n";
        cout << "======================= Client's Portion =======================\n";
        cout << "================================================================\n";
        cout << endl;
        cout << "1. Transfer to another client\n";
        cout << "2. Show your account details\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            transfer(database, database[loggedInClientIndex]);
            updateClientsDatabase(database);
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            displayClientDetails(database[loggedInClientIndex]);
            system("pause");
            break;
        }
        case 3:
            system("cls");
            cout << "Exiting Customer menu..." << endl;
            system("cls");
            return; 
        default:
            cout << "Invalid choice. Please try again." << endl;
            system("pause");
            break;
        }

        system("cls");
    } while (choice != 3);
}

void clientMain()
{
    vector<Client> database;
    allLoadFunction(database);
    if (!database.empty())
    {
        size_t loggedInClientIndex;

        if (clientLogin(database, loggedInClientIndex)) 
        {
            clientMenu(database, loggedInClientIndex);
            system("pause");
        }
        else 
        {
            cout << "Login failed." << endl;
            system("pause");
        }
    }
}

void mainScreen()
{
    messagesLoad();

    int choice;
    do
    {
        system("cls");
        cout << "================================================================\n";
        cout << "===================== Bank Mangement System ====================\n";
        cout << "================================================================\n";

        cout << "1. Admin's Portion\n";
        cout << "2. Stuff's Portion\n";
        cout << "3. Client's Portion\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("cls");
            cout << "================================================================\n";
            cout << "======================= Admin's Portion ========================\n";
            cout << "================================================================\n";
            cout << endl;
            adminMain();
            break;
        }
        case 2:
        {
            system("cls");
            cout << "================================================================\n";
            cout << "======================= Stuff's Portion ========================\n";
            cout << "================================================================\n";
            cout << endl;
            stuffMain();
            break;
        }
        case 3:
        {
            system("cls");
            cout << "================================================================\n";
            cout << "======================= Client's Portion =======================\n";
            cout << "================================================================\n";
            cout << endl;
            clientMain();
            break;
        }
        case 4:
            system("cls");
            cout << "Thanks for using Bank Management System..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            system("pause");
            break;
        }
    } while (choice != 4);
}

int main()
{
    mainScreen();

    return 0;
}