/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:05:21 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "map.hpp"

int main ()
{
  ft::map<char,int> mymap;
  ft::map<char,int>::iterator it, it2;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;

  it = mymap.find('b');
  std::cout << it->first << std::endl;
  if (it != mymap.end())
    mymap.erase(it);

  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('a')->second << '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';

  return 0;
}
