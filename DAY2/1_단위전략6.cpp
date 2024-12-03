#include <string>
#include <iostream>

/*
// C++ ǥ���� ���ڿ� Ŭ������ �Ʒ��� �����ϴ�.
template<typename T,  // char, wchar_t, char16 ���� ���ڿ� ����(�����ڵ� ���)
		 typename Traits = std::char_traits<T>, // �� ��å
		 typename Alloc = std::allocator<T>>    //  �޸� �Ҵ�
class basic_string
{
	T* buff;
	Alloc ax; // �޸� �Ҵ��� �ʿ��Ҷ� ax ���

public:
	// ���ڿ� ��
	bool operator==(const std::basic_string& other)
	{
		return Traits::compare(buff, other.buff); 
	}

};
using string = std::basic_string<char>;
*/

// ���ڿ� �� ��å�� ���� Ŭ����
// C++ǥ�ع����� �ִ� �䱸 ���Ǵ�� ������ �մϴ�.
// (cppreference.com ���� string �˻�)

struct MyTraits : public std::char_traits<char>
{
    static char to_upper(char ch)
    {
        return std::toupper((unsigned char)ch);
    }

    static bool eq(char c1, char c2)
    {
        return to_upper(c1) == to_upper(c2);
    }

    static bool lt(char c1, char c2)
    {
        return to_upper(c1) < to_upper(c2);
    }

    static int compare(const char* s1, const char* s2, std::size_t n)
    {
        while (n-- != 0)
        {
            if (to_upper(*s1) < to_upper(*s2))
                return -1;
            if (to_upper(*s1) > to_upper(*s2))
                return 1;
            ++s1;
            ++s2;
        }
        return 0;
    }

    static const char* find(const char* s, std::size_t n, char a)
    {
        const auto ua{ to_upper(a) };
        while (n-- != 0)
        {
            if (to_upper(*s) == ua)
                return s;
            s++;
        }
        return nullptr;
    }
};

// ���ڿ� ����å�� �����ϴ� �ڵ�
using ci_string = std::basic_string<char, MyTraits>;

int main()
{
//  std::string s1 = "ABCD";
//  std::string s2 = "abcd";

	ci_string s1 = "ABCD";
	ci_string s2 = "abcd";

	// ��� ������ ������

	if (s1 == s2)
		std::cout << "same\n";
	else 
		std::cout << "not same\n";
}