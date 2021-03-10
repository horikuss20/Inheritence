#include <iostream>
#include "BaseAccount.h"
#include "CheckingAccount.h"
#include "CreditAccount.h"
#include "SavingsAccount.h"
#include <fstream>

CheckingAccount ca;
SavingsAccount sa;
CreditAccount cra;

void SaveData();
void LoadData();

int main()
{
    bool refresh = true;
    LoadData();
    while (refresh)
    {
        std::cout << '\t' << "Welcome to Palpatine's Intergalatic Bank. Open an account today! |DO IT|" << std::endl;
        int userinput = 0;
        while (true)
        {
            std::cout << "Please select an account to access." << std::endl;
            std::cout << "1) Checking Account" << std::endl;
            std::cout << "2) Savings Account" << std::endl;
            std::cout << "3) Credit Account" << std::endl;

            userinput = 0;
            std::cin >> userinput;
            if (std::cin.fail() || userinput > 3 || userinput < 1)
            {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "Please input a valid integer selection." << std::endl;
                continue;
            }
            std::cin.clear();
            break;
        }

        bool deposit = false;

#pragma region Checking
        if (userinput == 1)
        {
            while (true)
            {
                userinput = 0;
                std::cout << "1) Deposit" << std::endl;
                std::cout << "2) Withdraw" << std::endl;
                std::cin >> userinput;
                if (std::cin.fail() || userinput > 2 || userinput < 1)
                {
                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                    std::cout << "Please input a valid integer selection." << std::endl;
                    continue;
                }
                else if (userinput == 1)
                {
                    deposit = true;
                }
                std::cin.clear();
                break;
            }
            float userfloat = 0;
            if (deposit)
            {
                std::cout << "How much would you like to deposit?" << std::endl;
                while (true)
                {
                    std::cin >> userfloat;
                    if (std::cin.fail() || userfloat < .01)
                    {
                        std::cin.clear();
                        std::cin.ignore(INT_MAX, '\n');
                        std::cout << "Please input a valid number." << std::endl;
                        continue;
                    }
                    else ca.Deposit(userfloat);
                    std::cout << "You have deposited " << userfloat << "." << std::endl;
                    std::cout << "Your balance is " << ca.GetBalance() << std::endl;
                    break;
                }
            }
            else
            {
                std::cout << "How much would you like to withdraw?" << std::endl;
                while (true)
                {
                    std::cin >> userfloat;
                    if (std::cin.fail() || userfloat < .01)
                    {
                        std::cin.clear();
                        std::cin.ignore(INT_MAX, '\n');
                        std::cout << "Please input a valid number." << std::endl;
                        continue;
                    }
                    else
                    {   ca.Withdraw(userfloat);
                    if (ca.GetBalance() - userfloat > 0)
                    {
                        std::cout << "You have withdrawn " << userfloat << "." << std::endl;
                    }
                    }
                    std::cout << "Your balance is " << ca.GetBalance() << std::endl;
                    break;
                }
            }
            std::cin.clear();
            SaveData();
        }
#pragma endregion
#pragma region Savings
        if (userinput == 2)
        {
            while (true)
            {
                userinput = 0;
                std::cout << "1) Deposit" << std::endl;
                std::cout << "2) Withdraw" << std::endl;
                std::cin >> userinput;
                if (std::cin.fail() || userinput > 2 || userinput < 1)
                {
                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                    std::cout << "Please input a valid integer selection." << std::endl;
                    continue;
                }
                else if (userinput == 1)
                {
                    deposit = true;
                }
                std::cin.clear();
                break;
            }
            float userfloat = 0;
            if (deposit)
            {
                std::cout << "How much would you like to deposit?" << std::endl;
                while (true)
                {
                    std::cin >> userfloat;
                    if (std::cin.fail() || userfloat < .01)
                    {
                        std::cin.clear();
                        std::cin.ignore(INT_MAX, '\n');
                        std::cout << "Please input a valid number." << std::endl;
                        continue;
                    }
                    else sa.Deposit(userfloat);
                    std::cout << "You have deposited " << userfloat << "." << std::endl;
                    std::cout << "Your balance is " << sa.GetBalance() << std::endl;
                    break;
                }
            }
            else
            {
                std::cout << "How much would you like to withdraw?" << std::endl;
                while (true)
                {
                    std::cin >> userfloat;
                    if (std::cin.fail() || userfloat < .01)
                    {
                        std::cin.clear();
                        std::cin.ignore(INT_MAX, '\n');
                        std::cout << "Please input a valid number." << std::endl;
                        continue;
                    }
                    else
                    {
                        sa.Withdraw(userfloat);
                        if (sa.GetBalance() - userfloat > 0)
                        {
                            std::cout << "You have withdrawn " << userfloat << "." << std::endl;
                        }
                    }
                    std::cout << "Your balance is " << sa.GetBalance() << std::endl;
                    break;
                }
            }
            std::cin.clear();
            SaveData();
        }
#pragma endregion
#pragma region Credit
        if (userinput == 3)
        {
            while (true)
            {
                userinput = 0;
                std::cout << "1) Deposit" << std::endl;
                std::cout << "2) Withdraw" << std::endl;
                std::cin >> userinput;
                if (std::cin.fail() || userinput > 2 || userinput < 1)
                {
                    std::cin.clear();
                    std::cin.ignore(INT_MAX, '\n');
                    std::cout << "Please input a valid integer selection." << std::endl;
                    continue;
                }
                else if (userinput == 1)
                {
                    deposit = true;
                }
                std::cin.clear();
                break;
            }
            float userfloat = 0;
            if (deposit)
            {
                std::cout << "How much would you like to deposit?" << std::endl;
                while (true)
                {
                    std::cin >> userfloat;
                    if (std::cin.fail() || userfloat < .01)
                    {
                        std::cin.clear();
                        std::cin.ignore(INT_MAX, '\n');
                        std::cout << "Please input a valid number." << std::endl;
                        continue;
                    }
                    else cra.Deposit(userfloat);
                    std::cout << "You have deposited " << userfloat << "." << std::endl;
                    std::cout << "Your balance is " << cra.GetBalance() << std::endl;
                    break;
                }
            }
            else
            {
                std::cout << "How much would you like to withdraw?" << std::endl;
                while (true)
                {
                    std::cin >> userfloat;
                    if (std::cin.fail() || userfloat < .01)
                    {
                        std::cin.clear();
                        std::cin.ignore(INT_MAX, '\n');
                        std::cout << "Please input a valid number." << std::endl;
                        continue;
                    }
                    else
                    {
                        cra.Withdraw(userfloat);
                        if (cra.GetBalance() - userfloat > 0)
                        {
                            std::cout << "You have withdrawn " << userfloat << "." << std::endl;
                        }
                    }
                    std::cout << "Your balance is " << cra.GetBalance() << std::endl;
                    break;
                }
            }
            std::cin.clear();
            SaveData();
        }
#pragma endregion
        char charinput; "";
        std::cout << "Would you like to make another transaction? (Y)es or (N)o" << std::endl;
        while (true)
        {
            std::cin >> charinput;
            if (std::cin.fail() || (charinput != 'y' && charinput != 'Y' && charinput != 'n' && charinput != 'N'))
            {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "Please input Y or N to close the application or make another transaction." << std::endl;
                continue;
            }
            else if (charinput == 'n' || charinput == 'N')
            {
                refresh = false;
            }
            break;
        }
    }
}

void SaveData()
{
    std::ofstream oFile;
#pragma once
    oFile.open("bankdata.txt");
    if (!oFile.is_open()) { return;  }

    //checking account = 1
    // balance
    oFile << "1\t" << ca.GetBalance() << '\n';
    //savings account = 2
    oFile << "2\t" << sa.GetBalance() << '\n';
    //credit account = 3
    oFile << "3\t" << cra.GetBalance() << '\n';
    oFile.close();
}

void LoadData()
{
    int accounttype;
    std::ifstream iFile;
    iFile.open("bankdata.txt");
    if (!iFile.is_open()) { return; }
    while (true)
    {
        iFile >> accounttype;
        iFile.ignore(INT_MAX, '\t');
        switch (accounttype)
        {
        case 1: //checking account
        {
            float balance;
            iFile >> balance;
            ca.Deposit(balance);
            break;
        }
        case 2: //savings account
        {
            float balance;
            iFile >> balance;
            sa.Deposit(balance);
            break;
        }
        case 3: //credit account
        {
            float balance;
            iFile >> balance;
            cra.Deposit(balance);
            break;
        }
        default:
            break;
        }
        iFile.ignore(INT_MAX, '\n');
        if (iFile.eof())
        {
            break;
        }
    }
    iFile.close();
}