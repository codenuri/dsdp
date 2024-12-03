#include <string>
#include <iostream>

// C++ 표준의 문자열 클래스는 아래와 같습니다.
template<typename T,  // char, wchar_t, char16 등의 문자열 종류(유니코드 고려)
		 typename Traits = std::char_traits<T>, // 비교 정책
		 typename Alloc = std::allocator<T>>    //  메모리 할당
class basic_string
{
	T* buff;
	Alloc ax; // 메모리 할당이 필요할때 ax 사용

public:
	// 문자열 비교
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

	// 결과 예측해 보세요

	if (s1 == s2)
		std::cout << "same\n";
	else 
		std::cout << "not same\n";
}