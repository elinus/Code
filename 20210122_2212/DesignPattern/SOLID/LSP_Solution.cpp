#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <memory>

using namespace std;

struct Shape {
	virtual uint32_t area() const = 0;
};

struct Rectangle : Shape {
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
	uint32_t area() const override {
		return m_width * m_height;
	}
private:
	uint32_t m_width, m_height;
};

struct Square : Shape {
	Square(uint32_t size) : m_size{ size } {}
	void set_size(uint32_t size) {
		m_size = size;
	}
	uint32_t area() const {
		return m_size * m_size;
	}
private:
	uint32_t m_size;
};

struct ShapeFactory {
	static unique_ptr<Shape> CreateRectangle(uint32_t width, uint32_t height);
	static unique_ptr<Shape> CreateSquare(uint32_t size);
};

unique_ptr<Shape> ShapeFactory::CreateRectangle(uint32_t width, uint32_t height) {
	return move(unique_ptr<Rectangle>(new Rectangle(width, height)));
}

unique_ptr<Shape> ShapeFactory::CreateSquare(uint32_t size) {
	return move(unique_ptr<Square>(new Square(size)));
}

void process(unique_ptr<Shape> up_s) {
	cout << up_s->area() << "\n";
}

// main_20210201_1833
int main_20210201_1833() {
	
	process(move(ShapeFactory::CreateRectangle(5, 5)));
	process(move(ShapeFactory::CreateSquare(5)));
	return 0;
}


