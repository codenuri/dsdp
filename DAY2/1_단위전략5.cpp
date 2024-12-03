#include <iostream>
#include <vector>

// STL �� �����ϱ� ���� ����� ���� allocator(�޸� �Ҵ��) Ŭ����
// #1. �ݵ�� ���ø��� �ʿ�� ������, �پ��� Ÿ���� �޸� �Ҵ��� ���ؼ�
//     ��κ� ���ø����� �ۼ�

// #2. �ݵ�� ��ӵ� �Լ��� ������ �մϴ�.
//     (cppreference.com ���� ȭ�� ���ʿ� "Named Requirement" ����)

template<typename T> class debug_alloc
{
public:
	inline T* allocate(std::size_t sz)
	{
		void* p = malloc(sizeof(T) * sz);

		printf("[debug_alloc] allocate %p, %d cnts\n", p, sz);
		
		return static_cast<T*>(p);
	}

	inline void deallocate(T* p, std::size_t sz)
	{
		printf("[debug_alloc] deallocate %p, %d cnts\n", p, sz);

		free(p);
	}

	// �� 2���� �ٽ��̰�, �Ʒ� 3���� ���ʿ��մϴ�. �������� �ڵ�
	// �׻� �����ؼ� ����ϸ� �˴ϴ�.
	using value_type = T;

	debug_alloc() {}

	template<typename U> debug_alloc(const debug_alloc<U>&) {}
							// generic ������ ����. 
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
