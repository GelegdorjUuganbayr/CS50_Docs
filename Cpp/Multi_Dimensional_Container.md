# Multi-dimensional container
it is easier to create a template class that takes the number of dimensions as a template a parameter and generates the necessary number of containers at compile time

```cpp
template<size_t dimcount, typename T, size_t vecSize >
class multiVector {
	private:
		std::vector< multiVector<dimcount - 1, T, vecSize>> vec;
	public:

		multiVector() : vec(vecSize) {
			multiVector<dimcount - 1, T, vecSize>(); 
		}


		const multiVector<dimcount - 1, T, vecSize>& operator[] (int m) const {
			return vec.at(m); 
		}

		multiVector<dimcount - 1, T, vecSize>& operator[] (int m) {
			return vec.at(m); 
		}
};

template<typename T,size_t vecSize>
class multiVector<1, T,vecSize> {
	private:
		std::vector<T> vec;
	public:

		multiVector() : vec(vecSize) {}


		T& operator[] (const int index) {
			return vec[index];
		}

		T& operator[] (int m) const {
			return vec[m];
		}

};
```
- The first version of multiVector is the recursive class and the second version is the base class
- We store a private member vector vec which is initialised in the default constructor
  - the recursive call is made
  - this calls the multiVector class until dimcount is 1 and then the base class version is invoked
- The operator[] is overridden in both classes and is recursive until the base class where it returns the element in the base class vector

### main
```cpp
int main() {

	vector<vector<vector<int> > > vec;  //3 dim vec

	//Fill vectors
	for (int i = 0; i < 5; i++) {
		vector<vector<int>> vv;
		for (int j = 0; j < 10; j++) {
			vector<int> ve;
			for (int t = 0; t < 3; t++) {
				ve.push_back(t);
			}
			vv.push_back(ve);
		}
		vec.push_back(vv);
	}

	//Print contents
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			for (int t = 0; t < 3; t++) {
				cout << " element index " << t << " is " << vec[i][j][t] << "\n";
			}
		}
	}

	multiVector<4, int, 5> vec4;
	cout << "accessing vec4[1][2][3][4][4] = 7 \n";
	vec4[1][2][3][4] = 7;  
	cout << "reading vec4[1][2][3][4][4] is ";
	cout << vec4[1][2][3][4] << "\n";

	//Just to prove good for N dimensions 100*100=10,000 vectors !!!.
	multiVector<4, int, 100> bigVec;

	return 0;
}
```
- multiVector<4,int,5> is created which has 4 dimensions each of size 5 and holding integers
- template class can scale we create a multiVector which has 4 dimensions and each dimension has size 100

