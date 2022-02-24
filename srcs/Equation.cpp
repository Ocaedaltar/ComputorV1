/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equation.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:13:27 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/24 05:34:40 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Equation.hpp"

Equation::Equation( void )
{}

double Equation::takePow( int pow, std::vector< Number > list )
{
	double ret = 0;
	for ( std::vector< Number >::iterator it = list.begin(); it != list.end(); it++ )
		if (it->getPower() == pow)
			ret = it->getNumber();
	return ret;
}

Equation::Equation( std::vector< Number > list )
{
	a = takePow(2, list);
	b = takePow(1, list);
	c = takePow(0, list);
	degres = ( a ? 2 : ( b ? 1 : 0));
}

Equation::Equation( Equation const & cpy)
{
	*this = cpy;
}

Equation &Equation::operator=( Equation const & other )
{
	a = other.getA();
	b = other.getB();
	c = other.getC();
	degres = other.getDeg();
	return *this;
}

Equation::~Equation()
{}

double const &Equation::getA( void ) const
{
	return a;
}

double const &Equation::getB( void ) const
{
	return b;
}

double const &Equation::getC( void ) const
{
	return c;
}

int const &Equation::getDeg( void ) const
{
	return degres;
}

double	Equation::ft_sqrt( double number ) const
{
	long		i;
	float		x2, y;
	const float	threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;						// floating point bit level hacking [sic]
	i  = 0x5f3759df - ( i >> 1 );				// Newton's approximation
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );	// 1st iteration --
	y  = y * ( threehalfs - ( x2 * y * y ) );	// 2nd iteration --
	y  = y * ( threehalfs - ( x2 * y * y ) );	// 3rd iteration pour avoir la meme precision que le suject.
	return -1/y;
}

void	Equation::solution_two( void ) const
{
	double disc = (b * b) - (4 * a * c);
	if ( disc > 0)
		std::cout << ((-b - ft_sqrt(disc)) / (2 * a)) << std::endl << ((-b + ft_sqrt(disc)) / (2 * a)) << std::endl;
	else if ( disc == 0)
		std::cout << (-b / (2 * a)) << std::endl;
	else
	{
		std::cout << "( " << -b << " - i√(" << ABS(disc) << ") ) / " << (2 * a) << std::endl;
		std::cout << "( " << -b << " + i√(" << ABS(disc) << ") ) / " << (2 * a) << std::endl;
	}
}

void	Equation::solution_one( void ) const
{
	std::cout << (-c / b) << std::endl;
}

void	Equation::solution_zero( void ) const
{
	std::cout << ( c == 0 ? SOL_ALL : SOL_ERR ) << std::endl;
}

void Equation::search_solution( void )
{
	std::cout << "The solution is: " << std::endl;
	switch (degres)
	{
	case 2:
		solution_two();
		break;
	case 1:
		solution_one();
		break;
	case 0:
		solution_zero();
		break;
	}
}
