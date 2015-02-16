#include "Span.hpp"
#include <exception>
#include <algorithm>
#include <numeric>

Span::Span(void) :
	m_vector(0),
	mn_currentNumber(0)
{
}

Span::Span(unsigned int pn_maxNumber) :
	m_vector(pn_maxNumber),
	mn_currentNumber(0)
{
}

Span::Span(Span const & p_span)
{
	*this = p_span;
}

Span::~Span(void)
{

}

Span & Span::operator=(Span const & p_span)
{
	m_vector = p_span.m_vector;
	mn_currentNumber = p_span.mn_currentNumber;
	return (*this);
}

void Span::addNumber(int pn_number)
{
	if (mn_currentNumber > m_vector.size())
		throw std::exception();
	m_vector[mn_currentNumber] = pn_number;
	mn_currentNumber++;
}

int Span::shortestSpan(void)
{
	checkSize();
	int array[mn_currentNumber];
	std::sort(m_vector.begin(), m_vector.begin() + mn_currentNumber);
	std::adjacent_difference(m_vector.begin(), m_vector.begin() + mn_currentNumber, array);
	int min = *std::max_element(m_vector.begin(), m_vector.begin() + mn_currentNumber);
	for (unsigned int i = 0; i < mn_currentNumber; i++)
	{
		if (min > array[i])
			min = array[i];
	}
	return (min);
}

int Span::longestSpan(void)
{
	checkSize();
	int min = *std::min_element(m_vector.begin(), m_vector.begin() + mn_currentNumber);
	int max = *std::max_element(m_vector.begin(), m_vector.begin() + mn_currentNumber);
	return (max - min);
}

void Span::checkSize(void) const
{
	if (m_vector.size() <= 1)
		throw std::exception();
}

void Span::initAll(int (*f)(void))
{
	std::generate(m_vector.begin(), m_vector.end(), f);
	mn_currentNumber = m_vector.size();
}

