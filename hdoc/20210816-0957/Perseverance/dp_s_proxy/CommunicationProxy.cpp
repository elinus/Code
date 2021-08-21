#include <iostream>

template <typename T>
struct Arr2D {
	T m_arr_2d[10][10];

	struct proxy {
		T* m_arr_1d;
		proxy(T *arr) : m_arr_1d{arr}
		{}
		T& operator[](int32_t index) {
			std::cout << "using proxy object!" << std::endl;
			return m_arr_1d[index];
		}
	};

	Arr2D::proxy operator[](int32_t index) {
		return Arr2D::proxy(m_arr_2d[index]);
	}
};

int main() {
	Arr2D<int32_t> arr;
	arr[0][0] = 2;
	return 0;
}