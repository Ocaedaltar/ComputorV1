/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equation.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:13:27 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/24 04:21:40 by mlormois         ###   ########.fr       */
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

void	Equation::solution_two( void ) const
{
	double disc = (b * b) - (4 * a * c);
	if ( disc > 0)
		std::cout << ((-b -sqrt(disc)) / (2 * a)) << std::endl << ((-b +sqrt(disc)) / (2 * a)) << std::endl;
	else if ( disc == 0)
		std::cout << (-b / (2 * a)) << std::endl;
	else
		std::cout << "This equation has no real solution." << std::endl;
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
