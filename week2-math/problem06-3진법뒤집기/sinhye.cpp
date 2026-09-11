// 문제: 3진법 뒤집기
// 접근 방식: 나누기 하면서 나머지값을 넣고 자리수 계산해서 합침
// 시간복잡도: O(log n)
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> digits;
    
    while (true) {
        if (n == 0){
            break;
        }
        
        digits.push_back(n % 3);
        
        n = n / 3;
    }
    
    int j = 0;
    for (int i = digits.size() - 1;i >= 0 ;i--) {
        answer += digits[j] * pow(3, i);
        j++;
    }
    
    return answer;
}
