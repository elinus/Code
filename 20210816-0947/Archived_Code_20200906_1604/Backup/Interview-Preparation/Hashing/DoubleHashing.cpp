#include <iostream>

const int TABLE_SIZE = 11;
const int PRIME = 7;

class DoubleHash {
    private:
        int* mHashTable;
        int mKeys;
    public:
        DoubleHash()
            : mHashTable(new int[TABLE_SIZE]), mKeys(0) {
                for (int i = 0; i < TABLE_SIZE; i++) {
                    mHashTable[i] = -1;
                }
        }
        
        ~DoubleHash() {
            delete [] mHashTable;
        }
        
        int Hash1(int key) {
            return key % TABLE_SIZE;
        }

        int Hash2(int key) {
            return PRIME - (key % PRIME);
        }

        void Insert(int key) {
            if (mKeys == TABLE_SIZE) {
                std::cout << "Error: Hash table is full!\n";
                return;
            }

            int index1 = Hash1(key);
            if (mHashTable[index1] != -1) {
                int index2 = Hash2(key);
                int i = 1;
                while (true) {
                    int nIndex = (index1 + i * index2) % TABLE_SIZE;
                    if (mHashTable[nIndex] == -1) {
                        mHashTable[nIndex] = key;
                        break;
                    } else {
                        i++;
                    }
                }
            } else {
                mHashTable[index1] = key;
            }
            mKeys++;
        }
        
        void PrintHashTable() {
            for (int i = 0; i < TABLE_SIZE; i++) {
                if (mHashTable[i] != -1) {
                    std::cout << i << " ------- " << mHashTable[i] << "\n";
                } else {
                    std::cout << i << "\n";
                }
            }
        }
};

int main (int argc, char *argv[]) {
    DoubleHash dhObj;
    int arr[] = { 91, 25, 36, 58, 14, 20, 28, 91, 25, 36, 58, 14};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        dhObj.Insert(arr[i]);
    }
    dhObj.PrintHashTable();
    return 0;
}

