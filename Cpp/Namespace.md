# namespace
Namespaces allow declarations to be grouped together and avoid name clashes
- They can be explicity qualified using the scope operator like nameSpace::Class
- You can make all names in a namespace accessible by using the namespace directive using namespace name where name is a namespace
  - std (the standard library namespace
- Avoid using the directive access specifier in headers
  - it will then be included whenever the header is included
  - it will highly likely result in name clashes
- A single name from a namespace can be used with the using directive such as using std::cout
- Namespaces can be combined to form new namespaces

```cpp
#include <iostream>

using std::cout;  //using directive instead of using namespace std since only need cout.

//Namespace 1
namespace ABC {  

	void doABC() {
		cout << "doABC() \n";
	}
}

//Namespace 2
namespace DEF {

	void doDEF() {
		cout << "doDEF() \n";
	}
}

//Combined namespace
namespace ABCDEF {
	using namespace ABC;
	using namespace DEF;
}

//Main function.
int main(int argc, char* argv[]) {

	ABCDEF::doABC();
	ABCDEF::doDEF();

	return 0;
}
```

### Output
```
printBody called.
Main function call.
```
