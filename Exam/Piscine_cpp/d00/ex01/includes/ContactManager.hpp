#ifndef CONTACTMANAGER_HPP
# define CONTACTMANAGER_HPP

# include "Contact.hpp"

# define MAX_CONTACT 8

class CContactManager
{
private:
	CContact	m_Contacts[MAX_CONTACT];

	void DisplayTruncString(std::string p_pString) const;

public:
	CContactManager(void);
	~CContactManager(void);

	void ProcessCommand(void);
	void Add(void);
	void Search(void);
	void Exit(void);
};

#endif /* !CONTACTMANAGER_HPP */
