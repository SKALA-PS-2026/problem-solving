#include <string>
#include <vector>
#include <iostream>
#include <typeinfo>
using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    bool t;
    for(int i=l; i<=r; i++)
    {
        t=true;
        string str = to_string(i);
        for(char c: str) {
            if(c != '0' && c != '5'){
                t=false;
                break;
            }
        }
        if(t){
            answer.push_back(i);
        }
    }
    
    if(answer.empty()){
        answer.push_back(-1);
    }

    return answer;
}


int main() {
    int l, r;
    cin >> l >> r;

    vector<int> result = solution(l, r);

    for(int num : result){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

