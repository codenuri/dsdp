#include <iostream>
#include <vector>
#include <ranges>


int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// �Ʒ� �ǹ� ������ ������
	std::ranges::take_view tv(v, 3);
	std::ranges::filter_view fv(tv, [](int n) { return n % 2 == 1; });

	// �Ʒ� ������ �� �ڵ�� ������ �����մϴ�.

	auto fv2 = v | std::views::take(3) | std::views::filter(�� ����);


	for (auto e : fv2 )
	{
		std::cout << e << ", ";
	}

}