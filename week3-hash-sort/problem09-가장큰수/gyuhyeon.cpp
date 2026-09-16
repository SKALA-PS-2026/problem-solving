// 문제: 가장 큰 수
// 접근 방식: 숫자를 문자열로 변환하고 두 문자열을 이어 붙인 결과가 더 큰 순서로 정렬한 뒤 연결하며, 모두 0이면 "0"을 반환한다.
// 시간복잡도: O(N * L * log N) (N: 숫자 수, L: 숫자의 최대 자릿수)

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> s_numbers;
    for (int num : numbers) {
        s_numbers.push_back(to_string(num));
    }
    
    sort(s_numbers.begin(), s_numbers.end(), [](const auto& s1, const auto& s2) {
        return s1 + s2 > s2 + s1;
    });
    
    if (s_numbers[0]=="0") return "0";
    
    string answer = "";
    
    for (string s : s_numbers) {
        answer += s;
    }
    
    return answer;
}