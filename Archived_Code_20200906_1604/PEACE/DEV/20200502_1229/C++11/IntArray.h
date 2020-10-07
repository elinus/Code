#ifndef __INTARRAY_H__
#define __INTARRAY_H__

#include <cassert>
#include <initializer_list>

class IntArray {
    private:
    int m_Length {};
    int *m_Data {};
    public:
    IntArray() = default;
    
    IntArray(int length) 
        : m_Length { length }
    {
        assert(length >= 0);
        if (length > 0) {
            m_Data = new int[length] {};
        }
        
    }

    IntArray(std::initializer_list<int> list)
        : IntArray(static_cast<int>(list.size())) 
    {
        int count { 0 };
        for (auto i : list) {
            m_Data[count++] = i;
        }
    }

    IntArray(const IntArray&) = delete;
    IntArray& operator=(const IntArray&) = delete;
    
    ~IntArray() {
        delete [] m_Data;
    }

    void erase() {
        delete [] m_Data;
        m_Data = nullptr;
        m_Length = 0;
    }

    int& operator[](int index) {
        assert(index >= 0 && index < m_Length);
        return m_Data[index];
    }

    int getLength() const {
        return m_Length;
    }

    void reallocate(int newLength) {
        erase();
        if (newLength <= 0)
            return;
        m_Data = new int[newLength] {};
        m_Length = newLength;
        
    }

    void resize(int newLength) {
        if (m_Length == newLength) return;
        if (newLength <= 0) {
            erase();
            return;
        }
        int *data { new int[newLength] };
        if (m_Length > 0) {
            int elementsToCopy { newLength > m_Length ? m_Length : newLength };
            for (auto i { 0 }; i < elementsToCopy; i++) {
                data[i] = m_Data[i]; 
            }
        }
        delete [] m_Data;
        m_Data = data;
        m_Length = newLength;
    }

    void insertBefore(int value, int index) {
        assert(index >= 0 && index <= m_Length);
        int *data { new int[m_Length + 1] };
        for (int i = 0; i < index; i++) {
            data[i] = m_Data[i];
        }
        data[index] = value;
        for (int i = index; i < m_Length; i++) {
            data[i+1] = m_Data[i];
        }
        delete [] m_Data;
        m_Data = data;
        ++m_Length;
    }

    void remove(int index) {
        assert(index >= 0 && index < m_Length);
        if (m_Length == 1){
            erase();
            return;
        }
        int *data { new int[m_Length - 1] };
        for (int i = 0; i < index; i++){
            data[i] = m_Data[i];
        }
        for (int i = index + 1; i < m_Length; i++) {
            data[index - 1] = m_Data[i];
        }
        delete [] m_Data;
        m_Data = data;
        --m_Length;
    }

    void insertAtBeginning(int value) {
        insertBefore(value, 0);
    }

    void insertAtEnd(int value) {
        insertBefore(value, m_Length);
    }

};

#endif /* __INTARRAY_H__ */
