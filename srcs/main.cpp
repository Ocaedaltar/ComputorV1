/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 04:01:41 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/24 05:37:19 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "computor.hpp"

// Print the reduced form of the equation
void ft_reduce_form( std::vector< Number > list )
{
	std::cout << "Reduced form: ";
	if (list.size())
	{
		for ( std::vector< Number >::iterator it = list.begin(); it != list.end(); it++ )
		{
			std::cout << ( it->getSign() ? "- " : ( it != list.begin() ? "+ " : "" )) << it->getValue() \
				<< " * X^" << it->getPower() << " ";
		}
		std::cout << "= 0" << std::endl;
	}
	else 
		std::cout << "0" << std::endl;
}

// Print the polynomial degree of the arguments!
// If he's greater than 2, print a error.
int ft_polynomial_degre( std::vector< Number > list )
{
	int degre = 0;
	if (list.size())
		degre = list.back().getPower();
	std::cout << "Polynomial degree: " << degre << std::endl;
	if ( degre > 2 )
		std::cerr << ERR_DEG << std::endl;
	return degre;
}

void ft_resolve( std::vector< Number > list )
{
	Equation equ = Equation( list );
	equ.search_solution();
}

// Handler Parser and Engine
void computor( std::string const & str )
{
	std::vector< Number > nums = ft_createList(ft_tokenize(ft_split( str )));
	ft_reduce_form( nums );
	if (ft_polynomial_degre( nums ) <= 2)
		ft_resolve( nums );
}

int main( int ac, char **av )
{
    for (int i = 1; i < ac; i++)
        computor( av[i] );
    return 0;
}
