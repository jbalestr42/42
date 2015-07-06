#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack
{
private:
	std::stack<T>	m_stack;

public:
	typedef T *		iterator;

	MutantStack(void) :
		m_stack()
	{}

	MutantStack(MutantStack const & p_mutantStack)
	{
		*this = p_mutantStack;
	}

	virtual ~MutantStack(void) { }

	MutantStack &	operator=(MutantStack const & p_mutantStack)
	{
		m_stack = p_mutantStack.m_stack;
		return (*this);
	}

	T *begin(void)
	{
		return &m_stack.top();
	}

	T *end(void)
	{
		return &m_stack.top();
	}

	void push(T const & p_val)
	{
		m_stack.push(p_val);
	}

	T const & top(void) const
	{
		return m_stack.top();
	}

	void pop(void)
	{
		m_stack.pop();
	}

	int size(void) const
	{
		return m_stack.size();
	}

};

#endif /* !MUTANTSTACK_HPP */

