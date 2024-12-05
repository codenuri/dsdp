#include <iostream>
#include <vector>

// �Ʒ� Ŭ������ �� ������ ������
template<typename T> class take_view
{
	T& rng;
	int cnt;
public:
	take_view(T& r, int c) : rng(r), cnt(c) {}

	auto begin() { return rng.begin(); }
	auto end() { return rng.begin() + cnt; }
};

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	take_view tv(v, 3);

//	for (auto e : v)
	for (auto e : tv)
	{
		std::cout << e << ", ";
	}

}