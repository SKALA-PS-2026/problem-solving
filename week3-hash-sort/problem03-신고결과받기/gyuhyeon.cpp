// 문제: 신고 결과 받기
// 접근 방식: 신고 대상별 신고자 벡터를 선형 탐색해 중복 신고를 제외하고, k번 이상 신고된 대상의 신고자에게 메일 수를 더한다.
// 시간복잡도: O(U * L + R * U * L) (U: 사용자 수, R: 신고 수, L: ID의 최대 길이; 해시 연산 평균 기준, 중복 확인은 선형 탐색)

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    unordered_map<string, int> cnt;
    unordered_map<string, vector<string>> m;
    unordered_map<string, int> get_idx;
    
    int idx = 0;
    for (string name : id_list) {
        get_idx[name] = idx++;
    }
    
    for (string rep : report) {
        istringstream ss(rep);
        string a,b;
        ss >> a >> b;
        if (find(m[b].begin(), m[b].end(), a) == m[b].end()) {
            m[b].push_back(a);
            cnt[b]++;
        }
    }
    
    for (auto& a : cnt) {
        if (a.second >= k) {
            for (string name : m[a.first]) {
                answer[get_idx[name]]++;
            }
        }
    }
    
    return answer;
}