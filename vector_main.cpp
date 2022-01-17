#include <iostream>
#include <string>
#include <deque>

#include <vector>
#include "templates/vector.hpp"

#include <stdlib.h>

#define MAX_RAM 215000
#define BUFFER_SIZE 4096

struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed " << std::endl;
		std::cerr << "Provide a seed please " << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}

	const int seed = atoi(argv[1]);
	srand(seed);
	/*ft::vector<Buffer> vector_buffer;

	for (int i = 0; i < COUNT; i++)
	{
		std::cout << i << ": "; 
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTYls " <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "good, it has to be empty" << std::endl;
	}
	*/
	std::cout << std::endl;
	{
		ft::vector<std::string> vector_str;
		ft::vector<int> vector_int;
		
		for (unsigned long i = 0; i < 52; i++)
		{
			vector_int.push_back((static_cast<int>(i) + 60) % 70);
		}
		std::cout << "\nAFTER PUSH_BACKS" << std::endl;
		for (unsigned long i = 0; i < vector_int.size(); i++)
		{
			std::cout << i << ": " << vector_int[i] << std::endl;
		}

		ft::randomAccessIterator<int> it = vector_int.begin();

		vector_int.insert(it, 10);

		it = vector_int.begin();

		std::cout << "\nAFTER INSERT" << std::endl;
		for (unsigned long i = 0; i < vector_int.size(); i++)
		{
			std::cout << i << ": " << vector_int[i] << std::endl;
		}
	}
	return (0);
}
