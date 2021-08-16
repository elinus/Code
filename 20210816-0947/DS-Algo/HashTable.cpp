#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HashTable {
public:
  HashTable(int capacity)
      : capacity(capacity), ht_(vector<pair<string, string>>(capacity)) {}
  ~HashTable() = default;
  bool add(const string &key, const string &data) {
    unsigned long h = hash(key);
    while (ht_[h].first[0] != '\0') {
      if (ht_[h].first == key)
        return false;
      h = (h + 1) % capacity;
    }
    ht_[h].first = key;
    ht_[h].second = data;
    return true;
  }
  bool find(const string &key, string &data) {
    unsigned long h = hash(key);
    int count = capacity;
    while (ht_[h].first[0] != '\0' && count--) {
      if (ht_[h].first == key) {
        data = ht_[h].second;
        return true;
      }
      h = (h + 1) % capacity;
    }
    return false;
  }
  unsigned long hash(const string &str) {
    unsigned long hash_ = 5381;
    for (auto i = 0; i != str.size(); i++) {
      hash_ = (((hash_ << 5) + hash_) + str[i]) % capacity;
    }
    return hash_ % capacity;
  }

private:
  int capacity;
  vector<pair<string, string>> ht_;
};

int main(int argc, char const *argv[]) {
  HashTable ht(4096);
  cout << "add = " << ht.add("co", "coco") << ", h = " << ht.hash("coco")
       << endl;
  cout << "add = " << ht.add("za", "zaki") << ", h = " << ht.hash("zaki")
       << endl;
  string ans{""};
  cout << ht.find("co", ans) << endl;
  cout << "data(co) = " << ans << endl;
  return 0;
}
