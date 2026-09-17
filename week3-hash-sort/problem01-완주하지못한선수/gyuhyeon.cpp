// 문제: 완주하지 못한 선수
// 접근 방식: 해시 맵에 참가자 이름별 인원수를 세고 완주자를 차감한 뒤, 1명이 남은 이름을 반환한다.
// 시간복잡도: 평균 O(N * L) (N: 참가자 수, L: 이름의 최대 길이, 해시 연산 평균 기준)

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> um;
    for (string name : participant) {
        um[name]++;
    }
    
    for (string name : completion) {
        um[name]--;
    }
    
    for (auto& p : um) {
        if (p.second == 1) {
            return p.first;
        }
    }
    
    return answer;
}