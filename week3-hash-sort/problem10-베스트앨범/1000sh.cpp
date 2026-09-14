// 문제: 베스트앨범
// 접근 방식: 집어 넣을때 종류별로 합산과 최대값과 두번재 최대값을 같이 집어넣고 정렬해서 합침
// 시간복잡도: 

#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    
    map<string,vector<int>> all; // 장르 {총합,최대큰수,1등인덱스,2등인덱스,2번째로 큰수}
    
    int size=genres.size();
    for(int i=size-1;i>=0;i--)
    {
        if(all.find(genres[i])==all.end())
        {
            all[genres[i]]={0,0,-1,-1,0};
        }
        int nowNum=plays[i];
        int sumNum=all[genres[i]][0]+nowNum;
        bool isbig =false;
        if(nowNum>=all[genres[i]][1])isbig=true;
        int bigNum2=isbig?all[genres[i]][1]:all[genres[i]][4];
        int bigNum=isbig?nowNum:all[genres[i]][1];
        int secondIndex=isbig?all[genres[i]][2]:all[genres[i]][3];
        int firstIndex=isbig?i:all[genres[i]][2];
        if(!isbig)
        {
            bool isbig2=false;
            if(nowNum>=all[genres[i]][4])isbig2=true;
            secondIndex=isbig2?i:secondIndex;
            bigNum2=isbig2?nowNum:bigNum2;
            
        }
        
        
        all[genres[i]]={sumNum,bigNum,firstIndex,secondIndex,bigNum2};
    }
    vector<pair<string, vector<int>>> sortedAll(
        all.begin(), all.end()
    );
    sort(sortedAll.begin(), sortedAll.end(),
    [](const auto& a, const auto& b) {
        return a.second[0] > b.second[0];
    });
    for(int i=0;i<sortedAll.size();i++)
    {
        cout<<sortedAll[i].first<<"  "<<sortedAll[i].second[0]<<endl;
        cout<<sortedAll[i].second[2]<<"  "<<sortedAll[i].second[3]<<endl;
        answer.push_back(sortedAll[i].second[2]);
        if(sortedAll[i].second[3]>=0) answer.push_back(sortedAll[i].second[3]);
    }
    return answer;
}
