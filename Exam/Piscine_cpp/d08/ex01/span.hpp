#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
private:
	std::vector<int>	m_vector;
	unsigned int		mn_currentNumber;

	void checkSize(void) const;

public:
	Span(void);
	Span(unsigned int pn_maxNumber);
	Span(Span const & p_span);
	virtual ~Span(void);

	Span &	operator=(Span const & p_span);

	void addNumber(int pn_number);
	int shortestSpan(void);
	int longestSpan(void);
	void initAll(int (*f)(void));

};

#endif /* !SPAN_HPP */

