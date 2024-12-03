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

// FileStream, NetworkStream, PipeStream
// => ���� H/W �� R/W ����
// => ������ �������� ����ϱ� ���� Stream �������̽� ����

// EncrpytDecorator, ZipDecorator
// => ���� H/W�� ���� ���� �ƴ϶�, �� 3�� Ŭ������ ����߰��� ��ǥ
// => ������ �����ؾ� �ϰ�, ��ø�� ����߰��� �Ǿ�� �ϱ� ������
//    Stream �������̽� ����

class ZipDecorator : public Stream
{
	Stream* origin; // �ٽ� : ������ �Ǵ� ����
					// �ǵ� : �ܺο� �̹� ������ ��ü�� ����Ű�ڴٴ°�
public:
	ZipDecorator(Stream* s) : origin(s) {}

	void write(const std::string& s)
	{
		std::string s2 = "[ " + s + " ] �����";

		origin->write(s2);
	}	
};

class EncryptDecorator : public Stream
{
	Stream* origin; 
public:
	EncryptDecorator(Stream* s) : origin(s) {}

	void write(const std::string& s)
	{
		std::string s2 = "[ " + s + " ] ��ȣȭ��";

		origin->write(s2);
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("Hello");

	EncryptDecorator ed(&fs);
	ed.write("Hello");  

	ZipDecorator zd(&ed);
	zd.write("Hello");	
//	fs.write("hello");

	// �Ʒ� ó�� �ϸ� �ȵǳ��� ?
	// => �Ʒ� ���� "filter" �߰��Ŀ�
	// => �ٽ� ����Ÿ �������� write �Ϸ��� ���͸� �ٽ� �����ؾ� �մϴ�.
	// => �׷���, �� ���� ������ ����
	/*
	FileStream fs("a.txt");

	fs.add_filter(new ZipFilter);
	fs.add_filter(new EncryptFilter);

	fs.write("hello"); // "hello" �� ��ϵ� ���Ϳ��� ���� ������ ����Ÿ ������
						// ����
	*/
}

// ���ۿ��� "C# Stream" �˻� �ϼ���
// => �̹��� ���� �� �غ�����