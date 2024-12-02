#include <iostream>


// 카메라를 먼저 만들지 말고
// 카메라 제조사와 카메라 사용자 사이에 지켜야 하는 규칙을 먼저 설계한다.
// 규칙 : 모든 카메라는 아래 클래스로 부터 파생되어야 한다.
class ICamera
{
public:
	virtual void take() = 0;
};

// 카메라 사용자는 "특정 제품의 이름" 이 아닌 "규칙이름" 으로 사용하면됩니다.
class People
{
public:
	void use_camera(ICamera* c) { c->take(); }
};


// 모든 카메라는 규칙을 지켜야 합니다.
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

