#ifndef FACTORY_HPP
# define FACTORY_HPP

# include "IOperand.hpp"
# include <functional>
# include <memory>

class Factory
{
public:
	~Factory(void) = default;

	static Factory & getInstance(void);
	IOperand const * createOperand(eOperandType type, std::string const & value) const;

private:
	typedef std::function<IOperand const *(std::string const &)>	CreateOperand;

	static std::unique_ptr<Factory>	m_instance;
	CreateOperand					m_createOperands[5];

	Factory(void);
	Factory(Factory const & factory);
	Factory & operator=(Factory const & factory);
	IOperand const * createInt8(std::string const & value) const;
	IOperand const * createInt16(std::string const & value) const;
	IOperand const * createInt32(std::string const & value) const;
	IOperand const * createFloat(std::string const & value) const;
	IOperand const * createDouble(std::string const & value) const;
	template<class T>
	void checkValue(std::string const & value) const;

};

#endif
