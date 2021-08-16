//#include <algorithm>
//#include <cstdlib>
//#include <iostream>
//#include <iterator>
//#include <vector>
//
//using namespace std;
//
//struct RandomGenerator {
//    int m_MaxValue;
//    RandomGenerator(int maxValue) : m_MaxValue(maxValue) {}
//    int operator()() { return rand() % m_MaxValue; }
//};
//
//template <typename T> void print(const vector<T>& vec) {
//    copy(vec.begin(), vec.end(), ostream_iterator<T>(cout, " "));
//    cout << endl;
//}
//
//class Encryptor {
//private:
//    int count;
//    bool increment;
//
//public:
//    Encryptor(int count, bool increment) : count(count), increment(increment) {}
//    string operator()(string data) {
//        for (size_t i = 0; i < data.size(); i++) {
//            if ((data[i] >= 'a' && data[i] <= 'z') ||
//                (data[i] >= 'A' && data[i] <= 'Z')) {
//                if (increment) {
//                    data[i] += count;
//                }
//                else {
//                    data[i] -= count;
//                }
//            }
//        }
//        return data;
//    }
//};
//
//string message(string msg, Encryptor encryptor) {
//    msg = "[Start]" + msg + "[End]";
//    return encryptor(msg);
//}
//
//int main(int argc, char const* argv[]) {
//    vector<int> vec_of_rand_nums(14);
//    generate(vec_of_rand_nums.begin(), vec_of_rand_nums.end(),
//        RandomGenerator(500));
//    print(vec_of_rand_nums);
//
//    cout << message("Coco", Encryptor(14, true)) << endl;
//    cout << message("Coco", Encryptor(20, true)) << endl;
//    cout << message("Coco", Encryptor(21, false)) << endl;
//    return 0;
//}
