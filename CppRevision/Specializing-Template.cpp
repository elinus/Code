#include <iostream>

using namespace std;

template<int N>
void printCountUp() {
	printCountUp<N-1>();
	cout << N << " ";
}

template<>
void printCountUp<0>() {
	 cout << 0 << "\n";
} 

int main (int argc, char *argv[])
{
    printCountUp<100>();
    return 0;
}

