/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 06:55:01 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/23 07:12:20 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Token.hpp"

Token::Token( void )
{}

Token::~Token()
{}

Token::Token( std::string str, int type ) :
	str(str), type(type)
{}

Token::Token( Token const & cpy )
{
	*this = cpy;
}

Token &Token::operator=( Token const & other )
{
	str = other.getStr();
	type = other.getType();
	return *this;
}

std::string const &Token::getStr( void ) const
{
	return str;
}

int const &Token::getType( void ) const
{
	return type;
}
