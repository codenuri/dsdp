#define USING_GUI
#include "cppmaster.h"

// 아래 클래스는 "서버를 대신" 하기 위한 클래스입니다.

class Calc
{
	int server;
public:
	Calc() { }

	int Add(int a, int b) { return ? };
	int Sub(int a, int b) { return ? };
};


int main()
{
	// 1. 서버의 핸들을 얻어 옵니다.
	int server = ec_find_server("Calc");


	std::cout << "서버 번호 : " << server << std::endl;

	// 2. 서버에 명령코드와 파라미터를 전달합니다.
	int n1 = ec_send_server(server, 1, 10, 20); // 10 + 20 요청
	int n2 = ec_send_server(server, 2, 10, 20); // 10 - 20 요청

	std::cout << n1 << ", " << n2 << std::endl;

}





