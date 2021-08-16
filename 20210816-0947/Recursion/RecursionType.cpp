#include <iostream>
using namespace std;

// Head recursion
void head_recur(int n) {
  if (n > 0) {
    head_recur(n - 1);
    cout << n << " ";
  }
}

// Tail recursion
void tail_recur(int n) {
  if (n > 0) {
    cout << n << " ";
    tail_recur(n - 1);
  }
}

// Tree recursion
void tree_recur(int n) {
  if (n > 0) {
    cout << n << " ";
    tree_recur(n - 1);
    tree_recur(n - 1);
  }
}

// Nested recursion
int nested_recur(int n) {
  if (n > 100) {
    return n - 10;
  }
  return nested_recur(nested_recur(n + 11));
}

// Indirect recursion
void bar(int n);
void foo(int n) {
  if (n > 0) {
    cout << __func__ << " :: " << n << endl;
    bar(n - 1);
  }
}

void bar(int n) {
  if (n > 0) {
    cout << __func__ << " :: " << n << endl;
    foo(n / 2);
  }
}

int main(int argc, char const *argv[]) {
  cout << "Head recur #=> ";
  head_recur(3);
  cout << endl;

  cout << "Tail recur #=> ";
  tail_recur(3);
  cout << endl;

  cout << "Tree recur #=> ";
  tree_recur(3);
  cout << endl;

  cout << "Indirect recur #\n";
  foo(20);
  cout << endl;

  cout << "Nested recur #=> " << nested_recur(95) << endl;
  return 0;
}
