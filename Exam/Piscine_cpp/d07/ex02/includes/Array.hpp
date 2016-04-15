#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template<typename T>
class Array
{
private:
	T *				mt_array;
	unsigned int	mn_length;

public:
	Array(void) :
		mn_length(0)
	{
		mt_array = new T[0];
	}

	Array(unsigned int pn_length) :
		mn_length(pn_length)
	{
		mt_array = new T[mn_length];
	}

	Array(Array<T> const & p_array)
	{
		*this = p_array;
	}

	virtual ~Array(void)
	{
		if (mt_array)
			delete [] mt_array;
	}

	Array<T> &	operator=(Array<T> const & p_array)
	{
		if (mt_array)
			delete [] mt_array;
		mt_array = new T[p_array.getLength()];
		mn_length = p_array.getLength();
		for (int i = 0; i < p_array.getLength(); i++)
			mt_array[i] = p_array[i];
		return (*this);
	}

	T &			operator[](int pn_index) const
	{
		if (pn_index < 0 || pn_index > mn_length)
			throw std::exception();
		return mt_array[pn_index];
	}

	int			size(void) const
	{
		return mn_length;
	}

	unsigned int getLength(void) const
	{
		return mn_length;
	}

};

#endif /* !ARRAY_HPP */

