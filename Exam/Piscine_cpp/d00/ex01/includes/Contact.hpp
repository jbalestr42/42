/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 12:56:20 by jbalestr          #+#    #+#             */
/*   Updated: 2015/01/05 17:56:11 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class CContact
{
private:
	std::string m_pFirstName;
	std::string m_pLastName;
	std::string m_pNickname;
	std::string m_pLogin;
	std::string m_pPostalAddress;
	std::string m_pEmailAddress;
	std::string m_pPhoneNumber;
	std::string m_pBirthday;
	std::string m_pFavoriteMeal;
	std::string m_pUnderwearColor;
	std::string m_pDarkestSecret;
	static int ms_nNbContact;

public:
	CContact(void);
	~CContact(void);

	void Init(void);
	void Display(void) const;

	void setFirstName(std::string p_Value);
	void setLastName(std::string p_Value);
	void setNickname(std::string p_Value);
	void setLogin(std::string p_Value);
	void setPostalAddress(std::string p_Value);
	void setEmailAddress(std::string p_Value);
	void setPhoneNumber(std::string p_Value);
	void setBirthday(std::string p_Value);
	void setFavoriteMeal(std::string p_Value);
	void setUnderwearColor(std::string p_Value);
	void setDarkestSecret(std::string p_Value);

	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;
	std::string getLogin(void) const;
	std::string getPostalAddress(void) const;
	std::string getEmailAddress(void) const;
	std::string getPhoneNumber(void) const;
	std::string getBirthday(void) const;
	std::string getFavoriteMeal(void) const;
	std::string getUnderwearColor(void) const;
	std::string getDarkestSecret(void) const;
	static int getNbInstance(void);

};

#endif /* !CONTACT_HPP */
