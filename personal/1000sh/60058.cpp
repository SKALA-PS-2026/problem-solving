// 문제: 괄호 변환
// 링크: https://school.programmers.co.kr/learn/courses/30/lessons/60058
/*
접근 방식: 괄호를 (=1, )=-1 해서 양수=>0 으로 되는것은 무시 음수=>0일경우 뒤집음. 양수를 가면 무조건 그뒤는 정상이므로 그대로 두고 음수면 무조건 바꾸면서 실행. 인줄 알았으나 아니여서 폐기 문제 겁나 복잡하네. 재귀로 처리
  양수 음수 그대로 양수면 그대로 출력. 음수면 따로 처리.
*/
// 시간복잡도: //On n<=1000


#include <string>
#include <vector>
#include <iostream>

using namespace std;

string rev(string rp)
{
    for(int i=0;i<rp.size();i++)
    {
        rp[i]='('==rp[i]?')':'(';
    }
    cout<<"uㄷ:"<<rp<<endl;
    return rp;
}

// (=1 )=-1
string Change(string p, int size)
{
    if(size==0)return "";
    string u="";
    string v="";
    int checknum=0;
    int yetchecknum=0;
    string allPart="";
    for(int i=0;i<size;i++)
    {
        yetchecknum=checknum;
        if(p[i]=='(') {checknum++;}
        else {checknum--;}
        if(checknum==0)
        {
            u=p.substr(0,i+1);
            v=p.substr(i+1,size);
            if(yetchecknum+checknum<0)
            {
                    allPart.push_back('(');
                    allPart+=Change(v,size-i);
                    allPart.push_back(')');
                
                allPart+=rev(u.substr(1,u.size()-2));
            }
            else {
                allPart+=(u);
                allPart+=Change(v,size-i);
            }
    cout<<"u:"<<u<<"  v:"<<v<<endl;
            break;
        }
    }
    return allPart;
    
}
string solution(string p) {
    string answer = Change(p,p.size());
    
    return answer;
}
