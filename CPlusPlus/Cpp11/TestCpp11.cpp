#include <iostream>
#include <unordered_set>
#include <string>
// #include <thread>
#include <chrono>
using namespace std;

// void coco()
// {
//     cout << __func__ << " tid = " << this_thread::get_id() << endl;
//     this_thread::sleep_for(chrono::milliseconds(500));
// }

int main(int argc, char const *argv[])
{
    unordered_set<string> us;
    us.insert("sunil");
    us.insert("akanksha");
    us.insert("coco");
    us.insert("zaki");
    for (auto it = us.begin(); it != us.end(); ++it)
    {
        cout << *it << endl;
    }

    // thread coco_thread(coco);
    // cout << __func__ << " tid = " << this_thread::get_id() << endl;
    // coco_thread.join();
    return 0;
}
