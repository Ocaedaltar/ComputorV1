/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 04:13:27 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/24 01:36:06 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "computor.hpp"


std::vector< std::string > ft_split( std::string const & str)
{
	std::vector< std::string >	tab;
	std::stringstream			ss(str);
	std::string					item;

	while (getline(ss, item, ' '))	
        if (item.length() > 0)
			tab.push_back( item );
	return (tab);
}

std::vector< Token > ft_tokenize( std::vector< std::string > tab )
{
	std::vector< Token > token;

	for ( std::vector< std::string >::iterator it = tab.begin(); it != tab.end(); it++ )
	{
		if ( *it == "=" )
			token.push_back( Token(*it, ASS) );
		else if ( *it == "-" || *it == "+" )
			token.push_back( Token(*it, (*it == "-") ? MIN : PLS ));
		else if ( (*it)[0] == 'X')
		{
			it->erase(0, 2);
			token.push_back( Token(*it, POW) );
		}
		else if ( isdigit((*it)[0]) )
			token.push_back( Token(*it, VAL) );
	}
	return token;
}

std::vector< Number > mergeList( std::vector< Number > old )
{
	std::vector< Number > list;
	double value;
	int power = 0;

	while (old.size() > 0)
	{
		value = 0;
		for( int i = old.size() - 1; i >= 0; i--) 
		{
			if (old.at(i).getValue() == 0)
				old.erase( old.begin() + i ); 
			else if (old.at(i).getPower() == power)
			{
				value += old.at(i).getNumber();
				old.erase( old.begin() + i ); 
			}
		}
		if (value)
			list.push_back( Number( power, (value < 0 ? 1 : 0), ABS(value)) );
		power++;
	}
	return list;
}

std::vector< Number > ft_createList( std::vector< Token > token )
{
	int sign = 0;
	int balancing = 0;
	std::vector< Number > nums;

	for ( std::vector< Token >::iterator it = token.begin(); it != token.end(); it++ )
	{
		sign = 1 * (it->getType() == MIN || sign);
		balancing = 1 * (balancing || it->getType() == ASS);
		if (it->getType() == VAL)
		{
			sign = 1 * ((!balancing && sign) || (balancing && !sign));
			if (std::stod(it->getStr()) != 0)
				nums.push_back( Number( std::stoi((it + 1)->getStr()), sign , std::stod(it->getStr())));
			sign = 0;
		}
	}
	return mergeList( nums );
}
