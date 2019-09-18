#ifndef SINGLETON_H
#define SINGLETON_H

#include <memory>

template <typename TypeName>
class Singleton {

protected:
	virtual ~Singleton() {};
	Singleton();
private:
	static std::unique_ptr<TypeName> instance;
public:
	static TypeName& getInstance();
};

template<typename TypeName>
std::unique_ptr<TypeName> Singleton<TypeName>::instance = nullptr;

template<typename TypeName>
Singleton<TypeName>::Singleton() {
}

template<typename TypeName>
TypeName & Singleton<TypeName>::getInstance() {
	if(!instance) {
		instance = std::unique_ptr<TypeName>(new TypeName());
	}
	return *instance;
}




#endif // !SINGLETON_H
