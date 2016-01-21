#ifndef OPERAND_HPP
# define OPERAND_HPP

# include <sstream>
# include <cmath>
# include <limits>
# include "IOperand.hpp"
# include "Factory.hpp"
# include "Exceptions.hpp"

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

	Operand(Operand const & operand)
	{
		*this = operand;
	}

	Operand(std::string const & value) :
		m_value(value)
	{}

	virtual ~Operand(void) = default;

	Operand & operator=(Operand const & operand)
	{
		m_value = operand.m_value;
		return (*this);
	}

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
				return getResult(rhs, op);
				break;
			case eOperandType::Int16:
				return getResult(rhs, op);
				break;
			case eOperandType::Int32:
				return getResult(rhs, op);
				break;
			case eOperandType::Float:
				return getResult(rhs, op);
				break;
			case eOperandType::Double:
				return getResult(rhs, op);
				break;
			default:
				break;
		}
		return "0";
	}

	std::string		getResult(IOperand const & rhs, Operator op) const
	{
		long double u1 = std::stold(toString().c_str());
		long double u2 = std::stold(rhs.toString().c_str());
		long double r;

		switch (op)
		{
			case Operand::Add:
				r = u1 + u2;
				break;
			case Operand::Sub:
				r = u1 - u2;
				break;
			case Operand::Mul:
				r = u1 * u2;
				break;
			case Operand::Div:
				if (u2 < std::numeric_limits<long double>::epsilon())
					throw ZeroDivisionException();
				r = u1 / u2;
				break;
			case Operand::Mod:
				if (u2 < std::numeric_limits<long double>::epsilon())
					throw ZeroDivisionException();
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
