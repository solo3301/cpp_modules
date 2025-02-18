#include "../includes/Span.hpp"

int main()
{
	try
	{
		Span sp(5);
		sp.addNumber(10);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		sp.printNumbers();

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		// Test for adding more than you can
		std::cout << "Adding extra number (should throw error)..." << std::endl;
		sp.addNumber(42);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	//If there are less than 2 numbers in the container.
	try
	{
		Span smallSpan(1);
		smallSpan.addNumber(100);
		std::cout << "Shortest span: " << smallSpan.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// Adding numbers through a range
	try
	{
		Span bigSpan(10);
		std::vector<int> values;
		values.push_back(100);
		values.push_back(50);
		values.push_back(75);
		values.push_back(25);
		values.push_back(5);
		bigSpan.addNumbers(values.begin(), values.end());
		bigSpan.printNumbers();
		std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}

/*int main()*/
/*{*/
/*	Span sp = Span(5);*/
/*	sp.addNumber(6);*/
/*	sp.addNumber(3);*/
/*	sp.addNumber(17);*/
/*	sp.addNumber(9);*/
/*	sp.addNumber(11);*/
/**/
/*	std::cout << sp.shortestSpan() << std::endl;*/
/*	std::cout << sp.longestSpan() << std::endl;*/
/**/
/*	return 0;*/
/*}*/
