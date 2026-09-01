// 문제: 문자열 내림차순으로 배치하기
// 접근 방식: 정렬 떄려박음
// 시간복잡도: On

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    sort(s.begin(),s.end(),greater<char>());
    return s;
}
