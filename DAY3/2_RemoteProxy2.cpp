#define USING_GUI
#include "cppmaster.h"

// 아래 클래스는 "서버를 대신" 하기 위한 클래스입니다.

class Calc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); };
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); };
};


int main()
{
	// 위 클래스는 서버 개발자가 만들어주는 클래스 입니다.
	// 서버를 대신하는 "Proxy" 입니다.
	// 이제 클라이언트 개발자는 실제 서버에 접속하지말고 Proxy 를 사용합니다
	Calc* calc = new Calc;
	
	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





