#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

struct Rectangle {
	Rectangle(uint32_t width, uint32_t height)
		: m_width{ width }, m_height{ height } {}
	uint32_t get_width() const {
		return m_width;
	}
	uint32_t get_height() const {
		return m_height;
	}
	virtual void set_width(uint32_t width) {
		m_width = width;
	}
	virtual void set_height(uint32_t height) {
		m_height = height;
	}
	uint32_t area() const {
		return m_width * m_height;
	}
protected:
	uint32_t m_width, m_height;
};

struct Square : Rectangle {
	Square(uint32_t size) : Rectangle(size, size) {}
	void set_width(uint32_t width) override {
		m_width = m_height = width;
	}
	void set_height(uint32_t height) override {
		m_height = m_width = height;
	}
};

void process(Rectangle& r) {
	uint32_t w = r.get_width();
	r.set_height(10);
	assert((10 * w) == r.area());
}

// main_20210201_1758
int main_20210201_1758() {
	Rectangle r{ 5, 5 };
	process(r);
	Square s{ 5 };
	process(s);
	return 0;
}