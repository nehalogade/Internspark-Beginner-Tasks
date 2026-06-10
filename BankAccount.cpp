#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    void createAccount()
    {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cin.ignore();
        cout << "Enter Account Holder Name: ";
        getline(cin, accountHolder);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void deposit()
    {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;

        balance += amount;
        cout << "Rs. " << amount << " deposited successfully.\n";
    }

    void withdraw()
    {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount <= balance)
        {
            balance -= amount;
            cout << "Rs. " << amount << " withdrawn successfully.\n";
        }
        else
        {
            cout << "Insufficient Balance!\n";
        }
    }
    void displayBalance()
    {
        cout << "\n--- Account Details ---\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << accountHolder << endl;
        cout << "Current Balance: Rs. " << balance << endl;
    }
};
int main()
{
    BankAccount acc;
    int choice;

    acc.createAccount();

    do
    {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            acc.deposit();
            break;

        case 2:
            acc.withdraw();
            break;

        case 3:
            acc.displayBalance();
            break;

        case 4:
            cout << "Thank you!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}