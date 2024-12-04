#include <iostream>

int main()
{
	char sa1[] = "hello";
	char sa2[] = "hello";

	const char* sp1 = "hello";
	const char* sp2 = "hello";

	// 아래 결과 예측해 보세요(같은 주소? 다른 주소)
	printf("%p\n", sa1);
	printf("%p\n", sa2);

	printf("%p\n", sp1);
	printf("%p\n", sp2);

}

// 읽기 전용 문자열이 필요 하면
// => 문자열 배열 보다 문자열 포인터 권장(공유 됩니다.)

// 대부분의 언어에 읽기 전용 문자열은 공유할수 있는 기능이 있습니다.

// RUST
// String : 문자열을 소유하는 타입
// str    : 문자열을 가리키는 타입(문자열 포인터 개념)

// s1 : String  = "hello";  // s1 이 hello 문자열 소유(힙)
// s2 : str = "hello";      // 상수메모리의 문자열을 s2가 가리킵
//							// const char* s2 = "hello"