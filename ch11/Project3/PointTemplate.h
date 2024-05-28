#ifndef __POINT_TEMPLATE_H__
#define __POINT_TEMPLATE_H__
template <typename T>
class Point {
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0) : xpos(x), ypos(y) {}
	void ShowPoint() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	template <typename U>
	friend ostream& operator<< (ostream& os, const Point<U>& pos) {
		os << "[" << pos.xpos << ", " << pos.ypos << "]";
		return os;
	}
};
#endif