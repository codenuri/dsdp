#define USING_GUI
#include "cppmaster.h" 


class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);

		ec_set_window_rect(handle, 0, 0, 300, 300);
	}


	static int msgproc(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: lbutton_down(); break;
		case WM_KEYDOWN:     key_down(); break;
		}
		return 0;
	}

	virtual void lbutton_down() {}
	virtual void key_down() {}
};


int main()
{
	Window w;
	w.create("hello"); 

	ec_process_message();
}

