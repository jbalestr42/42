#include "Factory.hpp"
#include "Operand.hpp"
#include "Exceptions.hpp"
#include <limits>

std::unique_ptr<Factory> Factory::m_instance = nullptr;

Factory::Factory(void)
{
	m_createOperands[static_cast<int>(eOperandType::Int8)] = std::bind(&Factory::createInt8, this, std::placeholders::_1);
	m_createOperands[static_cast<int>(eOperandType::Int16)] = std::bind(&Factory::createInt16, this, std::placeholders::_1);
	m_createOperands[static_cast<int>(eOperandType::Int32)] = std::bind(&Factory::createInt32, this, std::placeholders::_1);
	m_createOperands[static_cast<int>(eOperandType::Float)] = std::bind(&Factory::createFloat, this, std::placeholders::_1);
	m_createOperands[static_cast<int>(eOperandType::Double)] = std::bind(&Factory::createDouble, this, std::placeholders::_1);
}

Factory::Factory(Factory const &)
{}

Factory & Factory::operator=(Factory const &)
{
	return (*this);
}

Factory & Factory::getInstance()
{
	if (m_instance == nullptr)
		m_instance.reset(new Factory());
	return *m_instance;
}

IOperand const * Factory::createOperand(eOperandType type, std::string const & value) const
{
	return m_createOperands[static_cast<int>(type)](value);
}

IOperand const * Factory::createInt8(std::string const & value) const
{
	if (value.length() > 1)
		checkValue<std::int8_t>(value);
	return new Operand<eOperandType::Int8>(value);
}

IOperand const * Factory::createInt16(std::string const & value) const
{
	checkValue<std::int16_t>(value);
	return new Operand<eOperandType::Int16>(value);
}

IOperand const * Factory::createInt32(std::string const & value) const
{
	checkValue<std::int32_t>(value);
	return new Operand<eOperandType::Int32>(value);
}

IOperand const * Factory::createFloat(std::string const & value) const
{
	checkValue<float>(value);
	return new Operand<eOperandType::Float>(value);
}

IOperand const * Factory::createDouble(std::string const & value) const
{
	checkValue<double>(value);
	return new Operand<eOperandType::Double>(value);
}

template<class T>
void Factory::checkValue(std::string const & value) const
{
	long double v = std::stold(value);
	if (v > static_cast<long double>(std::numeric_limits<T>::max()))
		throw OverflowException();
	else if (v < static_cast<long double>(std::numeric_limits<T>::lowest()))
		throw UnderflowException();
}
