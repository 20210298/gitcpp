#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	vector<int> numbers = { 10, 21, 4, 45, 66, 93, 30 };
	vector<int> evens; //¦�� ���� ����
	//���� 1: ¦�� ���� evens �� ����
	for (auto a : numbers) {
		if (a % 2 == 0) {
			evens.push_back(a);
		}
	}
	//���� 2: �������� ����
	sort(evens.begin(), evens.end());
	//���� 3: evens ���
	for (auto b : evens) {
		cout << b << " ";
	}
	return 0;
}

//bubble sort�� ����