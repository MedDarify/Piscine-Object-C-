#include "bank.hpp"



int main()
{
	try
	{
		Bank bank(1000);
		Account* accountA = bank.createAccount(100);
		Account* accountB = bank.createAccount(100);
		Account* accountC =  bank.createAccount(1500);

		
		bank.deposit(*accountA, 1400);
		bank.giveLoan(*accountB, 200);
		bank.withdraw(*accountA, 50);

		std::cout << "------ Accounts -------" << std::endl;
		std::cout << *accountA << std::endl;
		std::cout << *accountB << std::endl;
		std::cout << *accountC << std::endl;

		std::cout << "----- bank before delete -----" << std::endl;
		std::cout << bank << std::endl;
		std::cout << "----- bank after delete -----" << std::endl;
		bank.deleteAccountById(1);
		bank.deleteAccountById(3);
		std::cout << bank << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
};