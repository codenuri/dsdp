// ����. - ���� ������ ������ �����ؼ� ������..

// �ٽ� #1. ������ ���� �ڵ忡�� ���ϴ� ���� �и��ض�
// => ���ϴ� ���� ��� �и��Ұ��ΰ� ??

// 1.1 ���ϴ� ���� �����Լ��� 
// => �����Լ��� ��å�̳� �˰��� ���� : template method 
// => �����Լ��� ��ü�� Ÿ�� ����      : factory method

// 1.2 ���ϴ� ���� �ٸ� Ŭ������
// 
// strategy : ��ü�� ����ϴ� �˰����� ����ð��� ��ü �����ϰ�
//				(Edit/IValidator)
// 
// state : ��ü�� ���¿� ���� ��� ���� ��ü 
//			(ĳ���� �����ۿ� ���� ���� ��ü, 
//			 ���Ǳ� ���� ������ ���� ��� ���� ��ü)
// 
// 
// builder : �����Ѱ�ü�� ���鶧 ���� ��������, �� ������ ǥ���� �ٸ���
//    

// policy base design : ��ü�� ����ϴ� �˰���(��å)�� ��ü �ϴµ�, �������̽��� �ƴ�
//		���ø� ���ڷ�, vector �� allocator ��ü 

// �ٽ� #2. ����� ������ ����ϴ� ����
// => A�� B�� ���������� A �� �����Ҽ� �ִ�.
// => A, B�� ������ ��� Ŭ���� �ʿ�

// ��?, ��ǵ��� ����� ������ �ϴ°� ?
// composite : ����� �������� ���հ�ü �����, Folder/File, PopupMenu/MenuItem
// decorator : ����� �������� ���� ����߰�   FileStream /ZipDecorator����

// �ٽ� #3. ���������� ���� �ذ�
// adapter : �������̽� ����, list�� stack ó�� ���̰�
// bridge  : ������ �������� �и�, update �� ���������� 
// proxy   : ����Ұ��� ������, Remote ������ ���� CalcProxy
// facade  : ����ϱ� ����, TCPServer


// �ٽ� #4. undo/redo �� �����ϰ� 
// memento : ��ü ������ ���忡 ���� undo
// command : ����� Ŭ������ ����. undo �� �ʿ��� ����Ÿ ����


// �ٽ� #5. ����, �湮, �뺸, ����
// observer : 1�� ��ȭ�� N�� �뺸
// chain of responsibility : ���ʴ�� ������ ����
// iterator : ���հ�ü�� �����ϰ� ����
// visitor : ���հ�ü�� ��� ��ҿ� ����� ������ ����


// ������ ������ �뵵�� ���� 3������ �з� �մϴ�.

// ���� ���� 5��
// => singleton,
// => prototype
// => abstract factory
// => factory method
// => builder 

// ���� ���� 7��
// ����� ���� : composite, decorator
// ������      : adapter, proxy, bridge, facade
// �Ӽ��̵����ϸ� ���� : flyweight

// ���� ���� 11��
// ���Ź湮 : iterator, visitor
// undo/redo : command, memento
// �뺸, ���� : observer, chain of responsibility
// ����		 : mediator
// ��ȭ�� �и� : template method, strategy, state 
// �����Ϸ� ���鶧 ����ߴ� ����(������ ���� ������) : iterpreter





