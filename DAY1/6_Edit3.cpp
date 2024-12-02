#include <iostream>
#include <string>
#include <conio.h>


// ���ϴ� �ڵ带 �и��ϴ� 2���� ���

// 1. ���ϴ� ���� �����Լ��� - template method ����, Edit2.cpp
// 2. ���ϴ� ���� �ٸ� Ŭ������ - strategy ����,     Edit3.cpp

// ��� Validator �� ���Ѿ� �ϴ� ������ �������̽� (��Ģ)���� ����

struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true; }

	virtual ~IValidator() {}
};

// �ֹ� ��� ��ȣ : 961  1      Ȯ��




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



// �Է°��� ��ȿ���� �����ϴ� Ŭ����

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

int main()
{
	Edit e;

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


