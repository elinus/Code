#include <iostream>
#include <functional>
#include <memory>

using namespace std;
using namespace std::placeholders;

int add(int x, int y)
{
    cout << "x: " << x << ", y:" << y <<endl;
    return x+y;
}

int main (int argc, char *argv[])
{
    cout << add(14, 20) << endl;
    auto add_bind_ =  std::bind(&add, _1, _2);
    cout << add_bind_(14, 20) << endl;
    
    auto add_bind_rev_ = std::bind(&add, _2, _1);
    cout << add_bind_rev_(14, 20) << endl; 

    std::function<int (int) > mod_add_funcObj = std::bind(&add, 20, _1);
    int x = mod_add_funcObj(14);
    cout << x << endl;
    return 0;
}

