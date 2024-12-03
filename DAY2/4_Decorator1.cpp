// Decorator(포장지, 꾸미기) - 65 page
#include <iostream>

// 스티커 사진 클래스라고 생각해 봅시다.
class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n";}
	void draw()	{ std::cout << "draw Photo\n"; }
};

// 상속을 사용한 기능의 추가
class Emoticon : public PhotoSticker
{
public:
	void draw()
	{
		std::cout << "$$$$$$$$$$$$\n";	// 추가된 기능
		PhotoSticker::draw();			// 원래 기능 사용
		std::cout << "$$$$$$$$$$$$\n";	// 추가된 기능
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();	// 사진 촬영
	ps.draw();	// 촬영된 사진 출력

	Emoticon emo;
	emo.take();
	emo.draw(); // 원래 기능 +  추가된 기능 사용
}
