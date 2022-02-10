#include <iostream>
#include <string>
#include "templates/containers/vector.hpp"

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

		ft::vector<int>::iterator it = vector_int.begin();
	
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
			std::cout << MAGENTA << "\n\n[BACK FRONT DATA EMPTY]" << RESET << std::endl;
			std::cout << MAGENTA << "back : " << RESET << vector_int.back() << std::endl;
			std::cout << MAGENTA << "front : " << RESET << vector_int.front() << std::endl; 
			std::cout << MAGENTA << "data : " << RESET << vector_int.data() << std::endl;
			std::cout << MAGENTA << "empty : " << RESET;
			if (vector_int.empty())
					std::cout << GREEN << "true";
			else
				std::cout << RED << "false";
			std::cout << RESET << std::endl;
		}

		{
			std::cout << MAGENTA << "\n\nTEST OF CLEAR" << RESET << std::endl;
			ft::vector<int> myvector;
			myvector.push_back (100);
			myvector.push_back (200);
			myvector.push_back (300);

			std::cout << "myvector contains:";
			for (unsigned i=0; i<myvector.size(); i++)
				std::cout << ' ' << myvector[i];
			std::cout << '\n';

			myvector.clear();
			myvector.push_back (1101);
			myvector.push_back (2202);

			std::cout << "myvector contains:";
			for (unsigned i=0; i<myvector.size(); i++)
				std::cout << ' ' << myvector[i];
			std::cout << '\n';
		}
		{
			std::cout << MAGENTA << "\n\nTEST OF EMPTY" << RESET << std::endl;
			ft::vector<int> myvector;
			int sum (0);

			for (int i=1;i<=10;i++)
				myvector.push_back(i);

			while (!myvector.empty())
			{
				sum += myvector.back();
				myvector.pop_back();
			}

			std::cout << "total: " << sum << '\n';
		}

		{
			std::cout << MAGENTA << "\n\nTEST OF ASSIGN" << RESET << std::endl;
			ft::vector<int> first;
			ft::vector<int> second;
			ft::vector<int> third;
			try
			{
				first.assign(7, 100);
				ft::vector<int>::iterator it;
				it = first.begin() + 1;

				second.assign(it, first.end()-1); // the 5 central values of first

				int myints[] = {1776,7, 4};
				third.assign(myints, myints + 3);   // assigning from array.
			}
			catch(const std::exception& e)
			{
				std::cerr << "DONTKNOW - " << e.what() << '\n';
			}
			std::cout << "Size of first: " << int (first.size()) << '\n';
			std::cout << "Size of second: " << int (second.size()) << '\n';
			std::cout << "Size of third: " << int (third.size()) << '\n';
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
		{
			std::cout << MAGENTA << "\n\nTEST OF ERASE" << RESET << std::endl;
			ft::vector<int> myvector;

			for (int i=1; i<=10; i++) myvector.push_back(i);

			myvector.erase (myvector.begin()+5);
			myvector.erase (myvector.begin(),myvector.begin()+3);

			std::cout << "myvector contains:";
			for (unsigned i=0; i<myvector.size(); ++i)
				std::cout << ' ' << myvector[i];
			std::cout << '\n';
		}
		{
			std::cout << MAGENTA << "\n\nTEST OF RBEGIN" << RESET << std::endl;
			ft::vector<int> myvector(5, 0);

			ft::vector<int>::reverse_iterator rit = myvector.rbegin();
			//int i = 0;
			/*for (; rit!= myvector.rend(); rit++)
				*rit = ++i;*/
			
			/*std::cout << "myvector contains:";
			for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
				std::cout << ' ' << *it;*/
		}
		{
			std::cout << MAGENTA << "\n\nCAPACITY AND MAX_SIZE" << RESET << std::endl;
			ft::vector<int> myvector;

			// set some content in the vector:
			for (int i=0; i<100; i++) myvector.push_back(i);

			std::cout << "size: " << (int) myvector.size() << '\n';
			if (myvector.capacity() >= myvector.size())
				std::cout << "capacity: is fine\n";
			else
				std::cout << "capcity is not fine : " << myvector.capacity() << '\n';
			if (myvector.max_size() > 10000)
				std::cout << "max_size is fine\n";
		}
	}
	return (0);
}
