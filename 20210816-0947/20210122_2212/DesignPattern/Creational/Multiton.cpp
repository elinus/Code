#include <bits/stdc++.h>

using namespace std;

enum class Importance { PRIMARY, SECONDARY, TERTIARY };

template <typename T, typename Key = string> struct Multiton {
  static shared_ptr<T> get(const Key &key) {
    auto it = m_instances.find(key);
    if (it != m_instances.end()) {
      return it->second;
    }
    return m_instances[key] = make_shared<T>();
  }

private:
  static map<Key, shared_ptr<T>> m_instances;
};

template <typename T, typename Key>
map<Key, shared_ptr<T>> Multiton<T, Key>::m_instances;

struct Printer {
  Printer() { cout << "Total instances so far = " << ++InstCnt << endl; }

private:
  static int InstCnt;
};
int Printer::InstCnt = 0;

int main(int argc, char const *argv[]) {
  using mt = Multiton<Printer, Importance>;
  auto main = mt::get(Importance::PRIMARY);
  auto aux1 = mt::get(Importance::SECONDARY);
  auto aux2 = mt::get(Importance::SECONDARY);
  return 0;
}
