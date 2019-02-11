#include <iostream>

using namespace std;

class Singleton {
public:
	static Singleton *GetInstance();
private:
	static Singleton* m_sInstance ;

	Singleton() {};
	~Singleton() {};
};

Singleton *Singleton::m_sInstance = nullptr;

Singleton *Singleton::GetInstance() {
	if (!m_sInstance)
		m_sInstance = new Singleton;
	return m_sInstance;
}

void main() {
	Singleton *firstElement = Singleton::GetInstance();
	cout << &*firstElement << endl;

	Singleton *secondElement = Singleton::GetInstance();
	cout << &*secondElement << endl;

	Singleton *thirdInstance = new Singleton(*firstElement);
	cout << &*thirdInstance << endl;

	system("pause");
}