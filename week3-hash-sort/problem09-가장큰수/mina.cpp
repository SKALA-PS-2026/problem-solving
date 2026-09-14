// 문제: 가장 큰 수
// 접근 방식: 숫자를 문자열로 변환 후, a+b > b+a 기준 커스텀 비교로 정렬. 정렬된 순서대로 이어붙이면 가장 큰 수 완성. 선두가 전부 0이면 "0" 반환
// 시간복잡도: O(nlogn)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    vector<string> v;
    for (auto i : numbers) v.push_back(to_string(i));
    sort(v.begin(), v.end(), compare);
    
    string answer = "";
    for (auto s : v) answer += s;
    if (answer[0] == '0') return "0";
    return answer;
}
