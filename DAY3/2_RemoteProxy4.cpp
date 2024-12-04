#define USING_GUI
#include "cppmaster.h"

// 클라이언트 개발자는 서버 개발자에게 2개의 파일을 받아야 합니다.
// ICalc.h       : 인터페이스가 담긴 헤더
// CalcProxy.dll : Proxy 가 담긴 동적모듈 파일

#include "ICalc.h"

ICalc* load_proxy()
{
	// #1. DLL 을 Load 합니다
	void* addr = ec_load_module("CalcProxy.dll");
					// linux : dlopen()    windows : LoadLibrary()

	// #2. DLL 에서 약속된 함수를 찾습니다.
	typedef ICalc* (*F)();

	F f = (F)ec_get_function_address(addr, "create");
					// linux : dlsym()		windows : GetProcAddress()

	// #3. 약속된 함수로 Proxy 객체 생성후 반환

	return f();
}


int main()
{
	ICalc* calc = new ? ;  

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





