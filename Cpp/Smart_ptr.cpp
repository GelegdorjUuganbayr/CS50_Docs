#include<iostream>
#include<memory>
#include<vector>

using namespace std;

class test1 {
public:
	int a;
	test1() :a{ 10 } { cout << "test1 constructor, a: " << a << endl; }
	~test1() { cout << "test1 destructor, a: " << a << endl; }
	void increment() { cout << "increment() a: " << a++ << endl;; }
};

class test2 {
public:
	test2() { cout << "test2 constructor" << endl; }
	~test2() { cout << "test2 destructor" << endl; }
	static unique_ptr<test1> unq_ptr;
};

unique_ptr<test1> test2::unq_ptr = make_unique<test1>();

int main()
{
	unique_ptr<test2> ptr_test = make_unique<test2>();
	cout << ptr_test->unq_ptr->a << endl;
	ptr_test->unq_ptr->increment();
	cout << ptr_test->unq_ptr->a << endl;

}

/*
std::unique_ptr<OtherClass> SomeClass::foo(new OtherClass);
std::unique_ptr<OtherClass> SomeClass::foo = static_cast<std::unique_ptr<OtherClass>>(new OtherClass);
std::unique_ptr<OtherClass> SomeClass::foo = std::make_unique<OtherClass>();
*/
