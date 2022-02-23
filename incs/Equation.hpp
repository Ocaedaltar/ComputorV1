/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equation.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:11:20 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/23 09:27:11 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUATION_HPP
# define EQUATION_HPP

# include "Number.hpp"
# include <vector>

class Equation
{
private:
	double b;
	double a;
	double c;

	int degres;

	double disc;

public:
	Equation( void );
	Equation( std::vector< Number > list );
	Equation( Equation const & cpy);
	Equation &operator=( Equation const & other );
	~Equation();

};




#endif