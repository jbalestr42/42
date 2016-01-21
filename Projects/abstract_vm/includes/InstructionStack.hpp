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
		std::string			m_name;
		int					m_line;
		InstructionFunction	m_function;

		Instruction(void) = default;
		Instruction(Instruction const & instruction);
		Instruction(std::string const & name, int line);
		~Instruction(void) = default;
		Instruction & operator=(Instruction const & instruction);

		void setFunction(InstructionFunction * function);
	};

	struct InstructionArgs : public Instruction
	{
		std::string		m_value;
		eOperandType	m_type;

		InstructionArgs(void);
		InstructionArgs(InstructionArgs const & instructionArgs);
		InstructionArgs(std::string const & name, std::string const & value, eOperandType type, int line);
		~InstructionArgs(void) = default;
		InstructionArgs & operator=(InstructionArgs const & instructionArgs);

		void setFunction(InstructionArgsFunction * function);
	};

	InstructionStack(InstructionStack const & instructionStack);
	InstructionStack & operator=(InstructionStack const & instructionStack);

	void split(std::vector<std::string> & tokens, std::string const & line, char delimiter);
	void splitWhitespace(std::vector<std::string> & tokens, std::string const & line);
	bool isNumber(std::string const & string) const;

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
	bool												m_exitProperly;
	OperandStack										m_stack;

};

#endif
