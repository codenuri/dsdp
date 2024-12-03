// Decorator(������, �ٹ̱�) - 65 page
#include <iostream>

// ��ƼĿ ���� Ŭ������� ������ ���ô�.
class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() { std::cout << "draw Photo\n"; }
};

//----------------------------------------------
class Emoticon 
{
	PhotoSticker* origin; // �ٽ� : ������ �Ǵ� ����������!!
						  // �ǵ� : �ܺο� �̹� ������� ��ü�� ����Ű�ڴٴ� ��
public:
	Emoticon(PhotoSticker* ps) : origin(ps) {}


	void draw()
	{
		std::cout << "$$$$$$$$$$$$\n";	// �߰� ���
		origin->draw();					// ���� ��ü ���
		std::cout << "$$$$$$$$$$$$\n";	
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();	
	ps.draw();	


	Emoticon emo(&ps); // ps ��� ��ü�� ����� �߰��ϰڴٴ� ��
	emo.draw();			// ps ��ü�� ��� + �߰��� ��ɵ� ����
						// emo �� ps��� ��ü�� ����� �߰� �� ��

	// ����� �߰��Ǳ����� ���� ��ü�� ��ɸ� ����Ҽ��� �ִ�.
	ps.draw();
}
