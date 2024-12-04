#define USING_GUI
#include "cppmaster.h"

// Ŭ���̾�Ʈ �����ڴ� ���� �����ڿ��� 2���� ������ �޾ƾ� �մϴ�.
// ICalc.h       : �������̽��� ��� ���
// CalcProxy.dll : Proxy �� ��� ������� ����

#include "ICalc.h"


int main()
{
	ICalc* calc = load_proxy();  

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





