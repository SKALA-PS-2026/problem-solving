// 문제: 실패율
// 접근 방식: 페어로 확률을 구한뒤 정렬
// 시간복잡도: O(n) n<=2000

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(const pair<float,int>& a, const pair<float,int>& b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first>b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int size=stages.size();
    vector<int> sum(N+2,0);
    vector<pair<float,int>> per(N,{0,0});
    for(int i=0;i<size; i++)
    {
        sum[stages[i]]++;
    }
    int count=sum[N+1];
    for(int i=N;i>0;i--)
    {
        count+=sum[i];
        if(count==0) per[i-1]={0,i};
        else per[i-1]={(sum[i])/(float)count,i};
    cout<<per[i-1].first<<"  "<<per[i-1].second<<endl;
    }
    sort(per.begin(),per.end(),compare);
    for(int i=0;i<N;i++)
    {
        answer.push_back(per[i].second);
    }
    return answer;
}
