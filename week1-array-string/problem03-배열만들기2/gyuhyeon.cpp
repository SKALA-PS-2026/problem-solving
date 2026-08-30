// 문제: 배열 만들기 2
// 접근 방식: 
// 시간복잡도: O(n)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    for (int i=l; i<=r; i++) {
        string num = to_string(i);
        bool flag = true;
        
        for (int j=0; j<num.length(); j++) {
            if (num[j] != '0' && num[j] != '5') {
                flag = false;
                break;
            }
        }
        
        if (flag) answer.push_back(stoi(num));
    }
    
    if (answer.size()==0) answer.push_back(-1);
    
    return answer;
}