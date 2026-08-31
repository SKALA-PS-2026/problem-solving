// 문제: 자연수 뒤집어 배열로 만들기
// 접근 방식: 
// 시간복잡도: 

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    while(n > 0) {
        answer.push_back(n % 10);
        n /= 10;
    }
    return answer;
}
