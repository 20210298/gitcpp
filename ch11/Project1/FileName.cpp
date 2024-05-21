#include <iostream>

using namespace std;

class Point {
	int xpos;
	int ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	void ShowPoint()const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

template <typename T1>
void Swap(T1& a, T1& b) {
	T1 temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 5, b = 3;
	Swap(a, b);
	cout << a << ", " << b << endl;
	Point p1(3, 4);
	Point p2(10, 20);
	Swap(p1, p2);
	p1.ShowPoint();
	p2.ShowPoint();
	return 0;
}