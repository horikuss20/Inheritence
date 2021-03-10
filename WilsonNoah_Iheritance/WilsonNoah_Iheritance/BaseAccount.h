#pragma once
class BaseAccount
{
private:
	float balance = 0;

protected: 
	int withdrawals = 0;

public:
	virtual void Withdraw(float amount) = 0;
	void Deposit(float amount);
	float GetBalance() const;
};

