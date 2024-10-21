#include "BankAccount.h"

// Constructor to initialize BankAccount
BankAccount::BankAccount(std::string accNo, double initialBalance)
    : accountNumber(accNo), balance(initialBalance) {}

// Function to withdraw amount; throws InsufficientFunds exception if amount exceeds balance
void BankAccount::withdraw(double amount) {
    if (amount > balance) {
        throw InsufficientFunds(); // Throw exception if insufficient funds
    }
    balance -= amount;
    std::cout << "Successfully withdrew: $" << amount << std::endl;
}

// Function to deposit amount; throws NegativeDeposit exception if amount is negative
void BankAccount::deposit(double amount) {
    if (amount < 0) {
        throw NegativeDeposit(); // Throw exception if deposit is negative
    }
    balance += amount;
    std::cout << "Successfully deposited: $" << amount << std::endl;
}

// Function to return the current balance
double BankAccount::getBalance() const {
    return balance;
}
