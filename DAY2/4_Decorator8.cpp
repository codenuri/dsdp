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

//-----------------------------------------------

// ��� �߰� Ŭ����(Decorator)���� ������ ����� ������ �ֽ��ϴ�.
// ��� Ŭ������ �����ϸ� ���մϴ�.
class Decorator : public Stream
{
	Stream* origin; 
public:
	Decorator(Stream* s) : origin(s) {}

	Stream* get_base_stream() { return origin; }

	void write(const std::string& s)
	{
		origin->write(s);
	}
};


class ZipDecorator : public Decorator
{
public:
	ZipDecorator(Stream* s) : Decorator(s) {}

	void write(const std::string& s)
	{
		std::string s2 = "[ " + s + " ] �����";

		Decorator::write(s2);
	}
};

class EncryptDecorator : public Decorator
{
public:
	EncryptDecorator(Stream* s) : Decorator(s) {}

	void write(const std::string& s)
	{
		std::string s2 = "[ " + s + " ] ��ȣȭ��";

		Decorator::write(s2);
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
}
