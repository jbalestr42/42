#include "InstructionStack.hpp"
#include <iostream>
#include <sstream>
#include <iterator>
#include <cstdlib>
#include <limits>
#include "Operand.hpp"
#include "Factory.hpp"

InstructionStack::InstructionStack(void) :
	m_countLine(1),
	m_exitProperly(false)
{
	m_instructionArgsFunctions["push"] = std::bind(&InstructionStack::push, this, std::ref(m_stack), std::placeholders::_1, std::placeholders::_2);
	m_instructionArgsFunctions["assert"] = std::bind(&InstructionStack::assert, this, std::ref(m_stack), std::placeholders::_1, std::placeholders::_2);
	m_instructionFunctions["pop"] = std::bind(&InstructionStack::pop, this, std::ref(m_stack));
	m_instructionFunctions["dump"] = std::bind(&InstructionStack::dump, this, std::ref(m_stack));
	m_instructionFunctions["add"] = std::bind(&InstructionStack::add, this, std::ref(m_stack));
	m_instructionFunctions["sub"] = std::bind(&InstructionStack::sub, this, std::ref(m_stack));
	m_instructionFunctions["mul"] = std::bind(&InstructionStack::mul, this, std::ref(m_stack));
	m_instructionFunctions["div"] = std::bind(&InstructionStack::div, this, std::ref(m_stack));
	m_instructionFunctions["mod"] = std::bind(&InstructionStack::mod, this, std::ref(m_stack));
	m_instructionFunctions["print"] = std::bind(&InstructionStack::print, this, std::ref(m_stack));
	m_instructionFunctions["exit"] = std::bind(&InstructionStack::exit, this, std::ref(m_stack));

	m_validTypes.emplace_back("int8", eOperandType::Int8);
	m_validTypes.emplace_back("int16", eOperandType::Int16);
	m_validTypes.emplace_back("int32", eOperandType::Int32);
	m_validTypes.emplace_back("float", eOperandType::Float);
	m_validTypes.emplace_back("double", eOperandType::Double);
}

InstructionStack::InstructionStack(InstructionStack const & instructionStack)
{
	*this = instructionStack;
}

InstructionStack::~InstructionStack(void)
{
	while (!m_stack.empty())
	{
		IOperand const * op = m_stack.top();
		m_stack.pop();
		delete op;
	}
}

InstructionStack & InstructionStack::operator=(InstructionStack const & instructionStack)
{
	(void)instructionStack;
	return (*this);
}

void InstructionStack::process(void)
{
	for (auto & instruction : m_instructions)
	{
		instruction->m_function();
		if (m_exitProperly)
			break;
	}
	if (!m_exitProperly)
		throw NoExitException();
}

void InstructionStack::processLine(std::string const & line)
{
	std::vector<std::string> tokens;

	split(tokens, line, ';');
	if (tokens.size())
	{
		splitWhitespace(tokens, tokens[0]);
		if (tokens.size())
		{
			if (tokens.size() == 1)
			{
				Instruction * ins = new Instruction(tokens[0], m_countLine);
				checkFunction(tokens[0], false, ins);
				m_instructions.emplace_back(ins);
			}
			else if (tokens.size() == 2)
			{
				std::vector<std::string> subTokens;
				checkParam(subTokens, tokens[1], line);
				InstructionArgs * ins = new InstructionArgs(tokens[0], subTokens[2], checkOperandType(subTokens[1]),  m_countLine);
				checkFunction(tokens[0], true, ins);
				m_instructions.emplace_back(ins);
			}
			else if (tokens.size() > 2)
				throw SyntacticErrorExceptionException(line, m_countLine);
		}
	}
	m_countLine++;
}

void InstructionStack::push(OperandStack & stack, std::string const & value, eOperandType type)
{
	stack.push(Factory::getInstance().createOperand(type, value));
}

void InstructionStack::assert(OperandStack & stack, std::string const & value, eOperandType type)
{
	IOperand const * op = Factory::getInstance().createOperand(type, value);
	IOperand const * res = *op - *stack.top();
	if (res->toString().compare("0"))
		throw AssertException(op->toString());
}

void InstructionStack::pop(OperandStack & stack)
{
	if (stack.empty())
		throw EmptyStackException();
	stack.pop();
}

void InstructionStack::dump(OperandStack & stack)
{
	for (int i = stack.size() - 1; i >= 0; i--)
		std::cout << stack[i]->toString() << std::endl;
}

void InstructionStack::add(OperandStack & stack)
{
	if (stack.size() < 2)
		throw NotEnoughValueException();
	IOperand const * op1 = stack.top();
	stack.pop();
	IOperand const * op2 = stack.top();
	stack.pop();
	stack.push(*op2 + *op1);
	delete op1;
	delete op2;
}

void InstructionStack::sub(OperandStack & stack)
{
	if (stack.size() < 2)
		throw NotEnoughValueException();
	IOperand const * op1 = stack.top();
	stack.pop();
	IOperand const * op2 = stack.top();
	stack.pop();
	stack.push(*op2 - *op1);
	delete op1;
	delete op2;
}

void InstructionStack::mul(OperandStack & stack)
{
	if (stack.size() < 2)
		throw NotEnoughValueException();
	IOperand const * op1 = stack.top();
	stack.pop();
	IOperand const * op2 = stack.top();
	stack.pop();
	stack.push(*op2 * *op1);
	delete op1;
	delete op2;
}

void InstructionStack::div(OperandStack & stack)
{
	if (stack.size() < 2)
		throw NotEnoughValueException();
	IOperand const * op1 = stack.top();
	stack.pop();
	IOperand const * op2 = stack.top();
	stack.pop();
	stack.push(*op2 / *op1);
	delete op1;
	delete op2;
}

void InstructionStack::mod(OperandStack & stack)
{
	if (stack.size() < 2)
		throw NotEnoughValueException();
	IOperand const * op1 = stack.top();
	stack.pop();
	IOperand const * op2 = stack.top();
	stack.pop();
	stack.push(*op2 % *op1);
	delete op1;
	delete op2;
}

void InstructionStack::print(OperandStack & stack)
{
	if (stack.top()->getType() != eOperandType::Int8)
		throw PrintFailedException(stack.top()->toString());
	std::cout << static_cast<char>(std::atoi(stack.top()->toString().c_str())) << std::endl;
}

void InstructionStack::exit(OperandStack & stack)
{
	while (!stack.empty())
	{
		IOperand const * op = stack.top();
		stack.pop();
		delete op;
	}
	m_exitProperly = true;
}

void InstructionStack::checkFunction(std::string const & functionName, bool hasParam, Instruction * instruction)
{
	auto it = m_instructionFunctions.find(functionName);
	if (it != m_instructionFunctions.end())
	{
		if (hasParam == true)
			throw NoNeedParamException(functionName, m_countLine);
		instruction->setFunction(&it->second);
		return;
	}
	auto itt = m_instructionArgsFunctions.find(functionName);
	if (itt != m_instructionArgsFunctions.end())
	{
		if (hasParam == false)
			throw NeedParamException(functionName, m_countLine);
		static_cast<InstructionArgs*>(instruction)->setFunction(&itt->second);
	}
	else
		throw UnknowInstructionException(functionName, m_countLine);
}

void InstructionStack::checkParam(std::vector<std::string> & tokens, std::string const & param, std::string const & line)
{
	if (param.find(")") == std::string::npos)
		throw SyntacticErrorExceptionException(line, m_countLine);
	split(tokens, param, ')');
	split(tokens, tokens[0], '(');
	if (tokens.size() != 3)
		throw SyntacticErrorExceptionException(line, m_countLine);
	if (!isNumber(tokens[2]))
		throw InvalidValueException(tokens[2], m_countLine);
}

eOperandType InstructionStack::checkOperandType(std::string const & type)
{
	for (auto & pair : m_validTypes)
	{
		if (!type.compare(pair.first))
			return pair.second;
	}
	throw UnknowTypeException(type, m_countLine);
}

void InstructionStack::split(std::vector<std::string> & tokens, std::string const & line, char delimiter)
{
	std::stringstream sstream(line);
	std::string segment;

	while (std::getline(sstream, segment, delimiter))
		tokens.emplace_back(segment);
}

void InstructionStack::splitWhitespace(std::vector<std::string> & tokens, std::string const & line)
{
	std::istringstream buf(line);
	std::istream_iterator<std::string> beg(buf);
	std::istream_iterator<std::string> end;
	tokens.assign(beg, end);
}

bool InstructionStack::isNumber(std::string const & string) const
{
	std::stringstream ss;
	ss << string;

	double num = 0.0;
	ss >> num;
	if (ss.good())
		return (false);
	else if (num == 0 && string[0] != '0')
		return (false);
	return (true);
}

InstructionStack::Instruction::Instruction(Instruction const & instruction)
{
	*this = instruction;
}

InstructionStack::Instruction::Instruction(std::string const & name, int line) :
	m_name(name),
	m_line(line),
	m_function(nullptr)
{}

InstructionStack::Instruction & InstructionStack::Instruction::operator=(Instruction const & instruction)
{
	m_name = instruction.m_name;
	m_line = instruction.m_line;
	m_function = instruction.m_function;
	return (*this);
}

void InstructionStack::Instruction::setFunction(InstructionFunction * function)
{
	m_function = *function;
}

InstructionStack::InstructionArgs::InstructionArgs(void) :
	Instruction()
{}

InstructionStack::InstructionArgs::InstructionArgs(InstructionArgs const & instructionArgs) :
	Instruction(instructionArgs)
{
	*this = instructionArgs;
}

InstructionStack::InstructionArgs::InstructionArgs(std::string const & name, std::string const & value, eOperandType type, int line) :
	Instruction(name, line),
	m_value(value),
	m_type(type)
{}

InstructionStack::InstructionArgs & InstructionStack::InstructionArgs::operator=(InstructionArgs const & instructionArgs)
{
	Instruction::operator=(instructionArgs);
	m_value = instructionArgs.m_value;
	m_type = instructionArgs.m_type;
	return (*this);
}

void InstructionStack::InstructionArgs::setFunction(InstructionArgsFunction * function)
{
	m_function = std::bind(*function, m_value, m_type);
}
