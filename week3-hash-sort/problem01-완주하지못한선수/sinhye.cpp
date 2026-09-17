// 문제: 완주하지 못한 선수
// 접근 방식: 해시맵을 이용해서 참가자에서 완주자 제외
// 시간복잡도: O(N)
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> marathon;
    
    for (const string& p : participant) {
        marathon[p]++;
    }
    
    for (const string& c : completion) {
        marathon[c]--;
    }
    
    for (const pair<string, int>& m : marathon) {
        if (m.second > 0) {
            answer = m.first;
        }
    }
    
    return answer;
}
