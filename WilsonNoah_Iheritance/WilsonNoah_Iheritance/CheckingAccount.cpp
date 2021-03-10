#include "CheckingAccount.h"
#include <iostream>

void CheckingAccount::Withdraw(float amount)
{
	if ((BaseAccount::GetBalance() - amount) > 0)
	{
		withdrawals++;
		std::cout << "You have made " << withdrawals << " withdraws. Anything above 10 will ellicit a 5$ fee." << std::endl;
		if (CheckingAccount::withdrawals > 10)
		{
			BaseAccount::Withdraw(amount + 5);
		}
		else BaseAccount::Withdraw(amount);
	}
	else std::cout << "The withdraw amount is too great." << std::endl;
}