#include <iostream>

using namespace std;

class Point {
private:
	int xpos, ypos;

public:
void ShowPoint()const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	/*	
	Point Add(const Point& p) {
		Point temp(xpos + p.xpos, ypos + p.ypos);
		return temp;
	}
	Point operator+(const Point& p) {
		Point pos(xpos + p.xpos, ypos + p.ypos);
		return pos;
	};
	Point operator+(const int n) {
		Point pos(xpos + n, ypos + n);
		return pos;
	};
	Point operator-(const Point& p) {
		Point pos(xpos - p.xpos, ypos - p.ypos);
		return pos;
	}*/
	friend Point operator+(const Point& a, const Point& b);
	friend Point operator-(const Point& a, const Point& b);
	friend Point operator+(const Point& a, const  int n);
};
Point operator+(const Point& a, const Point& b) {
	Point pos(a.xpos + b.xpos, a.ypos + b.ypos);
	return pos;
};
Point operator+(const Point& a,const  int n) {
	Point pos(a.xpos +n, a.ypos + n);
	return pos;
};
Point operator-(const Point& a, const Point& b) {
	Point pos(a.xpos - b.xpos, a.ypos - b.ypos);
	return pos;
};


int main() {
	Point p1(3, 4);
	Point p2(10, 20);
	Point p3 = p1 + p2;
	Point p4 = p1 + 4;
	Point p5 = p1 - p2;
	p3.ShowPoint();
	p4.ShowPoint();
	p5.ShowPoint();
	return 0;
}