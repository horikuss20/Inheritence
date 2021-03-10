#include "SavingsAccount.h"
#include <iostream>

void SavingsAccount::Withdraw(float amount)
{
	if (withdrawals < 3)
	{
		if (BaseAccount::GetBalance() - amount > 0)
		{
			withdrawals++;
			std::cout << "You have made " << withdrawals << " Withdraws. You are only allowed 3 total withdraws." << std::endl;
			BaseAccount::Withdraw(amount);
		}
		else std::cout << "The withdraw amount is too great." << std::endl;
	}
	else std::cout << "You have made too many withdraws from this account. You are unable to make any more." << std::endl;
}
