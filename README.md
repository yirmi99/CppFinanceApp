# Personal Finance Tracker

**Personal Finance Tracker** is a C++ project designed to help users track their personal finances, including adding and removing transactions (income and expenses), updating the balance, and saving data to a file. This project uses the **SFML** library for the graphical user interface (GUI).

## Features

- **Add Transactions**: Users can add income and expense transactions.
- **Remove Last Transaction**: Users can remove the last added transaction.
- **Balance Tracking**: The balance is automatically updated with each transaction.
- **Data Persistence**: All transactions are saved to a file (`transactions.txt`) and are automatically loaded when the program starts.
- **Graphical User Interface (GUI)**: The program uses SFML for a simple and intuitive user interface, allowing users to interact with the application easily.

## Setup and Installation

### Prerequisites
Make sure you have the following installed:
- **C++ Compiler** (G++ recommended)
- **SFML Library** for graphics, window handling, and input (you can install SFML via Homebrew on macOS with `brew install sfml`)

### Installation Instructions

1. Clone the repository:

   ```bash
   git clone https://github.com/yirmi99/CppFinanceApp.git
   ```

2. Navigate to the project folder:

   ```bash
   cd Personal-Finance-Tracker
   ```

3. Compile the project with G++:

   ```bash
   g++ -std=c++17 main.cpp -o financeTracker -I/usr/local/include -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system
   ```

4. Run the program:

   ```bash
   ./financeTracker
   ```

## How It Works?

- **Adding Transactions**: Users can add a new transaction by entering a description and an amount. The transaction is stored in the `transactions` vector and the balance is updated accordingly.
  
- **Removing Transactions**: Users can remove the most recent transaction. The balance is updated and the transaction is removed from the vector.

- **Displaying Balance**: The balance is automatically updated when transactions are added or removed and is displayed on the screen in real time.

- **Saving and Loading Data**: The transactions are saved in a file (`transactions.txt`). When the program starts, it loads the transactions from the file to restore the previous state.

## Usage

1. When you open the application, you will see a graphical interface with input fields for the description and amount of transactions.
2. Click **"Add Transaction"** to add a new transaction.
3. The **balance** will update automatically based on the added transactions.
4. You can also **remove the last transaction** using the **"Remove Last Transaction"** button.
5. All data is saved to **`transactions.txt`** and is loaded automatically when you restart the program.

