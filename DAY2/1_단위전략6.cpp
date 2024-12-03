#include <string>
#include <iostream>

int main()
{
	std::string s1 = "ABCD";
	std::string s2 = "abcd";

	// 결과 예측해 보세요

	if (s1 == s2)
		std::cout << "same\n";
	else 
		std::cout << "not same\n";
}