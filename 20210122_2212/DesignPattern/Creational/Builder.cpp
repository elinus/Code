#include <bits/stdc++.h>
using namespace std;

class HtmlBuilder;

class HtmlElement {
  string m_name;
  string m_text;
  vector<HtmlElement> m_childs;
  constexpr static size_t m_indent_size = 4;
  HtmlElement() = default;
  HtmlElement(const string &name, const string &text)
      : m_name{name}, m_text{text} {}
  friend class HtmlBuilder;

public:
  string str(int32_t indent = 0) {
    ostringstream oss;
    oss << string(m_indent_size * indent, ' ') << "<" << m_name << ">" << endl;
    if (m_text.size())
      oss << string(m_indent_size * (indent + 1), ' ') << m_text << endl;
    for (auto &element : m_childs) {
      oss << element.str(indent + 1);
    }
    oss << string(m_indent_size * indent, ' ') << "</" << m_name << ">" << endl;
    return oss.str();
  }
  static unique_ptr<HtmlBuilder> build(string root_name) {
    return make_unique<HtmlBuilder>(root_name);
  }
};

class HtmlBuilder {
  HtmlElement m_root;

public:
  HtmlBuilder(string root_name) { m_root.m_name = root_name; }
  HtmlBuilder *add_child(string child_name, string child_text) {
    m_root.m_childs.emplace_back(HtmlElement{child_name, child_text});
    return this;
  }
  string str() { return m_root.str(); }
  operator HtmlElement() { return m_root; }
};

int main(int argc, char const *argv[]) {
  auto builder = HtmlElement::build("ul");
  builder->add_child("li", "hello")->add_child("li", "world");
  cout << builder->str() << endl;
  return 0;
}
