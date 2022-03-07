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
#include <map>
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
	std::map<int, std::string>			std_test;
	/*ft::map<int, std::string>::iterator	it;

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
	}
	*/
	std::cout << "stl::max_size() = " << std_test.max_size() << std::endl;
	std::cout << "ft::max_size() = " << test.max_size() << std::endl;
	std::cout << "End of display loop\n";
}
