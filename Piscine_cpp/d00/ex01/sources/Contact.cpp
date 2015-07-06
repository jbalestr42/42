/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 13:08:33 by jbalestr          #+#    #+#             */
/*   Updated: 2015/01/05 17:56:11 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

int CContact::ms_nNbContact = 0;

CContact::CContact(void)
	:m_pFirstName(""),
	m_pLastName(""),
	m_pNickname(""),
	m_pLogin(""),
	m_pPostalAddress(""),
	m_pEmailAddress(""),
	m_pPhoneNumber(""),
	m_pBirthday(""),
	m_pFavoriteMeal(""),
	m_pUnderwearColor(""),
	m_pDarkestSecret("")
{

}

CContact::~CContact(void)
{

}

void CContact::Init(void)
{
	ms_nNbContact++;
	std::string Input;

	std::cout << "First Name:" << std::endl;
	std::cin >> Input;
	this->setFirstName(Input);
	std::cout << "Last Name:" << std::endl;
	std::cin >> Input;
	this->setLastName(Input);
	std::cout << "Nickname:" << std::endl;
	std::cin >> Input;
	this->setNickname(Input);
	std::cout << "Login:" << std::endl;
	std::cin >> Input;
	this->setLogin(Input);
	std::cout << "Postal Address:" << std::endl;
	std::cin >> Input;
	this->setPostalAddress(Input);
	std::cout << "Email Address:" << std::endl;
	std::cin >> Input;
	this->setEmailAddress(Input);
	std::cout << "Phone Number:" << std::endl;
	std::cin >> Input;
	this->setPhoneNumber(Input);
	std::cout << "Birthday:" << std::endl;
	std::cin >> Input;
	this->setBirthday(Input);
	std::cout << "Favorite Meal:" << std::endl;
	std::cin >> Input;
	this->setFavoriteMeal(Input);
	std::cout << "Underwear Color:" << std::endl;
	std::cin >> Input;
	this->setUnderwearColor(Input);
	std::cout << "Darkest Secret:" << std::endl;
	std::cin >> Input;
	this->setDarkestSecret(Input);
}

void CContact::setFirstName(std::string p_Value)
{
	this->m_pFirstName = p_Value;
}

void CContact::setLastName(std::string p_Value)
{
	this->m_pLastName = p_Value;
}

void CContact::setNickname(std::string p_Value)
{
	this->m_pNickname = p_Value;
}

void CContact::setLogin(std::string p_Value)
{
	this->m_pLogin = p_Value;
}

void CContact::setPostalAddress(std::string p_Value)
{
	this->m_pPostalAddress = p_Value;
}

void CContact::setEmailAddress(std::string p_Value)
{
	this->m_pEmailAddress = p_Value;
}

void CContact::setPhoneNumber(std::string p_Value)
{
	this->m_pPhoneNumber = p_Value;
}

void CContact::setBirthday(std::string p_Value)
{
	this->m_pBirthday = p_Value;
}

void CContact::setFavoriteMeal(std::string p_Value)
{
	this->m_pFavoriteMeal = p_Value;
}

void CContact::setUnderwearColor(std::string p_Value)
{
	this->m_pUnderwearColor = p_Value;
}

void CContact::setDarkestSecret(std::string p_Value)
{
	this->m_pDarkestSecret = p_Value;
}

std::string CContact::getFirstName(void) const
{
	return this->m_pFirstName;
}

std::string CContact::getLastName(void) const
{
	return this->m_pLastName;
}

std::string CContact::getNickname(void) const
{
	return this->m_pNickname;
}

std::string CContact::getLogin(void) const
{
	return this->m_pLogin;
}

std::string CContact::getPostalAddress(void) const
{
	return this->m_pPostalAddress;
}

std::string CContact::getEmailAddress(void) const
{
	return this->m_pEmailAddress;
}

std::string CContact::getPhoneNumber(void) const
{
	return this->m_pPhoneNumber;
}

std::string CContact::getBirthday(void) const
{
	return this->m_pBirthday;
}

std::string CContact::getFavoriteMeal(void) const
{
	return this->m_pFavoriteMeal;
}

std::string CContact::getUnderwearColor(void) const
{
	return this->m_pUnderwearColor;
}

std::string CContact::getDarkestSecret(void) const
{
	return this->m_pDarkestSecret;
}

int CContact::getNbInstance(void)
{
	return CContact::ms_nNbContact;
}

void CContact::Display(void) const
{
	std::cout << std::left << std::setw(17) << "First Name: " << this->m_pFirstName << std::endl;
	std::cout << std::setw(17) << "LastName: " << this->m_pLastName << std::endl;
	std::cout << std::setw(17) << "Nickname: " << this->m_pNickname << std::endl;
	std::cout << std::setw(17) << "Login: " << this->m_pLogin << std::endl;
	std::cout << std::setw(17) << "Postal Address: " << this->m_pPostalAddress << std::endl;
	std::cout << std::setw(17) << "Email Address: " << this->m_pEmailAddress << std::endl;
	std::cout << std::setw(17) << "Phone Number: " << this->m_pPhoneNumber << std::endl;
	std::cout << std::setw(17) << "Birthday: " << this->m_pBirthday << std::endl;
	std::cout << std::setw(17) << "Favorite Meal: " << this->m_pFavoriteMeal << std::endl;
	std::cout << std::setw(17) << "Underwear Color: " << this->m_pUnderwearColor << std::endl;
	std::cout << std::setw(17) << "Darkest Secret: " << this->m_pDarkestSecret << std::endl;
}

