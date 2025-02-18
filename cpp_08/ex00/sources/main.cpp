#include "../includes/easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	try
	{
		std::vector<int> numbers;

		numbers.push_back(10);
		numbers.push_back(20);
		numbers.push_back(30);
		numbers.push_back(40);

		std::vector<int>::iterator it;
		std::cout << "Searching for 30 in vector..." << std::endl;
		it = easyfind(numbers, 30);
		std::cout << "Found: " << *it << std::endl;

		std::cout << "Searching for 50 in vector..." << std::endl;
		it = easyfind(numbers, 50);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::list<int> myList;

		myList.push_back(100);
		myList.push_back(200);
		myList.push_back(300);
		myList.push_back(400);

		std::list<int>::iterator it;
		std::cout << "\nSearching for 300 in list..." << std::endl;
		it = easyfind(myList, 300);
		std::cout << "Found: " << *it << std::endl;
		
		std::cout << "searching 500 in list..." << std::endl;
		it = easyfind(myList, 500);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
