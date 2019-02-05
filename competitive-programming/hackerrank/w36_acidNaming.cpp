#include <bits/stdc++.h>

using namespace std;

string acidNaming(string acid_name) {
  int len = acid_name.size();
  int hydro = 5;
  int ic = 2;
  if (len >= 5) {
    if (acid_name[0] == 'h')
      hydro--;
    if (acid_name[1] == 'y')
      hydro--;
    if (acid_name[2] == 'd')
      hydro--;
    if (acid_name[3] == 'r')
      hydro--;
    if (acid_name[4] == 'o')
      hydro--;
  }

  if (acid_name[len - 2] == 'i')
    ic--;
  if (acid_name[len - 1] == 'c')
    ic--;

  if (hydro == 0 && ic == 0)
    return "non-metal acid";
  else if (ic == 0)
    return "polyatomic acid";
  else
    return "not an acid";
}

int main() {
  int n;
  cin >> n;
  for (int a0 = 0; a0 < n; a0++) {
    string acid_name;
    cin >> acid_name;
    string result = acidNaming(acid_name);
    cout << result << endl;
  }
  return 0;
}
