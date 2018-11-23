# Templates

## Template Function
Template functions are a c++ language feature for code reuse
- It allows to use the function for multiple types
- Generic Programming

### template function structure
```cpp
template<typename T>
void printTypeName(T x) {
	cout << typeid(x).name() << endl;
}
```
- This program is able to use any of c++ type
- **template\<typename T\>**
  - It tells the compiler that this is a template angle brackets contain the type
  - typename T specifies the type that will be varied
  - **template\<class T\>** also can be used
    - class: templating a class
    - typename: all other types
    
### Usage
```cpp
int myint = 5;
printTypeName<int>(myint);

double mydouble = 99.9;
printTypeName<double>(mydouble);

int myint = 5;
printTypeName<>(myint);

double mydouble = 99.9;
printTypeName(mydouble);
```
With template function the compiler can perform type deduction to determine the parametrizing types when we don't provide them
- Empty angle brackets: It tells the compiler that we are calling a template function
- No angle brackets: It leaves it up to the compiler to infer
  - you cannot have any other functions by the same name
  
# Generic Algorithm
Template allows to create an algorithm that can be applied to many different types
- In the c++ STL, all the use of a random access iterator to iterate over container elements.
- Each container implements its own random access iterator which is able to iterate through and access its own elements
- Use the STL algorithms as these have complexity specifications and the code is highly optimised

### Bubble sort with STL
```cpp
std::vector<int> myvec;
from(std::vector<int>::iterator i = myvec.begin();i != myvec.end();i++) {
	for(std::vector<int>::iterator j = myvec.begin();j != i;j++) {
		if(*i < *j) {
			std::swap(*i,*j);
		}
	}
} 
```

### Bubble sort with Template
```cpp
template<typename TContainer>
void bubbleSort(TContainer begin,TContainer end) {
  from(TContainer i = begin;i != end;i++) {
    for(TContainer j = begin;j != i;j++) {
			if(*i < *j) {
				std::swap(*i,*j);
			}
		}
	} 
}

int main(void) {
  std::vector<int> myvec;
  bubbleSort(aVec.begin(), aVec.end());
}
```
If you are developing your own generic algorithms it is easier to start with a non-generic version that works correctly and then make that generic. 

### Generic algorithm for the class
To use the generic algorithm on the class, operator needs to be overriden
```cpp
class Circle {

private:
	int radius;
	double area;

public:
	Circle(int rad) : radius(rad) {
		area = pi*radius*radius;
	}
	const bool operator < (const Circle &r) const {
		return (area < r.area);
	}
	friend std::ostream& operator<< (std::ostream& stream, const Circle& cir) {
		stream << cir.area << "\n";
		return stream;
	}
};
```

## Point
### Point class with template
 The program might need several different types for member x and y
 - like int, doubles, floats etc. depending on how much precision we want a point to have
```cpp
template<class point>
class Point{
	public:
		Point() {}
		Point( point x,point y): px(x),py(y)  {}

	private:
		point px;
		point py;
};
```

### inherit Point class with template
```cpp
template<class derPoint>
class Point3D : Point<derPoint> {
	public:
		Point3D(derPoint x,derPoint y,derPoint z) : px(x), py(y), pz(z) {}

	private:
		derPoint px;
		derPoint py;
		derPoint pz;

};
```

# Multi type template
### three different data types
```cpp
template<class pointx, class pointy, class pointz>
class MultiTypePoint {
	public:
		MultiTypePoint(pointx x, pointy y, pointz z) : px(x), py(y), pz(z) {
			cout << "MultiTypePoint object constructor." << endl;
		}

	void printPoint() {
		cout << " X " << px << " Y " << py << " Z " << pz << endl;
	}

private:
	pointx px;
	pointy py;
	pointz pz;
};
```

### With primary data type
```cpp
template<class pointx, int pointy, int pointz>
class MultiTypedPoint {
	public:
		MultiTypedPoint(pointx x) : px(x), py(pointy), pz(pointz) {
			cout << "MultiTypedPoint object constructor." << endl;
		}

	void printPoint() {
		cout << " X " << px << " Y " << py << " Z " << pz << endl;
	}

private:
	pointx px;
	int py;
	int pz;
};

MultiTypedPoint<float,5,5> mtypedp(5.55555555555);
```




