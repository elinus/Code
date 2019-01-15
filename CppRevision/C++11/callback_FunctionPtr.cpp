/*
 @notes: types of callback
 - function pointer
 - lambda expr.
 - function objects / functors
 * */

#include <iostream>
#include <string>

std::string increment(std::string msg)
{
    for (int i = 0; i < msg.size(); ++i) {
        msg[i]++;
    }
    return msg;
}

std::string decrement(std::string msg)
{
    for (int i = 0; i < msg.size(); ++i) {
        msg[i]--;
    }
    return msg;
}

std::string encrypt_msg(std::string msg, std::string (* encrypterFuncPtr)(std::string))
{
    msg = "[STRAT]" + msg + "[END]";
    msg = encrypterFuncPtr(msg);
    return msg;
}

int main (int argc, char *argv[])
{
    std::cout << encrypt_msg("TestMessage", &increment) << std::endl;
    std::cout << encrypt_msg("TestMessage", &decrement) << std::endl;
    return 0;
}

