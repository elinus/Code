#include <iostream>
#include <string>
#include <functional>

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

std::string buildCompleteMessage_(std::string rawData, std::function<std::string(std::string)> lambda_func) {
    rawData = "[Header]" + rawData + "[Footer]";
    rawData = lambda_func(rawData);
    return rawData;
}

int main (int argc, char *argv[]) {
    
    std::function<std::string(std::string, Encryptor)> func = buildCompleteMessage;
    std::string msg = func("Hello World!", Encryptor(true, 1));
    std::cout << msg << "\n";

    auto lambdaIncbyOne = [] (std::string data) -> std::string {
        for (int i = 0; i < data.size(); ++i) 
        {
            if ((data[i] >= 'a' && data[i] <= 'z') || (data[i] >= 'A' && data[i] <= 'Z'))
                data[i]++;
        }
        return data;
    };
    msg = buildCompleteMessage_("Hello World!", lambdaIncbyOne);
    std::cout << "::" << msg << "\n";
    
    return 0;
}

