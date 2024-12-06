#define USING_GUI
#include "cppmaster.h" 
#include <map>


class Window;

std::map<int, Window*> this_map;


// Ŭ���� ���ø� ���鶧
// => T�� ������� ���� ����� �ִٸ�
// => ���ø��� ������� �ʴ� ����� ��� Ŭ���� ���� �����ض�!!
// => "thin template" �Ǵ� "template hoisting" �̶�� �Ҹ��� ���(C++ IDioms)

class Window
{
protected:
	int handle;

public:
	// �޼��� ó�� ���õ� ���鰳 �Լ�
	void lbutton_down() {}
	void key_down() {}
	
	// move(), hide(), set_title(), set_top_most()��
	// ������ ���� ���� ���ʰ� �Լ��� ���⼭
};


template<typename T>
class MsgWindow : public Window
{

public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);
		ec_set_window_rect(handle, 0, 0, 300, 300);

		this_map[handle] = this;
	}

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		T* self = static_cast<T*>(this_map[hwnd]);

		switch (msg)
		{
		case WM_LBUTTONDOWN:
			self->lbutton_down();
			break;

		case WM_KEYDOWN:
			self->key_down();
			break;
		}
		return 0;
	}

};

class MainWindow : public MsgWindow<MainWindow>
{
public:
	void lbutton_down() {	std::cout << "MainWindow lbutton_down()\n";	}
};





int main()
{
	MainWindow w1;
	w1.create("MainWindow");


	ec_process_message();
}



// GUI4.cpp : event ó���� �����Լ��� �����ϴ� �ڵ�(template method)
//			 => �����Լ� ���̺��� ������尡 �ֽ��ϴ�.

// GUI9.cpp : event ó���� CRTP ����� �ذ��ϴ� �ڵ�
//			=> WTL(Window Template Library) �̶�� ���̺귯�� �� ��� ���
//			  (office ���鶧 ����� MS �� ���̺귯��)