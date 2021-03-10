#include "CreditAccount.h"
#include <iostream>
void CreditAccount::Withdraw(float amount)
{
	if ((BaseAccount::GetBalance() - amount) > 0)
	{
		CreditAccount::spent += amount;
		if (spent > 40)
		{
			BaseAccount::Withdraw(amount + 5000);
		}
		else BaseAccount::Withdraw(amount);
	}
	else std::cout << "The withdraw amount is too great." << std::endl;
}