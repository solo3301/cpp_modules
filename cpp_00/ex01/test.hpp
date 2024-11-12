#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>
# include <string>

class Student {
	private:
		std::string name;
		int age;

	public:
		Student() : name("none"), age(0) {}
		void Show();
		void ChangeAge(int newAge);
		void ChangeName(std::string newName);
};

#endif
