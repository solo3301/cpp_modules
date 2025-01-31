#include "../includes/Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
	std::cout << "SHOULD NOT SHOW ANY ERRORS UP TO THIS POINT!!!\n";
    try
    {
		std::cout << "\nLet's try to turn to the -2 index:\n";
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
		std::cout << "\nAttempting to write to numbers[750] (outside MAX_VAL):\n";
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	// 
	//CHECKING THE OPERATOR '[]'
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

	//try
	//{
		//Array<int> numbers(5);
		//for (size_t i = 0; i < numbers.size(); i++)
			//numbers[i] = i * 2;
		//std::cout << "Array element: ";
		//for (size_t i = 0; i < numbers.size(); i++)
			//std::cout << numbers[i] << " ";
		//std::cout << std::endl;

		//std::cout << "Accesing out-of-bounds index: ";
		//std::cout << numbers[10] << std::endl;
	//}
	//catch (const std::exception& e)
	//{
		//std::cerr << "Egeption: " << e.what() << std::endl;
	//}

	//Array<std::string> strings(3);
	//strings[0] = "hello";
	//strings[1] = "42";
	//strings[2] = "lisboa";

	//Array<std::string> copy = strings;
	//std::cout << "\nCopyed array: ";
	//for (size_t i = 0; i < copy.size(); i++)
		//std::cout << copy[i] << " ";
	//std::cout << std::endl;

    return 0;
}
