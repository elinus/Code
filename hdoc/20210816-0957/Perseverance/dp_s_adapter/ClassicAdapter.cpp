#include <iostream>

struct Point {
	int32_t m_x;
	virtual void draw() {
		std::cout << "Point" << std::endl;
	}
};

struct Point2d : Point {
	int32_t m_y;
	void draw() {
		std::cout << "Point2d" << std::endl;
	}
};

void draw_point(Point& p) {
	p.draw();
}

struct Line {
	Point2d m_start;
	Point2d m_end;
	void draw() {
		std::cout << "Line" << std::endl;
	}
};

struct LineAdapter : Point {
	Line& m_line;
	LineAdapter(Line& line) : m_line{ line } {}
	void draw() {
		m_line.draw();
	}
};

int main() {
	Line l;
	LineAdapter la(l);
	draw_point(la);
	return 0;
}