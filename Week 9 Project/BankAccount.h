#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <exception>
#include <iostream>

class InsufficientFunds : public std::exception {
public:
    // Exception message for insufficient funds
    const char* what() const noexcept override {
        return "Error: Insufficient funds for this withdrawal.";
    }
};

class NegativeDeposit : public std::exception {
public:
    // Exception message for negative deposits
    const char* what() const noexcept override {
        return "Error: Deposit amount cannot be negative.";
    }
};

class BankAccount {
private:
    double balance;
    std::string accountNumber;

public:
    // Constructor to initialize account with account number and initial balance
    BankAccount(std::string accNo, double initialBalance);

    // Function to withdraw money, throws InsufficientFunds exception if balance is insufficient
    void withdraw(double amount);

    // Function to deposit money, throws NegativeDeposit exception if amount is negative
    void deposit(double amount);

    // Function to get the current balance of the account
    double getBalance() const;
};

#endif // BANKACCOUNT_H
