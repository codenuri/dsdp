#include <string>
#include <iostream>

int main()
{
	std::string s1 = "ABCD";
	std::string s2 = "abcd";

	// ��� ������ ������

	if (s1 == s2)
		std::cout << "same\n";
	else 
		std::cout << "not same\n";
}