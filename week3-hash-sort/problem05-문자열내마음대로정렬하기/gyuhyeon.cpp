// 문제: 문자열 내 마음대로 정렬하기
// 접근 방식: n번째 문자를 기준으로 오름차순 정렬하고, 같은 문자이면 문자열 전체의 사전순으로 정렬한다.
// 시간복잡도: O(M * L * log M) (M: 문자열 수, L: 문자열의 최대 길이)

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {

    sort(strings.begin(), strings.end(), [n](const string& s1, const string& s2) {
        if (s1[n]==s2[n]) return s1 < s2;
        return s1[n] < s2[n];
    });
    
    return strings;
}