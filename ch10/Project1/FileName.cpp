#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class MyString {
private:
	char* str;
public:
	MyString(const char* s = nullptr) { // 생성자
		if (s == nullptr) {
			str = new char[1];
			*str = '\0';
		}
		else {
			str = new char[strlen(s) + 1];
			strcpy(str, s);
		}
	}
	~MyString() { delete[] str; } // 소멸자
	// 1. 대입 연산자 오버로딩
	MyString& operator=(const MyString& ref) {
		if (this == &ref)return *this;
		delete[] str;
		str = new char[strlen(ref.str) + 1];
		strcpy(str, ref.str);
		return *this;
	}	
	// 2. 연산자 << 오버로딩 (전역함수)
	friend ostream& operator<<(ostream& os, const MyString& a);
 };

ostream& operator<<(ostream& os, const MyString& a) {
	os << a.str;
	return os;
}

int main() {
	MyString a("Hello");
	MyString b("World");
	cout << a << endl; // "Hello" 출력
	cout << b << endl; // "World" 출력
	b = a; // 대입 연산자 사용
	cout << b << endl; // "Hello" 출력
	return 0;
}