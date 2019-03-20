#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  try {
    throw 1;
  } catch (int ei) {
    cout << "Int exception" << endl;
  } catch (double ed) {
    cout << "Double exception" << endl;
  } catch (...) {
    cout << "All other exception types" << endl;
  }

  try {
    throw 1.1;
  } catch (int ei) {
    cout << "Int exception" << endl;
  } catch (double ed) {
    cout << "Double exception" << endl;
  } catch (...) {
    cout << "All other exception types" << endl;
  }

  try {
    throw true;
  } catch (int ei) {
    cout << "Int exception" << endl;
  } catch (double ed) {
    cout << "Double exception" << endl;
  } catch (...) {
    cout << "All other exception types" << endl;
  }

  return 0;
}
