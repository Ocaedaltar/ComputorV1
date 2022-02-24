/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 04:10:49 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/24 05:35:59 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Number.hpp"

Number::Number( void )
{}

Number::Number( int power, int sign, double value ) :
	power(power), sign(sign), value(value)
{}

Number::Number( Number const & cpy )
{
	*this = cpy;
}

Number &Number::operator=( Number const & other )
{
	power = other.getPower();
	sign = other.getSign();
	value = other.getValue();
	return *this;
}

Number::~Number( void )
{}

int const &Number::getPower( void ) const
{
	return power;
}

int const &Number::getSign( void ) const
{
	return sign;
}

double const &Number::getValue( void ) const
{
	return value;
}

double Number::getNumber( void ) const
{
	return (value * ( sign == 1 ? -1 : 1 ));
}
