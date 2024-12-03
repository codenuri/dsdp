#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Stream
{
	virtual void write(const std::string& s) = 0;
	virtual ~Stream() {}
};

class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void write(const std::string& s)
	{
		printf("%s ����\n", s.c_str());
	}
};

int main()
{
	// ���Ͽ� ���� ��ȣȭ �ϴ� ����� ����ڵ��� �䱸 �մϴ�
	// ���̺귯�� �����ڷμ� �ּ��� ����� ������ ���ô�.

	// #1. FileStream Ŭ������ ��ȣȭ �ϴ� ��� �߰�����
	// => �䱸������ ������ ���� ���� Ŭ������ ��� �����Ҽ��� ����.!!!
	// => �׸���, FileStream �� �ƴ϶�, NetworkStream, PipeStream �� �����Ǿ���Ѵ�.

	// #2. FileStream �� �Ļ� Ŭ����(EncrpytFileStream)�� ���� �߰� ����.
	// => NetworkStream, PipeStream ��� �Ļ� Ŭ���� �ʿ�
	// => ��ȣȭ, ���� ���� �ʿ� �ϰ�, �� ��� �����Ϸ��� ���� ��ӵ� �ʿ�

	// #3. ��� Ŭ������ Stream �� ��� �߰�
	// => OCP ����
	// => ���� �ڵ��� ����


	// #4. Decorator�� ����ϸ� ���� ??

	FileStream fs("a.txt");
	fs.write("Hello");		

	EncrpytDecorator ed(&fs);
	ed.write("Hello");  // #1. ��ȣȭ ��� ����
						// #2. fs.write(��ȣȭ�� ����Ÿ) 

	ZipDecorator zd(&ed );
	zd.write("Hello");	// #1. ���� ��� ����
						// #2. ed.write(����� ����Ÿ)
}
