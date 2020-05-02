#include <iostream>
#include <string>

class Encryptor {
    private:
        bool mIsIncremental;
        int mCount;
    public:
        Encryptor(): mIsIncremental(true), mCount(1) {}
        Encryptor(bool incremental, int count):
            mIsIncremental(incremental), mCount(count) {}
        std::string operator ()(std::string data) {
            for (int i = 0; i < data.size(); ++i) {
                if ((data[i] >= 'a' && data[i] <= 'z') || 
                        (data[i] >= 'A' && data[i] <= 'Z')) {
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

std::string buildCompleteMessage(std::string message, Encryptor encryptorObj) {
    message = "[HEADER]" + message + "[FOOTER]";
    message = encryptorObj(message);
    return message;
}

int main(int argc, char const *argv[])
{
    std::string msg = "KeepMoving!";
    std::cout << buildCompleteMessage(msg, Encryptor()) << std::endl;
    std::cout << buildCompleteMessage(msg, Encryptor(true, 2)) << std::endl;
    std::cout << buildCompleteMessage(msg, Encryptor(false, 1)) << std::endl;
    return 0;
}

