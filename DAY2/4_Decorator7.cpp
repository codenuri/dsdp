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
		printf("%s 쓰기\n", s.c_str());
	}
};

// FileStream, NetworkStream, PipeStream
// => 실제 H/W 에 R/W 수행
// => 사용법이 동일함을 약속하기 위해 Stream 인터페이스 구현

// EncrpytDecorator, ZipDecorator
// => 실제 H/W에 쓰는 것이 아니라, 위 3개 클래스에 기능추가가 목표
// => 사용법도 동일해야 하고, 중첩된 기능추가가 되어야 하기 때문에
//    Stream 인터페이스 구현

class ZipDecorator : public Stream
{
	Stream* origin; // 핵심 : 포인터 또는 참조
					// 의도 : 외부에 이미 생성된 객체를 가리키겠다는것
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void write(const std::string& s)
	{
		std::string s2 = "[ " + s + " ] 압축됨";

		origin->write(s2);
	}	
};

class EncryptDecorator : public Stream
{
	Stream* origin; 
public:
	EncryptDecorator(Stream* s) : stream(s) {}

	void write(const std::string& s)
	{
		std::string s2 = "[ " + s + " ] 암호화됨";

		origin->write(s2);
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("Hello");

	EncrpytDecorator ed(&fs);
	ed.write("Hello");  

	ZipDecorator zd(&ed);
	zd.write("Hello");	
}
