/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hxx                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 14:48:51 by irabeson          #+#    #+#             */
/*   Updated: 2015/03/20 18:42:09 by irabeson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T>
inline std::size_t	Matrix<T>::index2dToIndex1D(std::size_t column, std::size_t row)const
{
	return (column + row * m_columns);
}

template <class T>
Matrix<T>::Matrix() :
	m_values(nullptr),
	m_columns(0u),
	m_rows(0u),
	m_count(0u)
{
}

template <class T>
Matrix<T>::Matrix(std::size_t columns, std::size_t rows, T defaultValue) :
	m_values(new T[columns * rows]),
	m_columns(columns),
	m_rows(rows),
	m_count(columns * rows)
{
	std::fill(begin(), end(), defaultValue);
}

template <class T>
Matrix<T>::Matrix(Matrix<T>&& other) :
	m_values(std::move(other.m_values)),
	m_columns(other.m_columns),
	m_rows(other.m_rows),
	m_count(other.m_count)
{
	other.m_columns = 0u;
	other.m_rows = 0u;
	other.m_count = 0u;
}

template <class T>
Matrix<T> & Matrix<T>::operator=(Matrix<T>&& other)
{
	if (this != &other)
	{
		m_values = std::move(other.m_values);
		m_columns = other.m_columns;
		m_rows = other.m_rows;
		m_count = other.m_count;
		other.m_columns = 0u;
		other.m_rows = 0u;
		other.m_count = 0u;
	}
	return (*this);
}

template <class T>
void	Matrix<T>::resize(std::size_t columns, std::size_t rows, T defaultValue)
{
	m_values.reset(new T[columns * rows]);
	m_columns = columns;
	m_rows = rows;
	m_count = columns * rows;
	std::fill(begin(), end(), defaultValue);
}

template <class T>
T&	Matrix<T>::get(std::size_t column, std::size_t row)
{
	return (m_values[index2dToIndex1D(column, row)]);
}

template <class T>
T const&	Matrix<T>::get(std::size_t column, std::size_t row)const
{
	return (m_values[index2dToIndex1D(column, row)]);
}

template <class T>
void		Matrix<T>::set(std::size_t column, std::size_t row, T const& value)
{
	m_values[index2dToIndex1D(column, row)] = value;
}

template <class T>
std::size_t	Matrix<T>::columns()const
{
	return (m_columns);
}

template <class T>
std::size_t	Matrix<T>::rows()const
{
	return (m_rows);
}

template <class T>
std::size_t	Matrix<T>::count()const
{
	return (m_count);
}

template <class T>
T&			Matrix<T>::operator()(std::size_t colum,  std::size_t row)
{
	return (get(colum, row));
}

template <class T>
T const&	Matrix<T>::operator()(std::size_t colum,  std::size_t row)const
{
	return (get(colum, row));
}

template <class T>
typename Matrix<T>::iterator	Matrix<T>::begin()
{
	return (m_values.get());
}

template <class T>
typename Matrix<T>::iterator	Matrix<T>::end()
{
	return (m_values.get() + m_count);
}

template <class T>
typename Matrix<T>::const_iterator	Matrix<T>::begin()const
{
	return (m_values.get());
}

template <class T>
typename Matrix<T>::const_iterator	Matrix<T>::end()const
{
	return (m_values.get() + m_count);
}
