/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:29:37 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/22 05:33:16 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.hpp"

void affNumber( List nums )
{
    for ( iterator it = nums.begin(); it != nums.end(); it++)
        std::cout << *it;
    std::cout << std::endl; 
}

int main( int ac, char **av )
{
    for ( int i = 1; i < ac; i++)
        computor_parsing( av[i] );
    return 0;
}