#include <iostream>
#include <vector>

using namespace std;

template <class TContainer>
class VecScopeGuard {
    public:
    VecScopeGuard(TContainer *container): container(container), engaged(true)
    {}
    ~VecScopeGuard() {
        if (engaged) {
            container->pop_back();
        }
    }
    void disengage() {
        engaged = false;
    }
    private:
    TContainer *container;
    bool engaged;
};

int main(int argc, char const *argv[])
{
    vector<int> vec1;
    vector<int> vec2;
    try {
        VecScopeGuard<vector<int>> vec1guard(&vec1);
        VecScopeGuard<vector<int>> vec2guard(&vec2);
        vec1.push_back(14);
        vec2.push_back(14);
        vec1guard.disengage();
        vec2guard.disengage();
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    cout << "vec1 size = " << vec1.size() << ", vec2 size = " << vec2.size() << endl;

    cout << "\n\n";
    try
    {
        VecScopeGuard<vector<int>> vec1guard(&vec1);
        vec1.push_back(14);
        std::bad_alloc ex;
        throw ex;

        VecScopeGuard<vector<int>> vec2guard(&vec2);
        vec2.push_back(14);
        vec1guard.disengage();
        vec2guard.disengage();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    cout << "vec1 size = " << vec1.size() << ", vec2 size = " << vec2.size() << endl;

    return 0;
}
