/*
 * @author Sunil Mourya
 */
#include <iostream>
#include <vector>

using namespace std;

template<class TContainer>
class ScopeGaurd {
    public:
        ScopeGaurd(TContainer *ptr)
            : engage_(true), ptr_(ptr) 
        {
            cout << __func__ << endl;
        }

        ~ScopeGaurd() {
            cout << __func__ << endl;
            if(engage_) {
                ptr_->pop_back();
            }
        }

        void disengage() {
            engage_ = false;
        }
    private:
        bool engage_;
        TContainer *ptr_;
};

int main(int argc, char *argv[])
{ 
    cout << "! < < " << __FILE__ << "/" <<__func__ << "/" << __LINE__  << " > >" << endl;
    
    vector<int> vec1;
    vector<int> vec2;

    try {
        vec1.push_back(1);
        ScopeGaurd<vector<int> > gaurd1(&vec1);
        vec2.push_back(1);
        ScopeGaurd<vector<int> > gaurd2(&vec2);
        gaurd1.disengage();
        gaurd2.disengage();
    } catch (...) {
        cout << "Caught error." << endl;
    }
    cout << "vec1 size = " << vec1.size() << ", vec2 size = " << vec2.size() << endl;
    vec1.clear();
    vec2.clear();
    
    try {
        vec1.push_back(1);
        ScopeGaurd<vector<int> > gaurd1(&vec1);
        std::bad_alloc mem_ex;
        throw mem_ex;
        vec2.push_back(1);
        ScopeGaurd<vector<int> > gaurd2(&vec2);
        gaurd1.disengage();
        gaurd2.disengage();
    } catch (std::bad_alloc e) {
        cout << "Caught error." << endl;
        cout << "ScopeGaurd error: vec1 size = " << vec1.size() << ", vec2 size = " << vec2.size() << endl;
    }

    return 0;
}

