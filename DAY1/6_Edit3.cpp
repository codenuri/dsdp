#include <iostream>
#include <string>
#include <conio.h>


// 변하는 코드를 분리하는 2가지 방법

// 1. 변하는 것을 가상함수로 - template method 패턴, Edit2.cpp
// 2. 변하는 것을 다른 클래스로 - strategy 패턴,     Edit3.cpp


// 입력값의 유효성을 조사하는 클래스

class LimitDigitValidator
{
	int limit;
public:
	LimitDigitValidator(int n) : limit(n) {}

	bool validate(const std::string& s, char c)
	{
		return s.size() < limit && isdigit(c);
	}
};


class Edit
{
	std::string data;
public:
	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); 

			if (c == 13) break;

			if (isdigit(c))
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

int main()
{
	Edit e;

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


