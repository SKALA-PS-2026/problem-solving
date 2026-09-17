// 문제: 실패율
// 접근 방식: 스테이지별 도전자 수를 세고 남은 도달 인원으로 실패율을 구한 뒤, 실패율 내림차순 및 스테이지 번호 오름차순으로 정렬한다.
// 시간복잡도: O(M + N log N) (M: 사용자 수, N: 스테이지 수)

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> fail(N+2);
    int n = stages.size();
    for (int stage : stages) {
        fail[stage]++;
    }
    
    vector<pair<int,double>> failp;
    
    int cnt = n;
    for (int stage=1; stage<=N; stage++) {
        double fp = 0;
        if (cnt > 0) {
            fp = (double)fail[stage] / cnt;
        }

        failp.push_back({stage, fp});
        cnt -= fail[stage];
    }
    
    sort(failp.begin(), failp.end(), [](const auto& s1, const auto& s2) {
        if (s1.second == s2.second) {
            return s1.first < s2.first;
        }
        return s2.second < s1.second;
    });
    
    for (auto& s : failp) {
        answer.push_back(s.first);
    }
    
    return answer;
}