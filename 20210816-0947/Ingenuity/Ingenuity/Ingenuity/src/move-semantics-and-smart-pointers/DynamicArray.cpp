#include <iostream>
using namespace std;

template <typename T>
class DynamicArray {
	T* m_array;
	int m_length;
public:
	DynamicArray(const int length) : m_array{ new T[length] }, m_length{ length }
	{}
	~DynamicArray() {
		delete[] m_array;
	}
	DynamicArray(const DynamicArray& other) {
		m_length = other.m_length;
		m_array = new T[m_length];
		for (int i = 0; i < m_length; i++) {
			m_array[i] = other.m_array[i];
		}
	}
	DynamicArray(DynamicArray&& other) noexcept : m_length{ other.m_length },
		m_array{ other.m_array } {
		other.m_length = 0;
		other.m_array = nullptr;
	}
	DynamicArray& operator=(const DynamicArray& other) {
		if (&other != this) {
			delete [] m_array;
			m_length = other.m_length;
			m_array = new T[m_length];
			for (int i = 0; i < m_length; i++) {
				m_array[i] = other.m_array[i];
			}
		}
		return *this;
	}
	DynamicArray& operator=(DynamicArray&& other) {
		if (&other != this) {
			delete[] m_array;
			m_length = other.m_length;
			m_array = other.m_array;
			other.m_length = 0;
			other.m_array = nullptr;
		}
		return *this;
	}
	int getLength() const {
		return m_length;
	}
	T& operator[](int index) {
		return m_array[index];
	}
	const T& operator[](int index) const { 
		return m_array[index]; 
	}
};