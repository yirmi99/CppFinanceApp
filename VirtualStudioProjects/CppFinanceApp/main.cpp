#include <iostream>
#include "winapp/FinanceApp/FinanceApp.h"

int main() {
    FinanceApp app;

    // add some test transactions
    app.addTransaction("Groceries", -50.75, "Food");
    app.addTransaction("Salary", 2500.00, "Income");
    app.addTransaction("Gas", -40.00, "Transport");
    app.addTransaction("Movie Ticket", -15.00, "Entertainment");

    // display transactions
    std::cout << "\n=== All Transactions ===\n";
    app.displayAllTransactions();

    // display total balance
    std::cout << "\nTotal Balance: " << app.getTotalBalance() << "\n";

    // remove a transaction
    std::cout << "\nRemoving transaction 2 (Salary)...\n";
    app.removeTransaction(1);

    // display transactions again
    std::cout << "\n=== Transactions After Removal ===\n";
    app.displayAllTransactions();
    std::cout << "\nUpdated Balance: " << app.getTotalBalance() << "\n";

    return 0;
}
