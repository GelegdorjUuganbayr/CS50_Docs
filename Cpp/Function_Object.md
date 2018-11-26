# Function Object
A function object is an object that behaves like a function
- It is callable but we use an object as the object can also store data
- The object usually defines the operator operator() which is known as the call operator
  - This is what gets executed when our function object is invoked as a function
- Many of the algorithms in the STL accept function objects as parameters
  - find_if, sort, equal_to, greater_equal, logical_not

### Structure and Class
```cpp
struct sortedStruct
{
	int val;

	sortedStruct(int k) : val(k) {}

	bool operator < (const sortedStruct& rhs) const
	{
		return (val < rhs.val);
	}
};

class sortedClass
{
public:
	sortedClass(int x) :val(x) {}
	~sortedClass() {};
	int getVal() const { return val; }
	bool operator < (const sortedClass& sc) const { 
		return val < sc.getVal(); 
	}
private:
	int val;
};

class lessThan {
public:
	lessThan() {};
	~lessThan() {};
	bool operator()(const sortedClass& lhs, const sortedClass& rhs) const { 
		return lhs < rhs; 
	};
	bool operator()(const sortedStruct& lhs, const sortedStruct& rhs) const {
		return lhs < rhs;
	};
};

class greaterThan {
public:
	greaterThan(int cmp): X(cmp) {};
	~greaterThan() {};
	bool operator()(const sortedClass& z) const { return z.getVal() > X; } //> comparison
	bool operator()(const sortedStruct& z) const { return z.val > X; } //> comparison
private:
	int X;
};
```
- struct and a class which have the same functionality are defined
- They both have an int variable val which is assigned upon object creation
- The operator < is defined as this is used to perform comparisons between the objects
- A lessThan class is defined which has operator() defined for both the classes and struct types
- A greaterThan class is defined above which the function object has:
  - A private member which is used to do the comparison against
  - A private member is assigned on object construction
  
### main
```cpp
int main(int argc, char* argv[]) {

	vector<sortedClass> vecSortClas;
	vector<sortedStruct> vecSortStru;
	for (int i = 0; i < 50; i++) {
		sortedClass sc(i);
		sortedStruct ss(i);
		vecSortClas.push_back(sc);
		vecSortStru.push_back(ss);
	}

	randomise(vecSortClas.begin(),vecSortClas.end());
	randomise(vecSortStru.begin(), vecSortStru.end());

	//Sorted Class
	// Vector of sortedClass classes before sorting
	for (vector<sortedClass>::iterator it = vecSortClas.begin(); it != vecSortClas.end(); it++) {
		cout << "sortedClass index " << distance(vecSortClas.begin(),it) << " has value " << it->getVal() << "\n";
	}

	// Vector of sortedClass classes after sorting
	std::sort(vecSortClas.begin(),vecSortClas.end(),lessThan());
	for (vector<sortedClass>::iterator it = vecSortClas.begin(); it != vecSortClas.end(); it++) {
		cout << "sortedClass index " << distance(vecSortClas.begin(), it) << " has value " << it->getVal() << "\n";
	}

	//SortedStruct
	//Vector of sortedStruct Structs before sorting
	for (vector<sortedStruct>::iterator it = vecSortStru.begin(); it != vecSortStru.end(); it++) {
		cout << "sortedClass index " << distance(vecSortStru.begin(), it) << " has value " << it->val << "\n";
	}
	
	// Vector of sortedStruct structs after sorting;
	std::sort(vecSortStru.begin(), vecSortStru.end(), lessThan());
	for (vector<sortedStruct>::iterator it = vecSortStru.begin(); it != vecSortStru.end(); it++) {
		cout << "sortedClass index " << distance(vecSortStru.begin(), it) << " has value " << it->val << "\n";
	}
  
	// Vector of sortedStruct structs which are greater than 45
	for (vector<sortedStruct>::iterator it = vecSortStru.begin(); it != vecSortStru.end(); it++) {
		vector<sortedStruct>::iterator it2 = it;
		auto ittemp = find_if(it2, it2+1, greaterThan(45));
		if (ittemp != it2+1) {
			cout << "sortedClass index " << distance(vecSortStru.begin(), it) << " is greater than 45 " << ittemp->val << "\n";
		}
	}

	//Destroy elements.
	vecSortClas.empty();
	vecSortStru.empty();

	return 0;
} 
```
- Create two vector containers and then populates them with 50 sortedStruct and sortedClass objects
- Each vectors contents are then printed to standard output before and after applying the sort algorithm using the lessThan class as a predicate
- Finally the sortedStruct vector is iterated over applying the greaterThan class to each element and printing out the values of those elements greater than 45

## overload[]
Create our own array class
-  Have to provide access functions to access the array elements
  - but this is not what we are used to when indexing array elements
- Instead we can overload the subscript operator
- Reason of using overload[]
  - We would usually only overload the subscript operator in classes:
    - that are going to hold a sequence of elements
    - you could provide access functions to the elements it is a better solution to overload the subscript operator


```cpp
template<typename arrayType,int size>
class genericArray {
private:
	arrayType m_array[size];

public:
	arrayType& operator[] (const int index) { //Writing
		if (index > size) {
			cout << "Index out of bounds" << endl;
			// return last element.
			return m_array[size-1];
		}
		return m_array[index];
	}

	arrayType operator[] (int index) const { //Reading
		if (index > size) {
			cout << "Index out of bounds" << endl;
			// return last element.
			return m_array[size-1];
		}
		return m_array[index];
	}
};
```
- Creates a template class object with a private member array whose elements have the template type argument arrayType
- const instances of the class so the subscript operator used for reading needs to be const
- check on the index parameter for out of bounds behaviour

### main
```cpp
int main(int argc, char* argv[]) {

	genericArray<int, 5> myIntArray;
	genericArray<double, 5> myDoubleArray;
	genericArray<float, 5> myFloatArray;

	for (int i = 0; i < 5; i++) {
		myIntArray[i] = i*2;
		myDoubleArray[i] = (double)(i * 2.0);
		myFloatArray[i] = (float)(i * 2.0);
	}

	for (int i = 0; i < 5; i++) {
		cout << "myIntArray[" << i << "] is " << myIntArray[i] << "\n";
	}

	for (int i = 0; i < 5; i++) {
		printf("myFloatArray[%i] is %lf \n", i, myFloatArray[i]);
	}

	for (int i = 0; i < 5; i++) {
		printf("myFloatArray[%i] is %f \n", i, myFloatArray[i]);
	}

	cout << myIntArray[99] << "\n\n";

	return 0;
}
```
- The reason the subscript operator returns a reference is because array assignment is an l-value which means it must have a memory address and references are always l-values.


