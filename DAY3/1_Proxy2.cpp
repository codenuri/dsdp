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
		if (url == "www.samsung.com") // url ������ local ���Ͽ� �ִ�������
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
//	DNS dns;		// �׻� ������ ����(�ð� �ɸ�)
	DNSProxy dns;	// �ʿ��Ҷ��� ������ ����

	std::cout << dns.resolve("www.samsung.com") << std::endl;
}
// Proxy ���� : �پ��� ������ �����ڸ� ����� ����

// DNSProxy : DNS �� ĳ�� ����� �߰��ϱ� ���� ������

// �׷��� ? �ᱹ ����� �߰� �ƴѰ��� ??
// => Decorator �� �� �������� ������ ?

// Decorator 
FileStream fs("a.txt"); // origin ��ü�� ���� �����
ZipDecorator zd(&fs);	// ���Ŀ� ��ü�� ��� �߰�
zd.write("hello");		// ��� �߰��� ����ص� �ǰ�
fs.write("hello");		// origin �� ���� ����� �˴ϴ�.
					// ZipDecorator �� FileStream �� ����ϴ°��� �ƴ� 

// Proxy 
//DNS dns;	// �̰��� ������� ����
DNSProxy dns;	// �̰��� ����϶�� ��
				// ��, origin ��ü�� ����ϱ� ���Ѱ�
				// Proxy �� ���������� origin �� �����ϴ� ��찡����.