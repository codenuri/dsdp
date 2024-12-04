// 6_Bridge1 - 90 page
#include <iostream>

// ��� MP3 ��ǰ�� ��Ģ
struct IMP3
{
	virtual void play() = 0;
	virtual void stop() = 0;
	virtual ~IMP3() {}
};


class IPod : public IMP3
{
public:
	void play() { std::cout << "Play MP3 with IPod" << std::endl; }
	void stop() { std::cout << "Stop" << std::endl; }
};

//-----------------------------------
// �� �ڵ尡 ���� MP3 �� �����Դϴ�.(IMP3, IPod, �پ��� ��ǰ��)
// ����ڰ� ���� �� ������ ����ϰ� �������� �Ʒ� Ŭ������ ����ϰ� �մϴ�.

// �Ʒ� Ŭ������ ���� "MP3 Play/Stop" ����� �����ϴ�.

class MP3
{
	IMP3* impl;
public:
	MP3(IMP3* p = nullptr) : impl(p)
	{
		if (impl == nullptr) impl = new IPod;
	}
	void play() { impl->play(); }
	void stop() { impl->stop(); }

	void play_one_minute()
	{
		impl->play();
		// Ÿ�̸� ��ġ�� 1�еڿ�
		impl->stop();
	}
};

// ���� ��� Ŭ������ IMP3 ��� MP3 �� ����ϰ� �մϴ�.

class People
{
public:
	void use(MP3* p) 
	{
		p->play();
		p->stop();

		p->play_one_minute();
	}
};


int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


