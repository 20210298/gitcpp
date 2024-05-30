#include <iostream>

using namespace std;

// ����� ���� ���� Ŭ����: ��� ���� �ʰ� ����
class StackOverflowError {
	//1. ����
private:
	int depth;
public:
	StackOverflowError(int depth) :depth(depth) {}
	void ShowExceptionReason() const {
		cout <<"��� ���� �ʰ� : �Լ� ȣ�� ������ �ʹ� ����ϴ�";
	}
};
// ��� ���̸� �����ϴ� �Լ�
void RecurFunc(int depth, int maxDepth) {
	//2. ����
	cout << "��� ����: " << depth << endl;	
	if (depth == maxDepth) {
		cout << "���� �߻�: ";
		throw(StackOverflowError(depth));
	}
	RecurFunc(++depth, maxDepth);	
}

int main() {
	int maxDepth;
	cout << "�ִ� ��� ���̸� �Է��ϼ���: ";
	cin >> maxDepth;
	//3. ����
	try {
		RecurFunc(1, maxDepth);
	}
	catch (StackOverflowError&expn){
		expn.ShowExceptionReason();
	}
	return 0;
}