/*
 * @author Sunil Mourya
 */
#include <iostream>
#include <vector>

using namespace std;

void updateVector1(vector<int> &v1, vector<int> &v2, int val)
{
    cout << __func__ << endl;
    v1.push_back(val);
    try {
        v2.push_back(val);
    } catch (...) {
        v1.pop_back();
        cout << "second vector update failed." << endl;
    }
}

void updateVector2(vector<int> &v1, vector<int> &v2, int val)
{
    cout << __func__ << endl;
    v1.push_back(val);
    try {
        std::bad_alloc baObj;
        throw baObj;
        v2.push_back(val);
    } catch (...) {
        v1.pop_back();
        cout << "second vector update failed." << endl;
    }
}



int main(int argc, char *argv[])
{
    cout << "! < < " << __FILE__ << "/" <<__func__ << "/" << __LINE__ << " > >" << endl;
    vector<int> vec1;
    vector<int> vec2;
    
    updateVector1(vec1, vec2, 1);
    cout << "vec1 size = " << vec1.size() << ", vec2 size = " << vec2.size() << endl;
    updateVector2(vec1, vec2, 2);
    cout << "vec1 size = " << vec1.size() << ", vec2 size = " << vec2.size() << endl;
    return 0;
}

