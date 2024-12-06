#define USING_GUI
#include "cppmaster.h" 
#include <map>


class Window;

std::map<int, Window*> this_map;


// 클래스 템플릿 만들때
// => T를 사용하지 않은 멤버가 있다면
// => 템플릿이 아닌 클래스를 기반 클래스 만들어서 제공해라!!

class Window
{
protected:
	int handle;

public:
	// 메세지 처리 관련된 수백개 함수
	void lbutton_down() {}
	void key_down() {}
	
	// move(), hide(), set_title(), set_top_most()등
	// 윈도우 제어 관련 수십개 함수를 여기서
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
	void lbutton_down()
	{
		std::cout << "MainWindow lbutton_down()\n";
	}
};





int main()
{
	MainWindow w1;
	w1.create("MainWindow");


	ec_process_message();
}

