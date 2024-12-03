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
		std::cout << get_title() << " �޴� ���õ�\n";

		_getch(); 
	}
};
class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title) : title(title) {}

	void add(MenuItem* m) { v.push_back(m); }

	// �˾��޴��� ���� �Ҷ� ������ ������ ���ô�.
	void command()
	{

	}
};

int main()
{
	MenuItem m1("���", 11);
	MenuItem m2("���", 12);

	PopupMenu pm("������ ���� �޴�");

	pm.add(&m1);
	pm.add(&m2);

	pm.command(); // �˾��޴� ����

}




