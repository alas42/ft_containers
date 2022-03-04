/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:07:47 by hbaudet           #+#    #+#             */
/*   Updated: 2021/01/18 16:06:03 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include "map.hpp"

template <class Key, class T>
void	print(ft::map<Key, T>& lst)
{
	for (typename ft::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}

int main()
{
	ft::pair<int, std::string>			my_pair(746, "salut");
	ft::map<int, std::string>			test;
	ft::map<int, std::string>::iterator	it;

	test.insert(my_pair);
	test.insert(ft::pair<int, std::string>(-4, "bar"));
	test.insert(ft::pair<int, std::string>(2, "machin"));
	test.insert(ft::pair<int, std::string>(3, "foo"));
	test.insert(ft::pair<int, std::string>(800, "Marcel"));
	test.insert(ft::pair<int, std::string>(1, "truc"));
	it = test.begin();

	while (it != test.end())
	{
		// std::cout << "start of while\n";
		std::cout << it->first << ", " << it->second << '\n';
		it++;
// 		std::cout << "iterator incremented\n";

// #ifndef STD
// 		std::cout << it.getPointer() << '\n';
// 		std::cout << test.end().getPointer() << '\n';
// #endif

	}
	std::cout << "End of display loop\n";
}
