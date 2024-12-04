// ICalc.h
#pragma once

struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};



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
