#include "monitor.h"

// C ��� : � ���� �Ҷ�, "�Լ��� ���� ȣ��" �մϴ�.
//         => �־��� �ϸ� �Ҽ� �ֽ��ϴ�.


// Command ���� : ����� �Ҷ�, �� �Լ��� ȣ�����ִ�(�������ϴ�) ��ü�� ������ ��
//			=> �־��� �ϵ� �Ҽ� �ְ�.
//			=> ����ϴ� ����� �����Ҽ� �ְ�
//			=> ����Ҷ� �ʿ��� ����Ÿ�� �����Ҽ� �ִ�.
//			=> ���� ����� ���ʴ�� �����Ҽ��� �ִ�.


// �پ��� ����� ������ �����Ƿ� �������̽� ���� ����
struct ICommand
{
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual ~ICommand() {}
};

class BrightnessCommand : public ICommand
{
	Monitor& m;
	int value;
	int old_value = 0;
public:
	BrightnessCommand(Monitor& m, int value) : m(m), value(value) {}

	void execute() 
	{
		old_value = m.get_brightness();
		m.set_brightness(value); 
	}
	void undo()
	{
		m.set_brightness(old_value);
	}
};

int main()
{
	Monitor m;
	
	int old_value = m.get_brightness();
	m.set_brightness(90);
	// ���⼭, Monitor m �� ��⸦ �ٲٱ� �������·� ������ ������
	m.set_brightness(old_value);


	BrightnessCommand cmd(m, 90);
	cmd.execute();
	cmd.undo(); // ?!!!
}