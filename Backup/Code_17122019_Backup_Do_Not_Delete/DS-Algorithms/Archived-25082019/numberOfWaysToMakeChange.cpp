#include <iostream>
#include <cstring>

using namespace std;

void print(int table[], int size) {
    for (int i = 0; i < size; i++) {
        cout << table[i] << " ";
    }
    cout << "\n";
}

int count( int S[], int m, int n ) 
{ 
    int table[n+1]; 

    memset(table, 0, sizeof(table)); 
    print(table, n+1);
    table[0] = 1; 
    print(table, n+1);
    cout << "\n\n";

    for(int i=0; i<m; i++) {
        cout << i << endl;
        for(int j=S[i]; j<=n; j++) { 
            table[j] += table[j-S[i]];
            print(table, n+1);
        }
    }

    return table[n]; 
}

int main (int argc, char const *argv[])
{
    int S[] = {1, 5};
    int m = 2;
    int n = 6;
    cout << count(S, 2, 6) << endl;
    return 0;
}

