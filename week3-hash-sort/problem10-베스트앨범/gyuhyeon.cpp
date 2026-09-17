// 문제: 베스트앨범
// 접근 방식: 해시 맵으로 장르별 총 재생 수와 곡 목록을 모으고, 장르를 총 재생 수 내림차순으로 정렬한 뒤 각 장르에서 재생 수 내림차순·고유 번호 오름차순으로 최대 2곡을 선택한다.
// 시간복잡도: 평균 O(N * L + N log N) (N: 곡 수, L: 장르명의 최대 길이, 해시 연산 평균 기준)

#include <bits/stdc++.h>

using namespace std;

struct Genre {
    int tot = 0;
    vector<pair<int, int>> list;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, Genre> gm;

    for (int i = 0; i < genres.size(); i++) {
        gm[genres[i]].tot += plays[i];
        gm[genres[i]].list.push_back({i, plays[i]});
    }

    vector<Genre> gv;

    for (auto& [genre, g] : gm) {
        gv.push_back(g);
    }
    
    sort(gv.begin(), gv.end(), [](const auto& a, const auto& b) {
        return a.tot > b.tot;
    });
    
    for (Genre g : gv) {
        sort(g.list.begin(), g.list.end(), [](const auto& a, const auto& b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });
        
        for (int i=0; i<min((int)g.list.size(), 2); i++) {
            answer.push_back(g.list[i].first);
        }
    }
    
    return answer;
}