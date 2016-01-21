#include "Exceptions.hpp"
#include <sstream>

Exception::Exception(void) :
	m_funName("")
{}

Exception::Exception(std::string const & funName) :
	m_funName(funName)
{}

Exception::Exception(std::string const & funName, int line) :
	m_funName("")
{
	std::ostringstream oss;
	oss << "(line " << line << ") " << funName;
	m_funName = oss.str();
}

Exception::Exception(Exception const & exceptions)
{
	*this = exceptions;
}

Exception & Exception::operator=(Exception const & exceptions)
{
	m_funName = exceptions.m_funName;
	return (*this);
}

const char * Exception::what() const throw()
{
	return (m_funName.c_str());
}

NoExitException::NoExitException(void) :
	Exception("NoExitException: No exit at end of program !")
{}

ZeroDivisionException::ZeroDivisionException(void) :
	Exception("ZeroDivisionException: Divide by 0 !")
{}

UnderflowException::UnderflowException(void) :
	Exception("UnderflowException: Underflow !")
{}

OverflowException::OverflowException(void) :
	Exception("OverflowException: Overflow !")
{}

WrongFileException::WrongFileException(std::string const & string) :
	Exception("WrongFileException: The file \"" + string + "\" can't be opened.")
{}

PrintFailedException::PrintFailedException(std::string const & string) :
	Exception("PrintFailedException: Print failed ! The value (" + string + ") is not a character.")
{}

AssertException::AssertException(std::string const & string) :
	Exception("AssertException: Assertion failed ! The value (" + string + ") is not at the top of the stack.")
{}

NotEnoughValueException::NotEnoughValueException(void) :
	Exception("NotEnoughValueException: There are not enough values to perform the operation.")
{}

EmptyStackException::EmptyStackException(void) :
	Exception("EmptyStackException: The stack is empty")
{}

NeedParamException::NeedParamException(std::string const & string, int line) :
	Exception("NeedParamException: The instruction \"" + string + "\" need parameter.", line)
{}

NoNeedParamException::NoNeedParamException(std::string const & string, int line) :
	Exception("NoNeedParamException: The instruction \"" + string + "\" don't need parameter.", line)
{}

InvalidValueException::InvalidValueException(std::string const & string, int line) :
	Exception("InvalidValueException: The value \"" + string + "\" is invalid.", line)
{}

UnknowTypeException::UnknowTypeException(std::string const & string, int line) :
	Exception("UnknowTypeException: The type \"" + string + "\" is invalid.", line)
{}

UnknowInstructionException::UnknowInstructionException(std::string const & string, int line) :
	Exception("UnknowInstructionException: The function \"" + string + "\" is invalid.", line)
{}

SyntacticErrorExceptionException::SyntacticErrorExceptionException(std::string const & string, int line) :
	Exception("SyntacticErrorExceptionException: The line \"" + string + "\" is invalid.", line)
{}
