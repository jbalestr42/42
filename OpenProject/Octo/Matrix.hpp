/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 00:32:15 by irabeson          #+#    #+#             */
/*   Updated: 2015/03/23 12:28:28 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
# define MATRIX_HPP
# include <memory>
# include <algorithm>

/*!
 *	\class Matrix
 *	\brief Generic 2d array
 *	
 *	This class provide a generic two dimmensionnal array.
 *	You can create an empty matrix and resize it later or
 *	you can create a matrix with a defined size and default value.<br>
 *	
 *	This container provide the couple of methods begin/end so it can
 *	be used with for each loop (C++ 11) or with STL algorithms exactly
 *	as std::vector.
 *	\code
 *	Matrix<int>	mat(3, 3, 0);
 *	int			counter = 0;
 *	
 *	for (auto& value : mat)
 *		value = counter++;
 *	for (auto value : mat)
 *		std::cout << value << std::endl;
 *	\endcode
 */
template <class T>
class Matrix
{
	Matrix(Matrix<T> const&) = delete;
	Matrix&				operator = (Matrix<T> const&) = delete;
public:
	typedef T*			iterator;
	typedef T const*	const_iterator;

	/*!	Create a null matrix
	 *	
	 *	A null matrix has no memory reserved.<br>
	 *	\warning Using set() and get() method on a null matrix causes an undefined
	 *	behavior.
	 *	\see isNull()
	 *	\see resize()
	 */
	Matrix();

	/*!	Create a matrix filled by a value */
	Matrix(std::size_t columns, std::size_t rows, T defaultValue);

	/*!	Move constructor */
	Matrix(Matrix<T>&& other);

	/*!	Move operator */
	Matrix<T> & operator=(Matrix<T>&& other);

	/*!	Resize the matrix
	 *	Internal memory is reallocated only if the new size is greater
	 *	than the current size.<br>
	 *	\warning This method may invalidate iterators.
	 */
	void				resize(std::size_t columns, std::size_t rows, T defaultValue);

	/*!	Get a value */
	T&					get(std::size_t column, std::size_t row);

	/*!	Get a constant value */
	T const&			get(std::size_t column, std::size_t row)const;

	/*!	Set a value */
	void				set(std::size_t column, std::size_t row, T const& value);

	/*!	Indicates if the matrix is null */
	bool				isNull()const;

	/*!	Get the columns count */
	std::size_t			columns()const;

	/*!	Get the rows count */
	std::size_t			rows()const;

	/*!	Get the count of values */
	std::size_t			count()const;

	T&					operator()(std::size_t colum,  std::size_t row);
	T const&			operator()(std::size_t colum,  std::size_t row)const;

	iterator			begin();
	iterator			end();
	const_iterator		begin()const;
	const_iterator		end()const;
private:
	inline std::size_t	index2dToIndex1D(std::size_t column, std::size_t row)const;
private:
	std::unique_ptr<T[]>	m_values;
	std::size_t				m_columns;
	std::size_t				m_rows;
	std::size_t				m_count;
};

#include "Matrix.hxx"
#endif
