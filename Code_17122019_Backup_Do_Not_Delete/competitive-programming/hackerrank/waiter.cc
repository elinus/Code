/* Sunil Mourya */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> prime;

void init_prime(int Q){   
    prime.push_back(2);
    int  i = 3, j;
    for(int count = 2; count <= Q;)
    {
        for(j = 2; j <= i-1; ++j){
            if(i%j == 0) break;
        }
        if(i == j){
            prime.push_back(i);
            count++;
        }
        i++;
    }
}


int main()
{
    int N, Q, num;
    cin >> N >> Q;
    stack<int> input;
    stack<int> div;
    stack<int> Ndiv;
    for(int i = 0; i < N; ++i){
        cin >> num;
        input.push(num);
    }
    init_prime(Q);
    vector<int> print;
    for(int i = 0; i < Q; ++i){
        while(!input.empty()){
            if(input.top() % prime[i] == 0){
                div.push(input.top());
            } else {
                Ndiv.push(input.top());
            }
            input.pop();
        }
        input = Ndiv; // copy stack
        while(!div.empty()){
            print.push_back(div.top());
            div.pop();
        }
    }

    while(!Ndiv.empty()){
        print.push_back(Ndiv.top());
        Ndiv.pop();
    }

    vector<int>::iterator it;
    for(it = print.begin(); it != print.end(); ++it){
        cout << *it << endl;
    }
    return 0;
}

