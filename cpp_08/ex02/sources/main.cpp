#include "../includes/MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "Testing MutantStack:\n";
	MutantStack<int> ms;
	ms.push(5);
	ms.push(17);
	std::cout << "Top element: " << ms.top() << std::endl;
	ms.pop();
	std::cout << "Stack size after pop: " << ms.size() << std::endl;
	ms.push(3);
	ms.push(7);
	ms.push(0);
	ms.push(9);
	std::cout << "Stack elements: ";
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\nTest std::list\n";
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Last element: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "List size after pop: " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(7);
	lst.push_back(0);
	lst.push_back(9);
	std::cout << "List elemants: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}

/*int main()*/
/*{*/
/*	MutantStack<int> mstack;*/
/*	mstack.push(5);*/
/*	mstack.push(17);*/
/*	std::cout << "Top: " << mstack.top() << std::endl;*/
/*	mstack.pop();*/
/*	std::cout << "Size: " << mstack.size() << std::endl;*/
/*	mstack.push(3);*/
/*	mstack.push(5);*/
/*	mstack.push(737);*/
/*	//[...]*/
/*	mstack.push(0);*/
/*	MutantStack<int>::iterator it = mstack.begin();*/
/*	MutantStack<int>::iterator ite = mstack.end();*/
/*	++it;*/
/*	--it;*/
/*	while (it != ite)*/
/*	{*/
/*		std::cout << *it << std::endl;*/
/*		++it;*/
/*	}*/
/*	std::stack<int> s(mstack);*/
/*	return 0;*/
/*}*/
