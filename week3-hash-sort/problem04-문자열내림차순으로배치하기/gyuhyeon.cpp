// 문제: 문자열 내림차순으로 배치하기
// 접근 방식: 문자열의 문자를 greater<char>() 비교자로 내림차순 정렬한다.
// 시간복잡도: O(N log N) (N: 문자열 길이)

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    
    sort(s.begin(), s.end(), greater<char>());
    
    return s;
}