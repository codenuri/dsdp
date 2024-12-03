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
		std::cout << "������ �����ؼ� "
			<< url << "�� ���� IP ���� �����\n";

		std::this_thread::sleep_for(std::chrono::seconds(3));

		return "100.100.100.100";
	}
};

// DNS Ŭ������ ��� �ؼ� ����Ҽ� �ִ� Ŭ������ ����� ���ô�.
class DNSProxy : public IDNS
{
public:
	std::string resolve(const std::string& url)
	{
		// ���� ��û�� URL �� local pc �� ĳ��(���ϵ�)�� �ִ��� ����
		// �ؼ� �ִٸ� �ش� ������ ��ȯ
		if (url == "www.samsung.com")
		{
			return "200.200.200.200";
		}

		// ��û�� URL �� ����(ĳ��)�� ��������
		// ������ �����ؼ� IP�� ��� �´�.
		DNS dns;
		return dns.resolve(url);		
	}
};


int main()
{
	DNS dns;

	std::cout << dns.resolve("www.samsung.com") << std::endl;
}