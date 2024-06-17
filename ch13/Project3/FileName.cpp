#include <iostream>
#include <list>
using namespace std;
bool Reverse(int n1, int n2) {	
	return n1 > n2;
}
// reverse로 이름 지으면 중복되어서 실행이 안된다
int main() {
	list<int> lst = { 9, 1, 3, 2, 5, 4, 6, 7, 2, 3, 1, 8 };

	lst.sort(Reverse);
	cout << "내림차순 정렬: ";
	for (int n : lst) {
		cout << n << " ";
	}
	cout << endl;

	lst.unique();
	cout << "중복요소 제거: ";
	for (int n : lst) {
		cout << n << " ";
	}
	return 0;
}