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
	//������:
	//����ɶ���д
	list<int>::iterator it = lst3.begin();
	while (it != lst3.end()) {
		cout << *it << " ";
		//*it = 0;
		++it;		
	}
	cout << endl;
	//ֻ��
	list<int>::const_iterator cit = lst3.cbegin();
	while (cit != lst3.cend()) {
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
	//����ɶ���д
	list<int>::reverse_iterator rit = lst3.rbegin();
	while (rit != lst3.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	//����ֻ��
	list<int>::const_reverse_iterator cri = lst3.crbegin();
	while (cri != lst3.crend()) {
		cout << *cri << " ";
		++cri;
	}
	cout << endl;
	//��Χfor:
	//ֻ��
	for (const int i : lst3) {
		cout << i << " ";
	}
	cout << endl;
	//�ɶ���д
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
	//����Ԫ��,����������ʧЧ
	lst.insert(lst.begin(),5, 2);
	printList(lst);
	cout << *it << endl;
	list<int> copy(lst);
	lst.insert(lst.end(), copy.begin(), copy.end());
	cout << *it << endl;
	printList(lst);
	//ɾ�������ᵼ�µ�����ʧЧ,��Ҫ���¸��µ�����:1. ��ȡerase����ֵ�� 2. ���õ������ӿ�
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
	//resize(size_t n,int val):n > sizeʱ,��val;n < sizeʱ,
	lst.resize(5);
	lst.resize(7, 1);

	//remove:ɾ��ָ��ֵ,���ж��,ȫ��ɾ��;���û��,�򲻽���ɾ������
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