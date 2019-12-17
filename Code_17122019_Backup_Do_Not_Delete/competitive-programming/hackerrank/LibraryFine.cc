# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <cctype>
# include <iostream>
# include <string>
# include <algorithm>
# include <iterator>
# include <stack>
# include <queue>
# include <vector>
# include <list>
# include <set>
# include <map>

using namespace std;

struct Date {
    int D, M, Y;
};

int main()
{
    struct Date aa, ee;
    cin >> aa.D >> aa.M >> aa.Y;
    cin >> ee.D >> ee.M >> ee.Y;
    int fine = 0;
    if(aa.Y - ee.Y < 0){
        fine = 0;
    } else if(aa.Y - ee.Y > 0){
        fine = 10000;
    } else if(aa.M - ee.M < 0){
        fine = 0;
    } else if(aa.M - ee.M > 0){
        fine = 500 * (aa.M - ee.M);
    } else if(aa.D - ee.D < 0){
        fine = 0;
    } else {
        fine = 15 * (aa.D - ee.D);
    }
    cout << fine << endl;
    return 0;
}

