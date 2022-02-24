/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 04:02:45 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/24 02:00:28 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_HPP
# define COMPUTOR_HPP

# include "Number.hpp"
# include "Token.hpp"
# include "Equation.hpp"

# include <cctype>

# include <string>
# include <iostream>
# include <iostream>
# include <sstream>
# include <vector>
# include <iterator>

# define ABS(x) ( x < 0 ? -x : x )
# define MSG( str ) std::cout << "MSG: " << str << std::endl; 
# define ERR_DEG "The polynomial degree is stricly greater than 2, I can't solve."

std::vector< std::string >	ft_split( std::string const & str);
std::vector< Token >		ft_tokenize( std::vector< std::string > tab );
std::vector< Number >		ft_createList( std::vector< Token > token );

#endif