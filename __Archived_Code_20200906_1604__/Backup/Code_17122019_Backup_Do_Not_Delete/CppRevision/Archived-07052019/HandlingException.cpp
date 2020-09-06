#include <iostream>
#include <vector>
#include <string>
#include <exception>

using namespace std;

struct errorinfo
{
    int id;
    int locationId;
    int level;
    string description;
    string reason;
};

class MyException : public std::exception {
    public:
    MyException(const string &msg) : msg(msg){}
    virtual ~MyException() noexcept {
        errorlist.clear();
    }
    virtual const char* what() const noexcept {
        return msg.c_str();
    }
    void adderror(errorinfo error) noexcept(false) {
        errorlist.push_back(error);
    }
    vector<errorinfo>::iterator begin() {
        return errorlist.begin();
    }
    vector<errorinfo>::iterator end() {
        return errorlist.end();
    }
    private:
    string msg;
    vector<errorinfo> errorlist;
};

int main(int argc, char const *argv[])
{
    try
    {
        try
        {
            try
            {
                MyException myex("MyException object thrown.");
                throw myex;
            }
            catch(MyException& e)
            {
                errorinfo firstinfo;
                firstinfo.reason = "level 1 error";  
                firstinfo.id = 1;
                firstinfo.locationId = 0;
                firstinfo.level = 0;
                firstinfo.description = "First level exception thrown.";
                try
                {
                    e.adderror(firstinfo);
                }
                catch(bad_alloc)
                {
                    cout << "Out of memory MyException.adderror bad_alloc." << endl;
                }
                throw e;
            }
            
        }
        catch(MyException& e)
        {
            errorinfo secondinfo;
            secondinfo.reason = "level 2 error";
            secondinfo.id = 2;
            secondinfo.locationId = 1;
            secondinfo.level = 2;
            secondinfo.description = "Second level exception thrown.";
            try {
                e.adderror(secondinfo);
            }
            catch (bad_alloc) {
                cout << "Out of memory myexception.adderror bad_alloc." << endl;
            }
            throw e;
        }
    }
    catch(MyException &e)
    {
        for (std::vector<errorinfo>::iterator iter = e.begin(); iter != e.end(); ++iter) {
            errorinfo next = *iter;
            cout << next.reason << " " << next.id << " " << next.locationId << " " << next.level << " " << next.description << endl;
        }
    }
    
    return 0;
}
