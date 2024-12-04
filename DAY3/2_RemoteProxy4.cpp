#define USING_GUI
#include "cppmaster.h"

// Ŭ���̾�Ʈ �����ڴ� ���� �����ڿ��� 2���� ������ �޾ƾ� �մϴ�.
// ICalc.h       : �������̽��� ��� ���
// CalcProxy.dll : Proxy �� ��� ������� ����

#include "ICalc.h"

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


int main()
{
	ICalc* calc = new ? ;  

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





