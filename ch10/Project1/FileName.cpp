#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class MyString {
private:
	char* str;
public:
	MyString(const char* s = nullptr) { // ������
		if (s == nullptr) {
			str = new char[1];
			*str = '\0';
		}
		else {
			str = new char[strlen(s) + 1];
			strcpy(str, s);
		}
	}
	~MyString() { delete[] str; } // �Ҹ���
	// 1. ���� ������ �����ε�
	MyString& operator=(const MyString& ref) {
		if (this == &ref)return *this;
		delete[] str;
		str = new char[strlen(ref.str) + 1];
		strcpy(str, ref.str);
		return *this;
	}	
	// 2. ������ << �����ε� (�����Լ�)
	friend ostream& operator<<(ostream& os, const MyString& a);
 };

ostream& operator<<(ostream& os, const MyString& a) {
	os << a.str;
	return os;
}

int main() {
	MyString a("Hello");
	MyString b("World");
	cout << a << endl; // "Hello" ���
	cout << b << endl; // "World" ���
	b = a; // ���� ������ ���
	cout << b << endl; // "Hello" ���
	return 0;
}