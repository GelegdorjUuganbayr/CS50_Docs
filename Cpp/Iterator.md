# Iterator
An iterator is an object that allows the traversal of a container
- Either STL algorithms or user defined, the algorithm nearly always uses an iterator
- Generic iterator traversal that allows the algorithms to be applied to any type
- The implementation of generic code

## Type of Iterators
There are five types of iterators in c++
- **Input/Output iterator**
  - It facility sequential single pass access to container elements performing either input or output. 
- **Forward iterators**
  - These inherit the input iterator behaviour
  - These inherit the output iterator behaviour if they are non const
  - They are limited to a forward direction of traversal
  - All STL containers support at least forward iterators
- **Bidirectional iterators**
  - These inherit from forward iterators
  - Same with forward iterator except they can also move in a reverse direction.
- **Random access iterators**
  - These can also access elements non-sequentially
  - We can apply an offset directly to the iterator to access an element without having to traverse the in-between elements
  
## input/output iterator
There are two input iterators defined

### istreambuf_iterator
```cpp
std::istreambuf_iterator<char> isbuf(std::cin.rdbuf());
```
- This is created to read the characters a user types into the terminal
- What the cin.rdbuf() function call does

### istream_iterator
```cpp
std::istream_iterator<int> is(std::cin);

std::istreambuf_iterator<char> isbeos; 
std::string mystring;
while (isbuf != isbeos && *isbuf != '\n') {
	mystring += *isbuf++;
}
```
- we use a for loop to traverse the iterator like so, we will also need to detect end of stream.
  - Program go around the loop until end of stream is reached
  - The user sends the new line character by entering the return key in the terminal
  
## forward iterator
### forward_list
```cpp
//forward iterator
forward_list<int> fwdlist;
forward_list<int>::iterator fwdlistiter;
fwdlist.push_front(3);
fwdlist.push_front(2);
fwdlist.push_front(1);

cout << "Forward iterator traversal of forward_list." << endl;
for (fwdlistiter = fwdlist.begin(); fwdlistiter != fwdlist.end(); fwdlistiter++) {
	cout << (*fwdlistiter) << endl;
}
```
- This is a singly linked list that only provides traversal in the forward direction and no random access

## Bidirectional iterator
- A forward and reverse iterator to traverse the elements
- The reason we use a list is because it is implements as a double linked list
  - We can go forward and back but they don't support random access
### list
```cpp
list<int> li;
list<int>::iterator listiter;
list<int>::reverse_iterator revlistiter;
li.push_back(1);
li.push_back(2);
li.push_back(3);

//Forward traversal
cout << "Forward traversal of list." << endl;
for (listiter = li.begin(); listiter != li.end(); listiter++) {
	cout << (*listiter) << endl;
}

//Reverse traversal.
cout << "Reverse traversal of list." << endl;
for (revlistiter = li.rbegin(); revlistiter != li.rend(); revlistiter++) {
	cout << (*revlistiter) << endl;
}
```
- forward iterator
  - The for loops get a forward iterator from the begin() function
  - Loop around the list until it reaches the end iterator given by the function end()
- reverse loop
  - The reverse loop is the same except the start iterator is given by the function rbegin() which points the the end of the container
  - Loop finishes when it reaches the beginning iterator given by the rend() function
  
## Random access iterator
### vector
```cpp
vector<int> v;
vector<int>::iterator iter;

v.push_back(1);
v.push_back(2);
v.push_back(3);

iter = v.begin();
iter +=2;
cout << *iter << endl;
```

# Creating generic algorithms using iterators
A generic algorithm
- Algorithm that can be used on many different data types 
- Algorithm that can be used on different iterator classes

The algorithm is usually defined as a template function
- If they change the elements in the container, they will
  - Define an input and output iterator
  - Copy the input iterator elements to the output iterator to avoid changing the original elements

### Finds the first instance of the supplied parameter argument findEle which has template type ValueType
```cpp
template<typename InputIterator, typename valueType>
InputIterator findfirstinstance(InputIterator iterBegin, InputIterator iterEnd, const valueType& findEle){
	while (iterBegin != iterEnd && *iterBegin != findEle) {
		++iterBegin;
	}

	return iterBegin;
}
```
- The above algorithm finds the first instance of findEle by iterating from iterBegin to iterEnd and returns the iterator pointing to the element

### Merging for Merge Sort
```cpp
template<class InputIterator, class OutputIterator>
OutputIterator mergeSortedContainers(InputIterator lhsBegin, InputIterator lhsEnd,
                                      InputIterator rhsBegin, InputIterator rhsEnd, 
                                      OutputIterator result)
{
	//Copy elements retaining order until end of one container.
	while (lhsBegin != lhsEnd && rhsBegin != rhsEnd) {
		if (*lhsBegin <= *rhsBegin) {
			*result = *lhsBegin;
			++lhsBegin;
		}
		else {
			*result = *rhsBegin;
			++rhsBegin;
		}
		++result;
	}

	//Copy remaining elements.
	while (lhsBegin != lhsEnd) {
		*result = *lhsBegin;
		++lhsBegin;
		++result;
	}

	while (rhsBegin != rhsEnd) {
		*result = *rhsBegin;
		++rhsBegin;
		++result;
	}

	return result;
}
```
- The algorithm loops over both input iterators copying the result for the comparison operator < into the output iterator
- When one of the input iterators reaches the end the first loop finishes and execution proceeds to the second and third loops
- These loops copy the remaining elements from the input that did not finish in the first loop
  - Only one of these loops should execute as the other loop with have already reached it's end in the first loop
- Since the input iterators are sorted then we only need copy the remaining elements to the results iterator

### Find and Replace
```cpp
template<class ForwardIterator, typename ElementType>
void findandreplace(ForwardIterator iterBegin, ForwardIterator iterEnd,
                    const ElementType& oldEle, const ElementType& newEle)
{
	while (iterBegin != iterEnd) {
		if (*iterBegin == oldEle) {
		*iterBegin = newEle;
		}
		++iterBegin;
	}
}
```
- Find and replace function that uses a forward iterator to iterate over a container
  - Find all elements that match the parameter argument oldEle
  - Replace them with newEle
- It is ideally suited to forward iterators as we only need to iterate over the container in a forward direction once to find and replace elements.

### Reverse Copy
```cpp
template<class BidirectionalIterator, class OutputIterator>
OutputIterator reverseCopy(BidirectionalIterator iterBegin,BidirectionalIterator iterEnd,OutputIterator result){

	//Copy elements from iterEnd to results container.
	while (iterBegin != iterEnd) {
		*result++ = *--iterEnd;
	}

	return result;
}
```
- The reverseCopy algorithm returns a reversed copy of the input container
- It does this by looping over the bi directional input iterator and writing out the elements in reverse to the output iterator


### Randomise
```cpp
template<class RandomAccessIterator>
void randomise(RandomAccessIterator iterBegin, RandomAccessIterator iterEnd) {
	while (iterBegin < iterEnd) {
		iter_swap(iterBegin, iterBegin + rand() % (iterEnd - iterBegin)); //randomInteger(iterEnd - iterBegin));
		++iterBegin;
	}
}
```
- The randomise algorithm randomises the elements in a container
- It works by iterating over the container using the random access iterator parameter arguments
  - then calls the rand function to get a random number
  - then it applies the modulo operator to this and adds it to the input iterator beginning to get the random offset of an element

### Main
```cpp
int main(int argc,char* argv[]) {
	//Containers used as to apply algorithms to.
	std::forward_list<int> firstList = { 34, 77, 16, 2 };
	std::forward_list<int> secondList = { 35, 76, 18, 2 };
	std::list<int> List = { 34, 77, 16, 2, 35, 76, 18, 2 };
	std::vector<int> resultsList(8);

	//Sort containers.
	firstList.sort();
	secondList.sort();
	cout << *findfirstinstance(firstList.begin(),firstList.end(),16) << endl;
	cout << *findfirstinstance(secondList.begin(), secondList.end(), 76) << endl;
  
	//mergeSortedContainers example.
	mergeSortedContainers(firstList.begin(),firstList.end(),secondList.begin(),secondList.end(),resultsList.begin());
	for (std::vector<int>::iterator it = resultsList.begin(); it != resultsList.end(); it++) {
	  cout << *it << " ";
	}
  
	//findandreplace example.
	findandreplace(firstList.begin(),firstList.end(),16,23);
	for (std::forward_list<int>::iterator it = firstList.begin(); it != firstList.end(); it++) {
	  cout << *it << " ";
	}
  
	//reverseCopy example.
	resultsList.empty();
	resultsList.resize(List.size());
	reverseCopy(List.begin(),List.end(),resultsList.begin());
	for (std::vector<int>::iterator it = resultsList.begin(); it != resultsList.end(); it++) {
		cout << *it << " ";
	}

	//randomise example
	List.sort();
	randomise(temp.begin(),temp.end());
	for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); it++) {
		cout << *it << " ";
	}
}
```



