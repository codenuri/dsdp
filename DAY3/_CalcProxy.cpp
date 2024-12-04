#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); };
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); };
};

// DLL �����(Ŭ���̾�Ʈ �����ڴ�) DLL ������ Proxy �� �̸���
// ������ ���ϰ�, ���ʿ䵵 ����, ����ص� �ȵ˴ϴ�. - ���Ѱ����� ���ؼ�
// DLL ���ο� ��ӵ� �Լ��� ����� Proxy ��ü�� �����ؾ� �մϴ�.
extern "C" __declspec(dllexport)
ICalc* create()
{
	return new Calc;
}

// ������ �̸��� ����ҰͶ�� "Calc" Ŭ���� �̸�����ϸ� �ȵǳ��� ?
// => Ŭ���̾�Ʈ�� "new Calc" �ؾ� �ϴµ�.. 
// new Calc : Calc Ŭ���� ��ü�� ��� ����(ICalc �� �ƴϰ� Calc) �� �ʿ�
//            Proxy Update �Ǹ� Calc ����� ����ɼ� �ֽ��ϴ�
//            �׷��� Ŭ���̾�Ʈ�� "�ٽ� ����" �Ǿ�� �մϴ�.

// create �̸� ��� : Ŭ���̾�Ʈ�� "�ٽ� ����" �� �ʿ� �����ϴ�.
//============================================
// ���� �ϴ� �� 
// ������ C++ �����Ϸ� : g++
// ������ C++ �����Ϸ� : cl.exe
// => ���� ��ư => "developer ... " �˻��ϸ� ������ â ����
// => ���� �ҽ��� �ִ� ������ �̵� (cd ���)

// => cl CalcProxy.cpp /LD   �� �����ϸ� "CalcProxy.dll" �����˴ϴ�.
// 
// => "/LD" �ɼ��� DLL �� �����϶�� �ɼ�

