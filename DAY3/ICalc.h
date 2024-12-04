// ICalc.h
#pragma once

// ���۷��� ī����(�������) ������� Proxy�� ������ �����ϴ� ���
// ������� ���� �Լ��� �������̽����� �־�� �մϴ�.

struct IRefCount
{
	virtual void AddRef() = 0;
	virtual void Release() = 0;

	virtual ~IRefCount() {}
};

struct ICalc : public IRefCount
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

/*
struct IMoterServerProxy : public IRefCount
{
	// ���� ���� ���� �Լ�
};
*/




ICalc* load_proxy()
{
	// #1. DLL �� Load �մϴ�
	void* addr = ec_load_module("CalcProxy.dll");
	// linux : dlopen()    windows : LoadLibrary()

// #2. DLL ���� ��ӵ� �Լ��� ã���ϴ�.
	typedef ICalc* (*F)();

	F f = (F)ec_get_function_address(addr, "create");
	// linux : dlsym()		windows : GetProcAddress()

// #3. ��ӵ� �Լ��� Proxy ��ü ������ ��ȯ

	return f();
}
