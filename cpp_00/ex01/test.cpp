#include "test.hpp"

void Student::Show() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << age << std::endl;
}

void Student::ChangeAge(int newAge) {
	if (newAge > 0)
		age = newAge;
	else
		std::cout << "Incorrect age" << std::endl;
}

void Student::ChangeName(std::string newName) {
	name = newName;
}

int main ()
{
	Student demian;

	demian.ChangeName("Demian");
	demian.ChangeAge(-23);

	demian.Show();
	return 0;
}
