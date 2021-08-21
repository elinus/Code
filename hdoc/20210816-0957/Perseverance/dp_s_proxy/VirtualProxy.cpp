#include <iostream>
#include <string>
#include <memory>

struct Image {
	virtual void draw() = 0;
};

struct Bitmap : Image {
	std::string m_filename;
	Bitmap(const std::string &filename) : m_filename{ filename } {
		std::cout << "Loading image from " << m_filename << std::endl;
	}
	void draw() override {
		std::cout << "Drawing image : " << m_filename << std::endl;
	}
};

struct LazyBitmap : Image {
	std::string m_filename;
	std::unique_ptr<Bitmap> m_bitmap{ nullptr };

	LazyBitmap(const std::string &filename): m_filename{filename}
	{}
	void draw() override {
		if (!m_bitmap) m_bitmap = std::make_unique<Bitmap>(m_filename);
		m_bitmap->draw();
	}
};

//int main() {
//	//Bitmap img1{ "image1.png" };
//	//Bitmap img2{ "image2.png" };
//	//(rand() % 2) ? img1.draw() : img2.draw();
//	LazyBitmap img_1{ "image_1.png" };
//	LazyBitmap img_2{ "image_2.png" };
//	img_1.draw();
//	return 0;
//}