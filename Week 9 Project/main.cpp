#include "BankAccount.h"

void processWithdrawal(BankAccount& account, double amount) {
    // Function to handle withdrawal; exception may propagate from here
    account.withdraw(amount);
}

int main() {
    try {
        // Create a BankAccount object with account number and initial balance
        BankAccount myAccount("12345", 100.0);

        // Output the initial balance
        std::cout << "Initial balance: $" << myAccount.getBalance() << std::endl;

        // Test deposit
        myAccount.deposit(50);
        std::cout << "Current balance after deposit: $" << myAccount.getBalance() << std::endl;

        // Test withdrawal that will fail due to insufficient funds
        processWithdrawal(myAccount, 200);  // Will throw InsufficientFunds

    } catch (const InsufficientFunds& e) {
        // Handle insufficient funds exception
        std::cout << e.what() << std::endl;
    } catch (const NegativeDeposit& e) {
        // Handle negative deposit exception
        std::cout << e.what() << std::endl;
    } catch (...) {
        // Generic catch block to handle any other unexpected exceptions
        std::cout << "An unexpected error occurred." << std::endl;
    }

    std::cout << "Program completed." << std::endl;
    return 0;
}
