#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <exception>
# include <string>

class Exception : public std::exception
{
public:
	Exception(std::string const & string);
	Exception(std::string const & string, int line);
	Exception(Exception const & exceptions);
	virtual ~Exception(void) = default;

	virtual const char * what() const throw();

private:
	std::string		m_funName;

	Exception(void);
	Exception & operator=(Exception const & exceptions);
};

class NoExitException : public Exception
{
public:
	NoExitException(void);
};

class ZeroDivisionException : public Exception
{
public:
	ZeroDivisionException(void);
};

class UnderflowException : public Exception
{
public:
	UnderflowException(void);
};

class OverflowException : public Exception
{
public:
	OverflowException(void);
};

class WrongFileException : public Exception
{
public:
	WrongFileException(std::string const & string);
};

class PrintFailedException : public Exception
{
public:
	PrintFailedException(std::string const & string);
};

class AssertException : public Exception
{
public:
	AssertException(std::string const & string);
};

class NotEnoughValueException : public Exception
{
public:
	NotEnoughValueException(void);
};

class EmptyStackException : public Exception
{
public:
	EmptyStackException(void);
};

class NeedParamException : public Exception
{
public:
	NeedParamException(std::string const & string, int line);
};

class NoNeedParamException : public Exception
{
public:
	NoNeedParamException(std::string const & string, int line);
};

class InvalidValueException : public Exception
{
public:
	InvalidValueException(std::string const & string, int line);
};

class UnknowTypeException : public Exception
{
public:
	UnknowTypeException(std::string const & string, int line);
};

class UnknowInstructionException : public Exception
{
public:
	UnknowInstructionException(std::string const & string, int line);
};

class SyntacticErrorExceptionException : public Exception
{
public:
	SyntacticErrorExceptionException(std::string const & string, int line);
};

#endif
