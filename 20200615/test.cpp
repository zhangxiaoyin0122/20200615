#include <iostream>
#include <list>
using namespace std;

void test() {
	list<int> lst;
	list<char> lst2(5, 'a'); //aaaaa
	int arr[] = { 1,2,3,4,5,6,7 };
	list<int> lst3(arr, arr + 7);//1234567
	list<char> lst4(lst2.begin(), lst2.end());//aaaaa
	list<int> lst5(lst3);//1234567
	//迭代器:
	//正向可读可写
	list<int>::iterator it = lst3.begin();
	while (it != lst3.end()) {
		cout << *it << " ";
		//*it = 0;
		++it;		
	}
	cout << endl;
	//只读
	list<int>::const_iterator cit = lst3.cbegin();
	while (cit != lst3.cend()) {
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
	//反向可读可写
	list<int>::reverse_iterator rit = lst3.rbegin();
	while (rit != lst3.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	//反向只读
	list<int>::const_reverse_iterator cri = lst3.crbegin();
	while (cri != lst3.crend()) {
		cout << *cri << " ";
		++cri;
	}
	cout << endl;
	//范围for:
	//只读
	for (const int i : lst3) {
		cout << i << " ";
	}
	cout << endl;
	//可读可写
	for (int& i : lst3) {
		cout << i << " ";
	}
	cout << endl;
}
template<class T>
void printList(const list<T>& lst) {
	for (auto& e : lst)
		cout << e << " ";
	cout << endl;
}
void test2() {
	list<int> lst;
	lst.insert(lst.begin(), 1);
	list<int>::iterator it = lst.begin();
	printList(lst);
	cout << *it << endl;
	//插入元素,迭代器不会失效
	lst.insert(lst.begin(),5, 2);
	printList(lst);
	cout << *it << endl;
	list<int> copy(lst);
	lst.insert(lst.end(), copy.begin(), copy.end());
	cout << *it << endl;
	printList(lst);
	//删除操作会导致迭代器失效,需要重新更新迭代器:1. 获取erase返回值， 2. 调用迭代器接口
	it = lst.erase(it);
	cout << *it << endl;
	printList(lst);
	lst.erase(lst.begin(), lst.end());
	printList(lst);

	cout << "resize: " << endl;
	lst.resize(5);
	printList(lst);
	lst.resize(7, 1);
	printList(lst);
}

void test3() {
	list<int> lst;
	//resize(size_t n,int val):n > size时,补val;n < size时,
	lst.resize(5);
	lst.resize(7, 1);

	//remove:删除指定值,如有多个,全部删除;如果没有,则不进行删除操作
	lst.remove(1);
	printList(lst);
	lst.remove(10);
	printList(lst);
	lst.remove(0);
	printList(lst);

}
void test4() {
	list<int> lst;
	lst.push_front(1);//1
	lst.push_front(2);//21
	lst.push_back(3);//213
	lst.push_back(4);//2134
	lst.front();//2
	lst.back();//4
	lst.pop_back();//213
	lst.pop_front();//13
	printList(lst);
}
int main() {

	test4();
	return 0;
}