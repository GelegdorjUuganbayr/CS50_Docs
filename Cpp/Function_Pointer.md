# Callbacks Function
A call back function is used to notify the program execution that an event has taken place
- This is commonly use in GUI development
- When a user clicks on a button a call back function will be invoked to handle the users request

```cpp
#include <iostream>

using namespace std;

template<typename arrayType,typename func>
void fillArray(arrayType *array, size_t arraySize, func f) {
	for (int i = 0; i < arraySize; i++) {
		array[i] = f();
	}
}

void nonTemplateFillArray(int *array, size_t arraySize, int (*getElement)(void)) {
	for (int i = 0; i < arraySize; i++) {
		array[i] = getElement();
	}

}

int fillWithInts() {
	return rand();
}


char fillWithChars() {
	return char('A' + rand() % 24);
}

int main(int argc, char* argv[]) {

	int intArray[10];
	fillArray(intArray, 10, fillWithInts);

	char charArray[10];
	fillArray(charArray, 10, fillWithChars);
  
  // Using non templated array fill call back function
	int intArrayNoTemplate[10];
	nonTemplateFillArray(intArrayNoTemplate, 10, fillWithInts);

	return 0;
}
```
- The first template function fillArray takes 3 parameters
  - the array to fill
  - the array size
  - the call back function used to populate the array elements
- The third function is a non-templated version of the fillArray function for integers
  - this is how it is used without templates
  - the type of the parameters is int I can only pass integer arrays into the function
  
# The Command Pattern
The command pattern is considered a behavioural design pattern
- It is like an object based version of a call back.
- The requester sends a request as an object which allows the receiver to parametrize different requests by object type
- The objects can be queued or pooled
  - Because the request is an object 
- The request operation can be reversed
  - Since all the information required to complete the operation is in the object. 

## television examle
### Command
```cpp
class Command {
public:
	virtual void execute() = 0;
};
```

### TV
```cpp
class Television
{
private:
	int channel;
public:
	//TV constructor init volume and channel to 0.
	Television() : channel(0) {  }

	void turnOn() {
		cout << "The television is on" << endl;
	}
	void turnOff() {
		cout << "The television is off" << endl;
	}
	void channelUp() {
		cout << "Turn channel up level is " << ++channel << "\n";
	}	
	void channelDown() {
		cout << "Turn channel down level is " << --channel << "\n";
	}
};
```

### TV On
```cpp
class TVOnCommand : public Command
{
private:
	Television& tv;
public:
	TVOnCommand(Television& tele) :tv(tele) {}
	virtual void execute() {
		tv.turnOn();
	}
};
```

### TV Off
```cpp
class TVOffCommand : public Command
{
private:
	Television& tv;
public:
	TVOffCommand(Television& tele) :tv(tele) {}
	virtual void execute() {
		tv.turnOff();
	}
};
```

### Channel up
```cpp
class ChannelUpCommand : public Command
{
private:
	Television& tv;
public:
	ChannelUpCommand(Television& tele) :tv(tele) {}
	virtual void execute() {
		tv.channelUp();
	}
};
```

### Channel down
```cpp
class ChannelDownCommand : public Command
{
private:
	Television& tv;
public:
	ChannelDownCommand(Television& tele) :tv(tele) {}
	virtual void execute() {
		tv.channelDown();
	}
};
```

### TV Remote
```cpp
class TVRemote
{
private:
	Command& tvOnCommand;
	Command& tvOffCommand;
	Command& channelUpCommand;
	Command& channelDownCommand;
public:
	TVRemote(Command& channelUpCmd, Command& channelDownCmd, Command& tvOnCmd, Command& tvOffCmd)
	:channelUpCommand(channelUpCmd), channelDownCommand(channelDownCmd), tvOnCommand(tvOnCmd), tvOffCommand(tvOffCmd)
	{}

	void tvOn() {
		tvOnCommand.execute();
	}
	void tvOff() {
		tvOffCommand.execute();
	}
	void channelUp() {
		channelUpCommand.execute();
	}
	void channelDown() {
		channelDownCommand.execute();
	}
};
```

### main
```cpp
int main(int argc, char* argv[]) {

	Television myTV;
	TVOnCommand tvOn(myTV);
	TVOffCommand tvOff(myTV);
	ChannelDownCommand chDwnCmd(myTV);
	ChannelUpCommand chUpCmd(myTV);

	TVRemote remote(chUpCmd,chDwnCmd,tvOn,tvOff);

	remote.tvOn();
	remote.channelUp();
	remote.channelUp();
	remote.channelUp();
	remote.channelDown();
	remote.tvOff();

	return 0;
}
```
- The first class is the command interface which defines the pure virtual function execute
  - Any class using the command class as a base class must define the execute method
- The Television class is next this is akin to the Receiver class in the command pattern
  - The actual object executing the commands sent to it
  -  It defines a private int members channel to store the tv state.
  
- The command classes are defined next, they all work in the same way
  - They define a constructor that has a Television object as a parameter which they invoke the television functions on
- Lastly we define the TVRemote class which private members for each of the commands
  - These are initialise in the constructor using the constructor parameters
  - The public functions invoke the execute function on each of the associated command objects.
  
# Member function pointer
```cpp
//Normal function pointer
void printString(string s) {
	cout << s << endl;
}

//Member function pointer.
class funcPointer{
	public:
		void printString(string s) {
			cout << s << endl;
		}
};

//Polymorphism use.
class Base {
public:
	virtual void sayHello() {
		cout << "Hello from Base class. \n";
	}
};

class Derived : public Base {
public:
	void sayHello() {
		cout << "Hello from Derived class. \n";
	}
};

int main(int argc, char* argv[]) {

	//Standard function pointer example
	string ss = "Hello World.";

	void(*funcPtr)(string) = &printString;
	(*funcPtr)(ss);


	//Member function pointer example.
	string str = "Hello from member function pointer.!!";
	void (funcPointer::*memFuncPtr)(string) = &funcPointer::printString;

	funcPointer fP;
	(fP.*memFuncPtr)(str);

	//Virtual member function example.
	void (Base::*baseFuncPtr)() = &Base::sayHello;
	void (Derived::*derivedFuncPtr)() = &Derived::sayHello;

	Base bP;
	Derived dP;

	(bP.*baseFuncPtr)();  //call Base::sayHello
	(dP.*derivedFuncPtr)(); //call Derived::sayHello
	(dP.*baseFuncPtr)();  //call Derived::sayHello using base pointer and derived object. 

	return 0;
}   
```


