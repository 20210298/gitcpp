#include <iostream>

using namespace std;

int main() {
	int arr[5] = { 1, 2, 3, 4, 5 };
	int idx;
	//����//
	while (true) {
		cout << "�迭 �ε��� �Է� :";
		cin >> idx;
		try {
			if (idx >= 5) throw(1);
			if (idx < 0) throw(1.0);
			cout << idx << "��° ��: " << arr[idx] << endl;
		}		
		catch (int ex1) {
			cout << "���� �߻�: ���� �ʰ�" << endl;
		}
		catch (double ex2) {
			cout << "���ܹ߻� : ��ȿ���� ���� �ε���" << endl;
		}
	}
	return 0;
}