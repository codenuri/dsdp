#include <iostream>


// �ٽ� Ŭ������
// �ٽ� Ŭ������ ����� �߰��ϴ� Ŭ����(Decorator)�� ������ �������̽��� �ʿ��ϴ�.

struct IDraw
{
	virtual void draw() = 0;
	virtual ~IDraw() {} 
};



class PhotoSticker : public IDraw 
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() { std::cout << "draw Photo\n"; }
};

//----------------------------------------------
class Emoticon : public IDraw
{
	IDraw* origin;
public:
	Emoticon(IDraw* ps) : origin(ps) {}

	void draw()
	{
		std::cout << "$$$$$$$$$$$$\n";
		origin->draw();
		std::cout << "$$$$$$$$$$$$\n";
	}
};

class Frame : public IDraw
{
	IDraw* origin;
public:
	Frame(IDraw* ps) : origin(ps) {}

	void draw()
	{
		std::cout << "============\n";
		origin->draw();
		std::cout << "============\n";
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();
	ps.draw();


	Emoticon emo(&ps);
	emo.draw();


	Frame frame(&emo);
	frame.draw();
}
