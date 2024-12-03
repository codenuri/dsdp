#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


class MenuItem
{
	std::string title;
	int  id;
public:
	MenuItem(const std::string& title, int id)
		: title(title), id(id) {
	}

	std::string get_title() { return title; }

	void command()
	{
		std::cout << get_title() << " ¸Þ´º ¼±ÅÃµÊ\n";

		_getch(); 
	}
};

int main()
{
	MenuItem m1("±è¹ä", 11);
	MenuItem m2("¶ó¸é", 12);

	PopupMenu pm("¿À´ÃÀÇ Á¡½É ¸Þ´º");

	pm.add(&m1);
	pm.add(&m2);

	pm.command(); // ÆË¾÷¸Þ´º ¼±ÅÃ

}




