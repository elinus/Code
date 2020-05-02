/* Sunil Mourya */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n1;
    int n2;
    int n3;
    cin >> n1 >> n2 >> n3;
    int sum1 = 0, sum2 = 0, sum3 = 0;

    vector<int> h1(n1);
    for(int h1_i = 0;h1_i < n1;h1_i++){
        cin >> h1[h1_i];
        sum1 += h1[h1_i];
    }
    stack<int> S1;
    for(int i = n1-1; i >= 0; --i){
        S1.push(h1[i]);
    }

    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
        cin >> h2[h2_i];
        sum2 += h2[h2_i];
    }
    stack<int> S2;
    for(int i = n2-1; i >= 0; --i){
        S2.push(h2[i]);
    }

    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
        cin >> h3[h3_i];
        sum3 += h3[h3_i];
    }
    stack<int> S3;
    for(int i = n3-1; i >= 0; --i){
        S3.push(h3[i]);
    } 

    int diff = 0;
    while(sum1 != sum2 || sum2 != sum3){
        if(sum1 > sum2 || sum1 > sum3){
            if(!S1.empty()){
                diff = S1.top();
                sum1 -= diff;
                S1.pop();
            }
        } 
        
        if(sum2 > sum1 || sum2 > sum3){
            if(!S2.empty()){
                diff = S2.top();
                sum2-= diff;
                S2.pop();
            }
        } 
        
        if(sum3 > sum1 || sum3 > sum2){
            if(!S3.empty()){
                diff = S3.top();
                sum3 -= diff;
                S3.pop();
            }
        }
    }
    cout << sum1 << endl;
    return 0;
}

