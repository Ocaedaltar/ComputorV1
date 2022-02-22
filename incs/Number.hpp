/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Number.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:27:38 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/21 16:51:47 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBER_HPP
# define NUMBER_HPP

# include "Equation.hpp"

class Number
{
private:
    unsigned int power;
    double value;

    Number( void );
public:
    Number( unsigned int const & power, double const & value );
    Number( Number const & cpy );
    ~Number( void );    

    Number &operator=( Number const & other );
    Number &operator+( Number const & other );
    Number &operator-( Number const & other );

    unsigned int const &getPower( void ) const;
    double const &getValue( void ) const;

};

std::ostream& operator<<( std::ostream& os, Number const &perso );

#endif
