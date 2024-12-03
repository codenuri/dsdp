#include <iostream>
#include <string>
#include <thread>
#include <chrono>

struct IDNS
{
	virtual std::string resolve(const std::string& url) = 0;
	virtual ~IDNS() {}
};

class DNS : public IDNS
{
public:
	std::string resolve(const std::string& url)
	{
		std::cout << "서버에 접속해서 "
			<< url << "에 대한 IP 정보 얻는중\n";

		std::this_thread::sleep_for(std::chrono::seconds(3));

		return "100.100.100.100";
	}
};

// DNS 클래스를 대신 해서 사용할수 있는 클래스를 만들어 봅시다.
class DNSProxy : public IDNS
{
public:
	std::string resolve(const std::string& url)
	{
		// 현재 요청한 URL 이 local pc 에 캐쉬(파일등)에 있는지 조사
		// 해서 있다면 해당 정보를 반환
		if (url == "www.samsung.com")
		{
			return "200.200.200.200";
		}

		// 요청된 URL 이 파일(캐쉬)에 없을때만
		// 서버에 접속해서 IP를 얻어 온다.
		DNS dns;
		return dns.resolve(url);		
	}
};


int main()
{
	DNS dns;

	std::cout << dns.resolve("www.samsung.com") << std::endl;
}