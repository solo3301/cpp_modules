#include "../includes/Array.hpp"

int main(int, char**)
{
	try
	{
		Array<int> numbers(5);
		for (size_t i = 0; i < numbers.size(); i++)
			numbers[i] = i * 2;
		std::cout << "Array element: ";
		for (size_t i = 0; i < numbers.size(); i++)
			std::cout << numbers[i] << " ";
		std::cout << std::endl;

		std::cout << "Accesing out-of-bounds index: ";
		std::cout << numbers[10] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Egeption: " << e.what() << std::endl;
	}

	Array<std::string> strings(3);
	strings[0] = "hello";
	strings[1] = "42";
	strings[2] = "lisboa";

	Array<std::string> copy = strings;
	std::cout << "\nCopyed array: ";
	for (size_t i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
	std::cout << std::endl;
}
