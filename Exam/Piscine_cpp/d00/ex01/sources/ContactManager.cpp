/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactManager.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 13:29:41 by jbalestr          #+#    #+#             */
/*   Updated: 2015/01/05 19:04:17 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ContactManager.hpp"
#include <iostream>
#include <iomanip>

CContactManager::CContactManager(void)
{

}

CContactManager::~CContactManager(void)
{

}

void CContactManager::ProcessCommand(void)
{
	bool bExit = false;
	std::cout << "Hello !" << std::endl;
	std::cout << "Available commands : ADD, SEARCH, EXIT" << std::endl;

	while (!bExit)
	{
		std::cout << "?> ";
		std::string InputCommand;
		std::cin >> InputCommand;

		if (!InputCommand.compare("EXIT"))
			bExit = true;
		else if (!InputCommand.compare("ADD"))
			this->Add();
		else if (!InputCommand.compare("SEARCH"))
			this->Search();
	}
}

void CContactManager::Add(void)
{
	if (CContact::getNbInstance() >= MAX_CONTACT)
	{
		std::cout << "Too many contacts" << std::endl;
		return;
	}
	m_Contacts[CContact::getNbInstance()].Init();
}

void CContactManager::Search(void)
{
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	for (int i = 0; i < CContact::getNbInstance(); i++)
	{
		std::cout << std::right << std::setw(10) << i << "|";
		this->DisplayTruncString(m_Contacts[i].getFirstName());
		std::cout << "|";
		this->DisplayTruncString(m_Contacts[i].getLastName());
		std::cout << "|";
		this->DisplayTruncString(m_Contacts[i].getNickname());
		std::cout << std::endl;
	}

	std::cout << "Index: " << std::endl;
	std::string Index;
	std::cin >> Index;
	if (Index[0] - '0' >= 0 && Index[0] - '0' < CContact::getNbInstance())
		m_Contacts[Index[0] - '0'].Display();
	else
		std::cout << "Index invalid !" << std::endl;
}

void CContactManager::DisplayTruncString(std::string p_pString) const
{
	int nWidth = p_pString.length() > 10 ? 9 : 10;
	std::cout << std::right << std::setw(nWidth) << p_pString.substr(0, nWidth);
	if (nWidth == 9)
		std::cout << ".";
}

