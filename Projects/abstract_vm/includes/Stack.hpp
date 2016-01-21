#ifndef STACK_HPP
# define STACK_HPP

# include <vector>

template<class T>
class Stack
{
public:
	typedef typename std::vector<T>::iterator Iterator;

	Stack(void) = default;

	Stack(Stack const & stack)
	{
		*this = stack;
	}

	virtual ~Stack(void) = default;

	Stack & operator=(Stack const & stack)
	{
		m_stack.assign(stack.begin(), stack.end());
		return (*this);
	}

	T & operator[](int index)
	{
		return (m_stack[index]);
	}

	std::size_t size(void)
	{
		return (m_stack.size());
	}

	bool empty(void)
	{
		return (!m_stack.size());
	}

	Iterator begin(void)
	{
		return m_stack.begin();
	}

	Iterator end(void)
	{
		return m_stack.end();
	}

	void push(T const & elem)
	{
		m_stack.push_back(elem);
	}

	void pop(void)
	{
		m_stack.pop_back();
	}

	T const & top(void)
	{
		return m_stack.back();
	}

private:
	std::vector<T>	m_stack;

};

#endif
