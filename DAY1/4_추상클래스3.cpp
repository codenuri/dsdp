#include <iostream>


// ī�޶� ���� ������ ����
// ī�޶� ������� ī�޶� ����� ���̿� ���Ѿ� �ϴ� ��Ģ�� ���� �����Ѵ�.
// ��Ģ : ��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ��Ǿ�� �Ѵ�.
class ICamera
{
public:
	virtual void take() = 0;
};

// ī�޶� ����ڴ� "Ư�� ��ǰ�� �̸�" �� �ƴ� "��Ģ�̸�" ���� ����ϸ�˴ϴ�.
class People
{
public:
	void use_camera(ICamera* c) { c->take(); }
};


// ��� ī�޶�� ��Ģ�� ���Ѿ� �մϴ�.
class Camera : public ICamera
{
public:
	void take() override { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() override { std::cout << "Take HD Picture" << std::endl; }
};

int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); 
}

