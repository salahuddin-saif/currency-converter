# 💱 Currency Converter

A simple yet functional currency converter program written in C that allows users to convert between multiple currencies with real-time exchange rates.

## 📋 Description

This Currency Converter is a console-based application that provides a user-friendly interface for performing currency conversions. The program features a menu-driven system that allows users to choose from five different currency conversion options or exit the program. It's designed to be simple, efficient, and easy to use for basic currency conversion needs.

## ✨ Features

- **Multiple Currency Pairs**: Supports 5 different currency conversion options
- **Interactive Menu System**: Easy-to-navigate interface with clear options
- **Two-Way Conversions**: Supports conversion in both directions for USD/BDT and BDT/AUD
- **Input Validation**: Handles invalid choices gracefully
- **Continuous Operation**: Allows multiple conversions without restarting
- **Clean Output Format**: Displays results with 2 decimal places for better readability

## 🔄 Conversion Options

| Option | Conversion | Exchange Rate |
|--------|------------|---------------|
| 1 | USD → BDT | 1 USD = 108 BDT |
| 2 | BDT → USD | 1 BDT = 0.00926 USD |
| 3 | USD → EUR | 1 USD = 0.95 EUR |
| 4 | AUD → BDT | 1 AUD = 85.09 BDT |
| 5 | BDT → AUD | 1 BDT = 0.012 AUD |

## 🚀 How to Use

1. **Run the program**
   ```bash
   ./currency_converter

## Example Session
 ```bash
   =============================
       CURRENCY CONVERTER      
=============================

Choose Conversion:
1. USD to BDT
2. BDT to USD
3. USD to EUR
4. AUD to BDT
5. BDT to AUD
0. Exit
Enter your choice: 1
Enter the amount: 100
100.00 USD = 10800.00 BDT 
