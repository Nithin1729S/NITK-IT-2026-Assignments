#include <iostream>
#include <string>

class Account;

void display_info(const Account &account);

class Account
{
private:
    std::string accountHolderName;
    long accountNumber;
    double balance;

public:
    Account(const std::string &name, long number, double initialBalance)
        : accountHolderName(name), accountNumber(number), balance(initialBalance) {}

    void display_balance() const
    {
        std::cout << "Account Balance: $" << balance << std::endl;
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            std::cout << "Withdrawal successful. Remaining balance: $" << balance << std::endl;
        }
        else
        {
            std::cout << "Invalid withdrawal amount or insufficient balance." << std::endl;
        }
    }

    friend void display_info(const Account &account);
};

void display_info(const Account &account)
{
    std::cout << "Account Holder Name: " << account.accountHolderName << std::endl;
    std::cout << "Account Number: " << account.accountNumber << std::endl;
    account.display_balance();
}

int main()
{

    std::string name;
    long number;
    double initialBalance;

    std::cout << "Enter Account Holder Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Account Number: ";
    std::cin >> number;

    std::cout << "Enter Initial Balance: $";
    std::cin >> initialBalance;

    Account myAccount(name, number, initialBalance);

    display_info(myAccount);

    double withdrawalAmount;
    std::cout << "Enter Withdrawal Amount: $";
    std::cin >> withdrawalAmount;

    myAccount.withdraw(withdrawalAmount);

    display_info(myAccount);

    return 0;
}
