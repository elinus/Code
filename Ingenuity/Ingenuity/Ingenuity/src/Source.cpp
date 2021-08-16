//#include <iostream>
//#include <unordered_set>
//#include <string>
//#include <thread>
//#include <chrono>
//using namespace std;
//
//void coco() {
//	cout << __func__ << " tid = " << this_thread::get_id() << endl;
//	this_thread::sleep_for(chrono::milliseconds(500));
//}
//
//int main() {
//	unordered_set<string> us;
//	us.insert("Sunil");
//	us.insert("Akanksha");
//	us.insert("Coco");
//	us.insert("Zaki");
//	for (auto it = us.begin(); it != us.end(); ++it) {
//		cout << *it << endl;
//	}
//
//	thread t0(coco);
//	t0.join();
//	cout << __func__ << " tid = " << this_thread::get_id() << " exiting.." << endl;
//	return 0;
//}