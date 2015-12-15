#ifndef INSTRUCTIONSTACK_HPP
# define INSTRUCTIONSTACK_HPP

# include "IOperand.hpp"
# include "Exceptions.hpp"
# include "Stack.hpp"
# include <string>
# include <vector>
# include <map>
# include <functional>
# include <memory>

class InstructionStack
{
public:
	InstructionStack(void);
	virtual ~InstructionStack(void);

	void process(void);
	void processLine(std::string const & line);

private:
	typedef Stack<IOperand const *>											OperandStack;
	typedef std::function<void(void)>										InstructionFunction;
	typedef std::function<void(std::string const &, eOperandType type)>		InstructionArgsFunction;

	struct Instruction
	{
		std::string		m_name;
		int				m_line;
		InstructionFunction	m_function;

		Instruction(std::string const & name, int line) :
			m_name(name),
			m_line(line),
			m_function(nullptr)
		{}

		void setFunction(InstructionFunction * function)
		{
			m_function = *function;
		}
	};

	struct InstructionArgs : public Instruction
	{
		std::string		m_value;
		eOperandType	m_type;

		InstructionArgs(std::string const & name, std::string const & value, eOperandType type, int line) :
			Instruction(name, line),
			m_value(value),
			m_type(type)
		{}

		void setFunction(InstructionArgsFunction * function)
		{
			m_function = std::bind(*function, m_value, m_type);
		}
	};

	InstructionStack(InstructionStack const & instructionStack);
	InstructionStack & operator=(InstructionStack const & instructionStack);

	void split(std::vector<std::string> & tokens, std::string const & line, char delimiter);
	void splitWhitespace(std::vector<std::string> & tokens, std::string const & line);
	bool isNumber(std::string const & string); //TODO: ajjouter les const a la fin des fonction

	eOperandType checkOperandType(std::string const & type);
	void checkParam(std::vector<std::string> & tokens, std::string const & param, std::string const & line);
	void checkFunction(std::string const & functionName, bool hasParam, Instruction * instruction);

	void push(OperandStack & stack, std::string const & value, eOperandType type);
	void assert(OperandStack & stack, std::string const & value, eOperandType type);
	void pop(OperandStack & stack);
	void dump(OperandStack & stack);
	void add(OperandStack & stack);
	void sub(OperandStack & stack);
	void mul(OperandStack & stack);
	void div(OperandStack & stack);
	void mod(OperandStack & stack);
	void print(OperandStack & stack);
	void exit(OperandStack & stack);

	std::vector<std::unique_ptr<Instruction>>			m_instructions;
	std::map<std::string, InstructionFunction>			m_instructionFunctions;
	std::map<std::string, InstructionArgsFunction>		m_instructionArgsFunctions;
	std::vector<std::pair<std::string, eOperandType>>	m_validTypes;
	std::size_t											m_countLine;
	OperandStack										m_stack;

};

#endif
