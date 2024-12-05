// 참고
class Sample
{
	inline static int value = 10;
	using DWORD = int;
};

int p = 0;

template<typename T>
void foo()
{
	// 아래 코드에서 * 의 의미를 생각해 보세요
	Sample::value* p;
	Sample::DWORD* p;
}