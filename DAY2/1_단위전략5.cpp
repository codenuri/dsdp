#include <iostream>
#include <vector>

// STL �� �����ϱ� ���� ����� ���� allocator(�޸� �Ҵ��) Ŭ����
// #1. �ݵ�� ���ø��� �ʿ�� ������, �پ��� Ÿ���� �޸� �Ҵ��� ���ؼ�
//     ��κ� ���ø����� �ۼ�

template<typename T> class debug_alloc
{
public:

};


int main()
{
//	std::vector<int> v;			// �� �ڵ��
//	std::vector<int, std::allocator<int>> v; // �ᱹ �� �ڵ��Դϴ�.

	std::vector<int, debug_alloc<int> > v;


	std::cout << "-----------------" << std::endl;

	v.resize(4);

	std::cout << "-----------------" << std::endl;

	v.resize(8);

	std::cout << "-----------------" << std::endl;
}
