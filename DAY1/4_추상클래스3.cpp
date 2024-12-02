#include <iostream>

// �߻� Ŭ���� : ���Ѿ� �ϴ� ��Ģ + �ٸ� ����� �ִ� ���
// ���� ���̽� : ���Ѿ� �ϴ� ��Ģ�� ���� ���

// C#, java : interface, abstract ��� ������ Ű���� ����
// C++      : ���� Ű���� ����, ���� �� �������� ����

//------------------------------------------
// ���� ����(tightly coupling)
// => �ϳ��� Ŭ������ �ٸ� Ŭ���� ����, Ŭ���� �̸��� ���� ����ϴ°�
// => use_camera(HDCamera* c)
// => ��ü �Ұ����� ������ ������.

// ���� ����(loosely coupling)
// => �ϳ��� Ŭ������ �ٸ� Ŭ���� ����, Ŭ���� �̸��� �ƴ� ��Ģ�� ����
//     �������̽��� ����ؼ� ���� �ϴ� ��
// => use_camera(ICamera* c)
// => ��ü ������ ������ ������.
//------------------------------------------------------

// ī�޶� ���� ������ ����
// ī�޶� ������� ī�޶� ����� ���̿� ���Ѿ� �ϴ� ��Ģ�� ���� �����Ѵ�.
// ��Ģ : "��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ��Ǿ�� �Ѵ�." ��� ǥ������ ����
//       "��� ī�޶�� �Ʒ� �������̽��� �����ؾ� �Ѵ�" ��� ǥ���մϴ�.

// class  : ���� ������ ������ ����Ʈ ���� private
// struct : ���� ������ ������ ����Ʈ ���� public

//class ICamera
struct ICamera
{
//public:
	virtual void take() = 0;
	virtual ~ICamera() {} // �������̽��� �ᱹ ��� Ŭ���� �Դϴ�.
						  // �Ҹ��ڸ� �����Լ��� �ؾ� �մϴ�. 
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

class FHDCamera : public ICamera
{
public:
	void take() override { std::cout << "Take FHD Picture" << std::endl; }
};

int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); 

	FHDCamera fhc;
	p.use_camera(&fhc);
}

