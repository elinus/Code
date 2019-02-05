/* Sunil Mourya */
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void CalculateMax(vector<int> &hist, int n){
    stack<int> S;
    int max_area = 0;
    int tp;
    int area_with_top;
    int i = 0;
    while(i < n){
        if(S.empty() || hist[S.top()] <= hist[i]){
            S.push(i++);
        } else {
            tp = S.top();
            S.pop();
            area_with_top = hist[tp] * (S.empty() ? i : i - S.top() - 1);
            if(area_with_top > max_area){
                max_area = area_with_top;
            }
        }
    }

    while(!S.empty()){
        tp = S.top();
        S.pop();
        area_with_top = hist[tp] * (S.empty() ? i : i - S.top() - 1);
        if(area_with_top > max_area){
            max_area = area_with_top;
        }
    }

    cout << max_area << endl;
}

int main()
{
    int n, num;
    cin >> n;
    vector<int> hist(n);
    for(int i = 0; i < n; ++i){
        cin >> hist[i];
    }
    CalculateMax(hist,n);   
    return 0;
}

