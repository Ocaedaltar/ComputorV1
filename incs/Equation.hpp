/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equation.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:11:20 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/24 05:21:17 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUATION_HPP
# define EQUATION_HPP

# include "Number.hpp"
# include <iostream>
# include <vector>

# define ABS(x) ( x < 0 ? -x : x )
# define SOL_ALL "All real numbers are solutions."
# define SOL_ERR "No possible solution."

class Equation
{
private:
	double a;
	double b;
	double c;

	int degres;

	double	ft_sqrt( double v ) const;
	void	solution_two( void ) const;
	void	solution_one( void ) const;
	void	solution_zero( void ) const;
	double	takePow( int pow ,  std::vector< Number > list );

public:
	Equation( void );
	Equation( std::vector< Number > list );
	Equation( Equation const & cpy);
	Equation &operator=( Equation const & other );
	~Equation();

	void search_solution( void );

	double const &getA( void ) const;
	double const &getB( void ) const;
	double const &getC( void ) const;
	int const &getDeg( void ) const;
};

#endif
