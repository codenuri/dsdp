#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// Proxy 패턴 : 기존 요소를 대신할 요소를 만드는 것!!

//  Raw Pointer 를 사용하지 말고 대신할 것을 만들어봅시다.

template<typename T>
class sp
{
	T* obj;
public:
	sp(T* p = nullptr) : obj(p) {}

	sp(const sp& other) : obj(other.obj) {}

	~sp() {}
};

int main()
{
	sp<ICalc> calc1 = load_proxy();
	sp<ICalc> calc2 = calc1;
}



int main()
{
	ICalc* calc1 = load_proxy();

	calc1->AddRef(); 

	ICalc* calc2 = calc1;
	calc2->AddRef(); 


	calc2->Release(); 

	std::cout << "-------------\n";

	calc1->Release(); 

	std::cout << "-------------\n";

}





