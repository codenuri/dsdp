/*
#define MAKE_SINGLETON(classname)			\
private:									\
	classname() {}							\
	classname(const classname&) = delete;	\
	classname& operator=(const classname&) = delete;	\
public:									\
	static classname& get_instance()	\
	{									\
		static classname instance;		\
		return instance;				\
	}
*/
#include "helper.h" // �� ����� �� �ڵ尡 �̹� �ֽ��ϴ�.

class Cursor
{
	MAKE_SINGLETON(Cursor)
};

int main()
{
	Cursor& c = Cursor::get_instance();
}