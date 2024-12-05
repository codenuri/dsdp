#include <iostream>
#include <vector>

// �տ��� ���� take_view ���� ����(�����̳ʸ� �ٶ� ���� ���ѵ� �ð�, ���纻��������)
// �� C++, Java, C# � ��� �ֽ��ϴ�.
// C++ : Range  (C++20 ����) - C++��� 20���� �����ϼ���
// C#  : LINQ
// Java : Stream 

#include <ranges>

namespace RG = std::ranges;

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };


//	for (auto e : RG::take_view(v, 3))
//	for (auto e : RG::reverse_view(v))
	for (auto e : RG::reverse_view( RG::take_view(v, 3) ) )
	{
		std::cout << e << ", ";
	}

}