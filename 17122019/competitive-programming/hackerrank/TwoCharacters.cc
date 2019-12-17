/* Sunil Mourya */
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    int N;
    cin >> N;
    string input;
    cin >> input;
    
    vector<int> alpha(26,0);
    vector<char> in;
    for(int i = 0; i < N; ++i){
        alpha[input[i] - 'a']++;
    }

    for(int i = 0; i < 26; ++i){
        if(alpha[i]) {
            in.push_back(i + 'a');
        }
    }

    int count = 0;
    int max = 0;
    char current = '\0';
    vector<char>::iterator first;
    vector<char>::iterator second;
    for(first = in.begin(); first != in.end(); ++first){
        for(second = in.begin(); second != in.end(); ++second){
            if(*first != *second){
                current = *first;
                for(int i = 0; i < N; ++i){
                    if(input[i] != *first && input[i] != *second){ // SKIP
                    } else if(input[i] != current && input[i] == *second){
                        count++;
                        current = *second;
                    } else if(input[i] != current && input[i] == *first){
                        count++;
                        current = *first;
                    } else {
                        count = 0;
                        break;
                    }
                }
                if(count > max){
                    max = count;
                }
                count = 0;
            }
        }
    }
    cout << max << endl;
    return 0;
}

