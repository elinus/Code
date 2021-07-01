#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<string> fizzBuzz(int A) {
  vector<string> res(A);
  for (int i = 1; i <= A; i++) {
    if ((i % 3 == 0) && (i % 5 == 0)) {
      res[i - 1] = "FizzBuzz";
    } else if (i % 3 == 0) {
      res[i - 1] = "Fizz";
    } else if (i % 5 == 0) {
      res[i - 1] = "Buzz";
    } else {
      res[i - 1] = to_string(i);
    }
  }
  return res;
}
