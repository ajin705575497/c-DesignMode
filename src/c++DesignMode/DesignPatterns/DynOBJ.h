#ifndef OBJDYN_H
#define OBJDYN_H

#include <string>
#include <map>

typedef void*(*Constructor)();

class CObjectFactory
{
public:
	static void registerClass(std::string className, Constructor constructor)
	{
		constructors()[className] = constructor;
	}
	static void *createObject(const std::string& className)
	{
		Constructor constructor = NULL;
		if (constructors().find(className) != constructors().end())
		{
			constructor = constructors().find(className)->second;
		}
		if (constructor == NULL)
			return NULL;
		return (*constructor)();
	}
private:
	//string->key:动态创建的类的类名 ，value是构建
	inline static std::map<std::string, Constructor>& constructors()
	{
		static std::map<std::string, Constructor> instance;
		return instance;
	}
};

#define REG_CLASS(class_name) \
class class_name##Helper \
{\
public:\
	class_name##Helper()\
	{\
		CObjectFactory::registerClass(#class_name, class_name##Helper::createObjFunc);\
	}\
	static void* createObjFunc()\
	{\
		return new ImpleTwo;\
	}\
};\
class_name##Helper class_name##helper;
#endif // !OBJDYN_H
