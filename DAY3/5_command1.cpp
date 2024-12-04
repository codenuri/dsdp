#include "monitor.h"

// ������� ��⸦ �����Ϸ���
// ��� #1. set_brightness() ��� �Լ��� ���� ȣ���Ѵ�.
// ��� #2. set_brightness() ��� �Լ��� ȣ���ϴ� ��ü�� ���� ���

class BrightnessCommand
{
	Monitor& m;
	int value;
public:
	BrightnessCommand(Monitor& m, int value) : m(m), value(value) {}

	void execute() { m.set_brightness(value);}
};

int main()
{
	Monitor m;	
	m.set_brightness(90);
	
	BrightnessCommand cmd(m, 90);
	cmd.execute();
}