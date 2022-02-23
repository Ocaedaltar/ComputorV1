/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 04:50:05 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/23 07:30:41 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_HPP
# define TOKEN_HPP

# include <string>

enum state
{
	VAL = 0,
	MIN,
	PLS,
	POW,
	ASS
};

class Token
{
private:
	std::string	str;
	int			type;

public:
	Token( void );
	Token( std::string str, int type );
	Token( Token const & cpy );
	Token &operator=( Token const & other );
	~Token();

	std::string const &getStr( void ) const;
	int const &getType( void ) const;
};

#endif
