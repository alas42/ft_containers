#include <iostream>
#include <string>
#include <deque>

#include <vector>

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

	std::vector<std::string> std_vector_str;
	std::vector<int> std_vector_int;
	std::vector<Buffer> std_vector_buffer;
	
	for (int i = 0; i < COUNT; i++)
	{
		std_vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		std_vector_buffer[idx].idx = 5;
	}
	
	std::vector<Buffer>().swap(std_vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			std_vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTYls " <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}

	std::cout << std::endl;
	
	return (0);
}
