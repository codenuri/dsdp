#include <iostream>
#include <string>
#include <vector>

// �Ʒ� Ŭ������ �̹� �־��ٰ� ������ ���ô�.
// => ���ڿ��� �����ߴٰ� ȭ�鿡 �̻ڰ� ����ϴ� ���
class TextView
{
	// font ����, ũ��, ���� ��... �پ��� ���� ���� 
	std::string data;
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};




//=================================================
class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};


// Ŭ���� ����� : Ŭ���� �������̽� ����
// ��ü   ����� : ��ü   �������̽� ����

class Text : public TextView,  public Shape     
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() override
	{
		TextView::show();
	}
};

int main()
{
	std::vector<Shape*> v;

	TextView tv("hello"); // TextView : Ŭ����
						  // tv       : ��ü(����)

	// �̹� ������ ��ü tv �� v�� ������ ������� ?
	v.push_back(&tv); // ??
}







