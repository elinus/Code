#include <iostream>
#include <string>

std::string buildCompleteMessage(std::string rawData, std::string(*pEncryptFunction)(std::string)) 
{
    rawData = "[Header]" + rawData + "[Footer]";
    rawData = pEncryptFunction(rawData);
    return rawData;
}

std::string encryptDataByLetterInc(std::string data) {
    for (int i = 0; i < data.size(); ++i) 
    {
        if ((data[i] >= 'a' && data[i] <= 'z') || (data[i] >= 'A' && data[i] <= 'Z'))
            data[i]++;
    }
    return data;
}

std::string encryptDataByLetterDec(std::string data) {
    for (int i = 0; i < data.size(); ++i) 
    {
        if ((data[i] >= 'a' && data[i] <= 'z') || (data[i] >= 'A' && data[i] <= 'Z'))
            data[i]--;
    }
    return data;
}

int main (int argc, char *argv[]) 
{
    std::string msg = buildCompleteMessage("Hello World!", encryptDataByLetterInc);
    std::cout << msg << "\n";
    
    msg = buildCompleteMessage("Hello World!", &encryptDataByLetterDec);
    std::cout << msg << "\n";
    
    return 0;
}

