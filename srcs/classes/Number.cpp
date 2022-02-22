/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:29:25 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/21 17:25:34 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Number.hpp"

Number::Number( unsigned int const & power, double const & value ) : 
    power(power), value(value)
{}

Number::Number( Number const & cpy )
{
    *this = cpy;
}

Number::~Number()
{}

Number &Number::operator=( Number const & other )
{
    power = other.getPower();
    value  = other.getValue();
    return *this;
}

Number &Number::operator+( Number const & other )
{
    if (power == other.getPower())
        value += getValue();
    return *this; 
}

Number &Number::operator-( Number const & other )
{
    if (power == other.getPower())
        value -= getValue();
    return *this; 
}

unsigned int const &Number::getPower( void ) const
{
    return power;
}

double const &Number::getValue( void ) const
{
    return value;
}

std::ostream& operator<<( std::ostream& os, Number const &perso )
{
    os << perso.getValue() << " * X^" << perso.getPower() << " ";
    return os;
}
