#include <iostream>
#include <vector>

// STL 에 전달하기 위한 사용자 정의 allocator(메모리 할당기) 클래스
// #1. 반드시 템플릿일 필요는 없지만, 다양한 타입의 메모리 할당을 위해서
//     대부분 템플릿으로 작성

template<typename T> class debug_alloc
{
public:

};


int main()
{
//	std::vector<int> v;			// 이 코드는
//	std::vector<int, std::allocator<int>> v; // 결국 이 코드입니다.

	std::vector<int, debug_alloc<int> > v;


	std::cout << "-----------------" << std::endl;

	v.resize(4);

	std::cout << "-----------------" << std::endl;

	v.resize(8);

	std::cout << "-----------------" << std::endl;
}
