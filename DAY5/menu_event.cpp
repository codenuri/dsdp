#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <functional> // std::bind(), std::function<>
using namespace std::placeholders;

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title)
		: title(title) {
	}

	virtual ~BaseMenu() {}

	std::string get_title() { return title; }

	virtual void command() = 0;
};








class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add(BaseMenu* m) { v.push_back(m); }

	void command()
	{
		while (1)
		{
			system("cls");

			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << '\n';
			}
			std::cout << sz + 1 << ". ����\n";

			std::cout << "�޴��� �����ϼ��� >> ";

			int cmd;
			std::cin >> cmd;


			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;


			v[cmd - 1]->command();

		}
	}
};

class MenuItem : public BaseMenu
{
	using HANDLER = std::function<void()>; // ���ڰ� ���� �Լ�
										   // �׷���, std::bind()�� �����Ƿ�
										   // ��� �Լ� ��ϰ���(void��ȯ)
	std::vector<HANDLER> v; // �޴� ���ý� �������� ����
							// ������ ��������


	int  id;


public:
	MenuItem(const std::string& title, int id, HANDLER h = nullptr )
		: BaseMenu(title), id(id) 
	{
		if (h != nullptr)
			v.push_back(h);
	}

	void add_handler(HANDLER h)
	{
		if (h != nullptr)
			v.push_back(h);
	}



	void command()
	{
		// �޴� ���ý� ��ϵ� ��� �Լ��� �˷��ش�.
		// => ������ ����
		for (auto f : v)
			f();	// f�� function �̹Ƿ� ()�� ȣ�Ⱑ��
					// ���� ���� �Լ�.. 
	}
};

void foo()
{
	std::cout << "foo ȣ��� - ���⼭ �޴����ý� �ؾ� ���� �ۼ�\n";
	std::cout << "�ƹ�Ű�� ������ �޴��� ���ư��ϴ�\n";
	_getch();
}

void goo(int id)
{
	std::cout << "goo ȣ��� - ���⼭ �޴����ý� �ؾ� ���� �ۼ�\n";
	std::cout << "�ƹ�Ű�� ������ �޴��� ���ư��ϴ�\n";
	_getch();
}



int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("���� ����");
	PopupMenu* pm2 = new PopupMenu("�ػ� ����");

	root->add(pm1);
	root->add(pm2);

	pm1->add(new MenuItem("RED", 11, &foo));
	pm1->add(new MenuItem("GREEN", 12, std::bind(&goo, 12)));
	pm1->add(new MenuItem("BLUE", 13,  std::bind(&goo, 13)));
	pm1->add(new MenuItem("WHITE", 14));

	pm2->add(new MenuItem("HD", 21));
	pm2->add(new MenuItem("FHD", 22));
	pm2->add(new MenuItem("UHD", 23));

	MenuItem* m = new MenuItem("8K", 24, &foo);
	m->add_handler(std::bind(&goo, 24));

	pm2->add(m);

	root->command();
}