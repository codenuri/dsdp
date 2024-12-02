#include <iostream>
#include <string>
#include <conio.h>

// validation ��å�� �����Ҽ� �־�� �մϴ�.


class Edit
{
	std::string data;
public:

	// ���뼺�� �������� �и�
	// => ������ ���� �ڵ� ���ο� �ִ� ���ؾ� �ϴ� �κ��� ã�Ƽ� �и��Ѵ�.
	// => ���ϴ� ���� �����Լ��� �и� �մϴ�

	virtual bool validate(char c)
	{
		return true;
	}

	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); 

			if (c == 13) break;

//			if (isdigit(c))  // ������ ���� �ڵ� ���ο� ���ؾ� �ϴ� �κ�
			if (validate(c)) // �����Լ��� ����ؼ� validation ����
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// �� �ڵ��� �ǵ�
// Edit �� �Ļ� Ŭ������ ���� validate �� override �ϸ�
// validation ��å�� �����Ҽ� �ִ�.
class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
//	Edit e;
	NumEdit e;
//	AdressEdit e2; // �ٸ� ��å�� ���� ���ο� edit

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


