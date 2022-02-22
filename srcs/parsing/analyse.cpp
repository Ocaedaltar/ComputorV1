/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 05:28:46 by mlormois          #+#    #+#             */
/*   Updated: 2022/02/22 07:07:00 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.hpp"

// bool anafirst( int etat )
// {
//     return (( etat == VAL ||etat == PS ) ? false : true );
// }

// bool analyse( std::vector< std::string > tab )
// {
//     int act;
//     int prev = -1;

//     int tabCount = 0;
//     int oppCount = 0;
//     int state = 0;
//     int minValue = 0;

//     for ( std::vector< std::string >::iterator it = tab.begin();
//             it != tab.end(); it++ )
//     {
//         act =   VAL * ( std::isdigit(it->at(0)) ) +
//                 POW * ( it->at(0) == 'X' ) +
//                 MUL * ( *it == "*" ) +
//                 ASS * ( *it == "=" ) + 0;
//                 // PS  * ( *it == "(" ) +
//                 // PE  * ( *it == ")" ) + 0;
//         // ANALYSE DU PREMIER MAILLON:
//         if ( !tabCount && act != VAL )
//             return false;
//         if ( tabCount )
//         {
//             if ( act == VAL && ( prev == VAL || prev == POW ) )
//             {
//             }
//         }
//         // 
//         tabCount++;
//         prev = act;
//     }
// }