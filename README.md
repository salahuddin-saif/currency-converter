# 💱 Currency Converter Management System

A complete console-based currency converter program written in **C++** that allows both users and admins to manage and perform currency conversions with multiple currencies. The system includes user registration, login, conversion history tracking, and an interactive, stylish interface.

## 📋 Description

This Currency Converter is a **console application** with a modern, visually structured interface. It supports multiple currencies, keeps a history of conversions per user, and allows admin access to view all user histories. The program includes a splash screen, a user panel, and an admin panel. Users can register, log in, perform conversions, and track their usage. Admins can view all conversion histories and also use the converter.

## ✨ Features

* **Multiple Currency Support**: USD, BDT, EUR, AUD, SGD, BND
* **Interactive Menu System**: Clear menus for users and admins
* **User Registration/Login**: Each user has an individual account
* **Conversion History**: Tracks total usage per user per conversion
* **Admin Panel**: View full conversion history of all users
* **Stylish UI**: Centered text, color-coded panels (cream for users, blue for admin)
* **Splash Screen**: ASCII art displayed before main menu
* **Input Validation**: Handles invalid conversions and choices gracefully
* **Continuous Operation**: Perform multiple conversions without restarting

## 🔄 Supported Conversions & Rates

| From → To | Rate                |
| --------- | ------------------- |
| USD → BDT | 1 USD = 122.43 BDT  |
| BDT → USD | 1 BDT = 0.00817 USD |
| USD → EUR | 1 USD = 0.87 EUR    |
| EUR → USD | 1 EUR = 1.149 USD   |
| USD → AUD | 1 USD = 1.45 AUD    |
| AUD → USD | 1 AUD = 0.689 USD   |
| USD → SGD | 1 USD = 1.29 SGD    |
| SGD → USD | 1 SGD = 0.775 USD   |
| USD → BND | 1 USD = 1.29 BND    |
| BND → USD | 1 BND = 0.775 USD   |
| BDT → EUR | 1 BDT = 0.0071 EUR  |
| EUR → BDT | 1 EUR = 140.85 BDT  |
| BDT → AUD | 1 BDT = 0.01186 AUD |
| AUD → BDT | 1 AUD = 84.25 BDT   |
| BDT → SGD | 1 BDT = 0.01050 SGD |
| SGD → BDT | 1 SGD = 95.26 BDT   |
| BDT → BND | 1 BDT = 0.01049 BND |
| BND → BDT | 1 BND = 95.29 BDT   |
| EUR → AUD | 1 EUR = 1.67 AUD    |
| AUD → EUR | 1 AUD = 0.598 EUR   |
| EUR → SGD | 1 EUR = 1.48 SGD    |
| SGD → EUR | 1 SGD = 0.676 EUR   |
| EUR → BND | 1 EUR = 1.48 BND    |
| BND → EUR | 1 BND = 0.676 EUR   |
| AUD → SGD | 1 AUD = 0.89 SGD    |
| SGD → AUD | 1 SGD = 1.123 AUD   |
| AUD → BND | 1 AUD = 0.88 BND    |
| BND → AUD | 1 BND = 1.136 AUD   |
| SGD → BND | 1 SGD = 1.0 BND     |
| BND → SGD | 1 BND = 1.0 SGD     |

> All conversions are **calculated using static rates** stored in the program.

## 🚀 How to Use

1. **Compile the program**

```bash
g++ -o currency_converter currency_converter.cpp
```

2. **Run the program**

```bash
./currency_converter
```

3. **Navigate menus**:

   * Admin: username `admin`, password `admin`
   * Users: Register first, then log in

4. **Select currencies and enter amount**. The result is displayed, and conversion history is saved automatically.

5. **View history** (Admin only): Displays all users’ conversion usage.

## 🛠️ Code Structure

1. **Splash Screen**: Displays ASCII art before the program starts.
2. **Global & Page Headers**: Centered headers for UI consistency.
3. **User Panel**: Register/Login, then access user dashboard.
4. **User Dashboard**: Access currency converter or logout.
5. **Admin Panel**: Login with admin credentials, use converter, and view history.
6. **Currency Converter Function**: Handles all conversions and saves history per user.
7. **History Management**: Saves conversion counts per user in `history.txt`.

## 📁 File Structure

```bash
currency-converter/
├── currency_converter.cpp   # Main source code
├── users.txt               # Stores registered users
├── history.txt             # Conversion history per user
└── README.md               # Documentation
```

## 🎯 Future Enhancements

* Add more currencies (GBP, JPY, INR, etc.)
* Integrate live exchange rates via API
* Add graphical UI (Qt, wxWidgets, or console color improvements)
* Allow batch conversion from a file
* Encrypt passwords for secure storage
* Add password reset feature

## 👨‍💻 Author

**MD. Salah Uddin**

## ⭐ Support

If you find this project useful, give it a star on GitHub!
