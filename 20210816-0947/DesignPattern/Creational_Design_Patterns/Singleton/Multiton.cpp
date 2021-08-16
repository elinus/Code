#include <iostream>
#include <map>
#include <memory>
#include <string>

enum class Importance { Primary, Secondary, Tertiary };

template <typename T, typename Key = std::string> class Multiton {
private:
  static std::map<Key, std::shared_ptr<T>> m_instances;

public:
  static std::shared_ptr<T> get(const Key &key) {
    for (auto it = m_instances.begin(); it != m_instances.end(); ++it) {
      if (it->first == key)
        return it->second;
    }
    return m_instances[key] = std::make_shared<T>();
  }
};

template <typename T, typename Key>
std::map<Key, std::shared_ptr<T>> Multiton<T, Key>::m_instances;

struct Printer {
public:
  Printer() {
    std::cout << "Printer instance #" << ++m_intsance_count << std::endl;
  }

private:
  static int m_intsance_count;
};
int Printer::m_intsance_count = 0;

int main(int argc, char const *argv[]) {
  using mt = Multiton<Printer, Importance>;
  auto main1 = mt::get(Importance::Primary);
  auto main2 = mt::get(Importance::Primary);
  auto sec = mt::get(Importance::Secondary);
  auto ter = mt::get(Importance::Tertiary);
  return 0;
}
