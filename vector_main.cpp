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
	ft::vector<Buffer> vector_buffer;

	for (int i = 0; i < COUNT; i++)
	{
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
	
	std::cout << std::endl;
	{
		ft::vector<std::string> vector_str;
		ft::vector<int> vector_int;
		ft::vector<int> vector_int2;
		
		for (unsigned long i = 0; i < 51; i++)
		{
			vector_int.push_back((static_cast<int>(i) + 60) % 70);
		}
	
		for (unsigned long i = 0; i < 10; i++)
		{
			vector_int2.push_back(static_cast<int>(i));
		}

		std::cout << MAGENTA << "\n[AFTER PUSH_BACKS]" << RESET << std::endl;
		std::cout << "size of vector = " << vector_int.size() << " || max_size = " << vector_int.max_size() <<  std::endl;
	
		for (unsigned long i = 0; i < vector_int.size(); i++)
		{
			std::cout << i << ": " << vector_int[i];
			if (i % 10 == 9)
				std::cout << std::endl;
			else
				std::cout << " |##| ";
		}

		ft::randomAccessIterator<int> it = vector_int.begin();
	
		vector_int.insert(it, (size_t)15, 10);

		it = vector_int.begin() + 5;
		vector_int.insert(it, (size_t)30, 0);


		std::cout << MAGENTA << "\n\nAFTER INSERT" << RESET << std::endl;
		for (unsigned long i = 0; i < vector_int.size(); i++)
		{
			std::cout << i << " : " << vector_int[i];
			if (i % 10 == 9)
				std::cout << std::endl;
			else
				std::cout << " |##| ";
		}

		std::cout << MAGENTA << "\n\nAFTER SWAP" << RESET << std::endl;
		vector_int.swap(vector_int2);

		for (unsigned long i = 0; i < vector_int.size(); i++)
		{
			std::cout << i << " : " << vector_int[i];
			if (i % 10 == 9)
				std::cout << std::endl;
			else
				std::cout << " |##| ";
		}

		{
			std::cout << MAGENTA << "\n\n[COMPARAISONS]" << RESET << std::endl;
			std::cout << "size of vector_int = " << vector_int.size() << ", of vector_int2 = " << vector_int2.size() << std::endl;
			bool comparisons[6];
			std::string signs[6];

			comparisons[0] = (vector_int < vector_int2);
			signs[0] = "<";

			comparisons[1] = (vector_int <= vector_int2);
			signs[1] = "<=";
		
			comparisons[2] = (vector_int > vector_int2);
			signs[2] = ">";

			comparisons[3] = (vector_int >= vector_int2);
			signs[3] = ">=";

			comparisons[4] = (vector_int == vector_int2);
			signs[4] = "==";

			comparisons[5] = (vector_int != vector_int2);
			signs[5] = "!=";

			for (int i = 0; i < 6; i++)
			{
				std::cout << MAGENTA << signs[i] << " ";
				if (comparisons[i])
					std::cout << GREEN << "true";
				else
					std::cout << RED << "false";
				std::cout << RESET << std::endl;
			}
		}
	}
	return (0);
}
