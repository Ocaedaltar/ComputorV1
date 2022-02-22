/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 05:24:51 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/22 07:21:44 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.hpp"

static std::vector< std::string > errorParsing( std::string const & str )
{
    std::vector< std::string> NIL;
    std::cerr << "Error: '" << str << "' not a valide input." << std::endl;
    return (NIL);
}

static std::string createWord( std::string & src, unsigned int len )
{
    std::string dst = src.substr(0, len);
    if (dst == "x" || dst == "X")
        dst = "X^1";
    else if (dst[0] == 'x')
        dst[0] = 'X';
    src.erase(0, len);
    return dst;
}

static unsigned int takeNumber( std::string const & str )
{
    unsigned int i = 0;
    while ( std::isdigit(str[i]) )
        i++;
    if (str[i] == '.')
        i++;
    while ( std::isdigit(str[i]) )
        i++;
    return i;
}

static unsigned int takePower( std::string const & str )
{
    unsigned int i = 0;
    if (str[0] == 'x' || str[0] == 'X')
    {
        i = 1;
        if ( str[1] == '^' )
        {
            i++;
            while ( std::isdigit(str[i]) )
                i++;
            if (i == 2)
                return 0;
        }
    }
    return i;
}

static std::vector< std::string > split ( std::string const &str, char delim)
{
    std::vector< std::string >  result;
    std::stringstream           ss(str);
    std::string                 item;
    unsigned int                ret;
    int                         sign = 1;

    while ( getline (ss, item, delim) )
    {
        while (item.length() > 0)
        {
            if ((ret = takeNumber( item )) > 0 && ((sign > 0)))
            {
                item = (sign == 1 ? "+" : "-") + item;
                result.push_back(createWord( item, ret + 1 ));
                sign = 0;
            }
            else if (( item[0] == '*' || item[0] == '=' ) && sign == 0)
            {
                std::string tmp = createWord( item, 1 );
                if (tmp == "*" && result.back() == "*")
                    return errorParsing( str );
                result.push_back( tmp );
                sign = 1;
            }
            else if ((ret = takePower( item )) > 0)
            {
                if (result.back() == "*")
                    result.pop_back();
                else if (sign)
                    result.push_back((sign == 1 ? "+1" : "-1"));
                result.push_back( createWord( item, ret) );
                sign = 0;
            }
            else if ( item[0] == '+'|| item[0] == '-' )
            {
                sign =  2 * (item[0] == '-' && sign != 2 ) + 
                        1 * ((item[0] == '+' && sign != 2) || 
                             (item[0] == '-' && sign == 2 ));
                item.erase(0, 1);
            }
            else
                return errorParsing( str );
        }
    }
    return result;
}

void computor_parsing( std::string const & str )
{
    std::vector< std::string > ret = split(str, ' ');
    if (ret.size() > 0 )
    {
        for (auto i : ret) std::cout << i << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
