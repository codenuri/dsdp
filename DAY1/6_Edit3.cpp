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

	IValidator* val = nullptr;
public:
	void set_validator(IValidator* p) { val = p; }



	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); 

			if (c == 13 && (val == nullptr || val->is_complete(data) )  ) break;

			if ( val == nullptr || val->validate(data, c) ) // ���� ��ȿ�� ���� �Ǵ���
			{												// �ٸ� ��ü�� ����
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};



// �Է°��� ��ȿ���� �����ϴ� Ŭ����

class LimitDigitValidator : public IValidator
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

	LimitDigitValidator v(5);

	e.set_validator(&v); // e ��ü�� "���� ��ȿ���� üũ�ϴ� ��ü ����"


	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


