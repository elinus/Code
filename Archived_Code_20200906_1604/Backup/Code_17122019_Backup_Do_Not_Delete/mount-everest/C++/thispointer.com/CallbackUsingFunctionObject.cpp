#include <iostream>
#include <string>

class Encryptor {
    private:
        bool mIsIncremental;
        int mCount;
    public:
        Encryptor()
            : mIsIncremental(0), mCount(1)
        {}
        Encryptor(bool isInc, int count)
            : mIsIncremental(isInc), mCount(count)
        {}
        std::string operator ()(std::string data) {
            for (int i = 0; i < data.size(); ++i) {
                if ((data[i] >= 'a' && data[i] <= 'z') || (data[i] >= 'A' && data[i] <= 'Z')) {
                    if (mIsIncremental) {
                        data[i] += mCount;
                    } else {
                        data[i] -= mCount;
                    }
                }
            }
            return data;
        }
};

std::string buildCompleteMessage(std::string rawData, Encryptor encryptFuncObj) {
    rawData = "[Header]" + rawData + "[Footer]";
    rawData = encryptFuncObj(rawData);
    return rawData;
}

int main (int argc, char *argv[]) {
    std::string msg = buildCompleteMessage("Hello World!", Encryptor(true, 1));
    std::cout << msg << "\n";
    
    msg = buildCompleteMessage("Hello World!", Encryptor(true, 2));
    std::cout << msg << "\n";
    
    msg = buildCompleteMessage("Hello World!", Encryptor(false, 1));
    std::cout << msg << "\n";
    
    return 0;
}

