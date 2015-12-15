#ifndef OPERAND_HPP
# define OPERAND_HPP

# include <sstream>
# include <cmath>
# include "IOperand.hpp"
# include "Factory.hpp"

template<eOperandType T>
class Operand : public IOperand
{
private:
enum Operator
{
	Add,
	Sub,
	Mul,
	Div,
	Mod
};

public:
	Operand(void) :
		m_value("")
	{}

	Operand(std::string const & value) :
		m_value(value)
	{}

	virtual ~Operand(void) {}

	virtual int getPrecision(void) const { return (static_cast<int>(T)); }

	virtual eOperandType getType(void) const { return (T); }

	virtual IOperand const * operator+(IOperand const & rhs) const
	{
		eOperandType type = getPrecision() < rhs.getPrecision() ? rhs.getType() : getType();
		return Factory::getInstance().createOperand(type, getValue(type, rhs, Operator::Add));
	}

	virtual IOperand const * operator-(IOperand const & rhs) const
	{
		eOperandType type = getPrecision() < rhs.getPrecision() ? rhs.getType() : getType();
		return Factory::getInstance().createOperand(type, getValue(type, rhs, Operator::Sub));
	}

	virtual IOperand const * operator*(IOperand const & rhs) const
	{
		eOperandType type = getPrecision() < rhs.getPrecision() ? rhs.getType() : getType();
		return Factory::getInstance().createOperand(type, getValue(type, rhs, Operator::Mul));
	}

	virtual IOperand const * operator/(IOperand const & rhs) const
	{
		eOperandType type = getPrecision() < rhs.getPrecision() ? rhs.getType() : getType();
		return Factory::getInstance().createOperand(type, getValue(type, rhs, Operator::Div));
	}

	virtual IOperand const * operator%(IOperand const & rhs) const
	{
		eOperandType type = getPrecision() < rhs.getPrecision() ? rhs.getType() : getType();
		return Factory::getInstance().createOperand(type, getValue(type, rhs, Operator::Mod));
	}

	virtual std::string const & toString(void) const { return (m_value); }

private:
	std::string		m_value;

	std::string		getValue(eOperandType type, IOperand const & rhs, Operator op) const
	{
		switch (type)
		{
			case eOperandType::Int8:
				return getResult<int8_t>(rhs, op);
				break;
			case eOperandType::Int16:
				return getResult<int16_t>(rhs, op);
				break;
			case eOperandType::Int32:
				return getResult<int32_t>(rhs, op);
				break;
			case eOperandType::Float:
				return getResult<float>(rhs, op);
				break;
			case eOperandType::Double:
				return getResult<double>(rhs, op);
				break;
			default:
				break;
		}
		return "0";
	}

	template<class U>
	std::string		getResult(IOperand const & rhs, Operator op) const
	{
		U u1 = static_cast<U>(std::stod(toString().c_str()));
		U u2 = static_cast<U>(std::stod(static_cast<Operand<eOperandType::Int8> const &>(rhs).toString().c_str()));
		U r;

		switch (op)
		{
			case Operand::Add:
				r = u1 + u2;
				break;
			case Operand::Sub:
				//TODO manage operation between char and not int8
				//quand la chain est 7, elle n'est pas converti en 7, mais en la valeur d'un char représentant 7
				r = u1 - u2;
				break;
			case Operand::Mul:
				r = u1 * u2;
				break;
			case Operand::Div:
				// divide by 0
				r = u1 / u2;
				break;
			case Operand::Mod:
				// divide by 0
				r = std::fmod(u1, u2);
				break;
			default:
				break;
		}
		std::ostringstream convert;
		convert << r;
		return (convert.str());
	}

};

#endif
