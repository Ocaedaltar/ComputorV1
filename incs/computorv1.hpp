/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:09:50 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/22 06:23:11 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_HPP
# define COMPUTORV1_HPP

# include "Equation.hpp"
# include "Number.hpp"

# include <string>
# include <iostream>
# include <iostream>
# include <sstream>

# include <cctype>

# include <vector>
# include <iterator>

typedef std::vector< Number >   List;
typedef List::iterator          iterator;

enum State
{
    DEF = -1,
    ERR = 0,
// VALUE:
    VAL,
    POW,
// OPERATOR:
    MUL,
    ASS,
// SYNTAX
    PS,
    PE
};

bool analyse( std::vector< std::string > tab );
void computor_parsing( std::string const & str );

#endif
