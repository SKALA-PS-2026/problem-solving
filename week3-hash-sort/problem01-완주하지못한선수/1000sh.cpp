// 문제: 완주하지 못한 선수
/*
접근 방식: unordered_map 에 넣고 중복 체크까지 하면서 for 돌림
  중복 체크하면서 뺌. 없는놈 체크되자마자 for 종료
*/
// 시간복잡도: O(n) 10^5

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int size_com=completion.size();
    unordered_map<string,int> comname;
    for(int i=0;i<size_com;i++)//선수이름 고유 암호화
    {
        comname[completion[i]]++;
    }
    int size_par=participant.size();
    for(int i=0;i<size_par;i++)//선수이름 고유 암호화
    {
        if(comname.find(participant[i])==comname.end())
            return (participant[i]);
        else 
        {
            comname[participant[i]]--;
            if(comname[participant[i]]<0)return (participant[i]);
        }
    }
   
    
    return answer;
}
