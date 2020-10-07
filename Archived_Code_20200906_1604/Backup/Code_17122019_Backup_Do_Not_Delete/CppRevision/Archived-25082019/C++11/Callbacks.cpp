#include <iostream>
#include <string>

std::string encryptDataByLetterInc(std::string data) {
    for (int i = 0; i < data.size(); ++i) {
        if ((data[i] >= 'a' && data[i] <= 'z') || 
                (data[i] >= 'A' && data[i] <= 'Z')) {
            data[i]++;
        }
    }
    return data;
}

std::string buildCompleteMessage(std::string message, std::string(*fptr)(std::string)) {
    message = "[HEADER]" + message + "[FOOTER]";
    message = fptr(message);
    return message;
}

int main(int argc, char const *argv[])
{
    std::string msg = "KeepMoving!";
    std::cout << buildCompleteMessage(msg, &encryptDataByLetterInc) << std::endl;
    return 0;
}

