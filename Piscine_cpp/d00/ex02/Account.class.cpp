/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 18:05:48 by jbalestr          #+#    #+#             */
/*   Updated: 2015/01/05 19:25:19 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
	:_accountIndex(0),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	Account::_nbAccounts++;
}

Account::Account(int p_initial_deposit)
	:_accountIndex(0),
	_amount(p_initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_accountIndex = Account::_nbAccounts;

	Account::_nbAccounts++;
	Account::_totalAmount += p_initial_deposit;
	Account::_displayTimestamp();
	Account::displayStatus();
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::makeDeposit(int p_deposit)
{
	(void)p_deposit;
}

bool Account::makeWithdrawal(int p_withdrawal)
{
	(void)p_withdrawal;
	return true;
}

int Account::checkAmount(void) const
{
	return 0;
}

void Account::displayStatus(void) const
{
	static int nStatuc = 0;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
	nStatus++;
}

// Static functions
void Account::_displayTimestamp(void)
{
	std::cout << "[timestamp] ";
}

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}
