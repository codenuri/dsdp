#include <string>
#include <iostream>

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