// ���ϴ� ���� �и��ϴ� 2���� ���

// Edit2.cpp
// => ���ϴ� ���� �����Լ���
// => template method
// => ����� ����ϴ� ����
// 
// �߿� Ư¡ : NumEdit �� Edit ��ɰ� Validation ��å��
//            ��� �����ϰ� �ȴ�.(��å�� ������)




// Edit3.cpp
// => ���ϴ� ���� �ٸ� Ŭ������
// => strategy ����

// Ư¡ :  Edit ��ɰ� Validation ��å�� ������ �и��Ǿ��ִ�.
// => LimitDigitValidator �� �ٸ� �Էµ��������� ��밡���ϴ�.

// => ����ð� validation ��å ���浵 ����
//    e.set_validator(&v1);
//    e.set_validator(&v2);

// ���� : Validator ���� Edit ��� ����Ÿ ���� �ȵ˴ϴ�.
//        �׷��� validate()�Լ��� ���ڷ� �ʿ��� ����Ÿ ����

// Edit ������ edit2 ���� edit3�� �����ϴ�.
//====================
// �׷���, ���������⸦ ������ ���ô�.
// => template method ������ �������� ���
// => �簢���� ��� �׸����� ���� �ð� ���� �ʿ� ����,
//    �ٸ� Ŭ�������� ���� �ʿ䵵 �����ϴ�.
//    ����, draw_imp() �� ����Լ��̹Ƿ� ��� ����Ÿ ���ٵ� ����

// �׷��� �̰��� ���ϴ� ���� "�����Լ��� �и�" �ϴ°��� �����ϴ�.
class Shape
{
public:
	void draw() 
	{
		draw_imp();
	} 
	virtual void draw_imp() {}
};
class Rect : public Shape
{
	virtual void draw_imp() {}
};

// C++ GUI ���̺귯���� QT, MFC ��� ���� �ֽ��ϴ�

// MFC �� CEdit Ŭ���� - Edit2.cpp ó�� �Ǿ� �ֽ���.
// QT  �� QEdit Ŭ���� - Edit3.cpp  