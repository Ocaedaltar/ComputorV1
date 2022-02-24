/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 04:03:11 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/24 05:35:25 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBER_HPP
# define NUMBER_HPP

class Number
{
private:
	int     power;
    int    	sign;
    double  value;

public:
	Number( void );
	Number( int power, int sign, double value );
	Number( Number const & cpy );
	Number &operator=( Number const & other );
	~Number( void );

	int const &getPower( void ) const;
	int const &getSign( void ) const;
	double const &getValue( void ) const;
	double getNumber( void ) const;
};

#endif
