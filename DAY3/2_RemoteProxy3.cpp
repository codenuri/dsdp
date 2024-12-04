#define USING_GUI
#include "cppmaster.h"



// Proxy �� �پ��ϰ� Update(��ü)�ɼ� �ֽ��ϴ�.
// ��Ģ(�������̽�)�� ���� ����
struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};


class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); };
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); };
};

int main()
{
	// �Ʒ� ó���ϸ� Proxy �� Client ���̿� ���Ѱ��մϴ�.
	// Proxy �� Update �Ǹ� Client �� �����Ǿ�� �մϴ�.
	// Calc* calc = new Calc;

	// ���Ѱ������� ����ؾ� �մϴ�.
	ICalc* calc = new ? ;

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





