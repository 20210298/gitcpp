#include <iostream>
#include <list>
using namespace std;
bool Reverse(int n1, int n2) {	
	return n1 > n2;
}
// reverse�� �̸� ������ �ߺ��Ǿ ������ �ȵȴ�
int main() {
	list<int> lst = { 9, 1, 3, 2, 5, 4, 6, 7, 2, 3, 1, 8 };

	lst.sort(Reverse);
	cout << "�������� ����: ";
	for (int n : lst) {
		cout << n << " ";
	}
	cout << endl;

	lst.unique();
	cout << "�ߺ���� ����: ";
	for (int n : lst) {
		cout << n << " ";
	}
	return 0;
}