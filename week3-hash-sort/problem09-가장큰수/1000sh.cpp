// 문제: 가장 큰 수
/*
접근 방식: 각 숫자를 첫자리를 복사해서 3자리를 만든다음 숫자 비교한다.
  같을 경우 중간이 첫자리보다 큰수가 있는지 작은수가 있는지에 따라서 bool체크해서 길이가 짧은걸 내보낼지 긴것을 내보낼지 정한다.
  1000은 100하고 동일 취급되므로 예외처리하고 0은 제일 작으므로 000으로 한다.
*/
// 시간복잡도: 

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string Num2String(int num)//3자리수로 첫차리 채워서 만들기
{
    if(num==1000)return "001";
    if(num==0) return "000";
    string s = to_string(num);
    string result;
    for (int i = 0; i < 3; i++) {
        result += s[i % s.size()];
    }   
    return result;
}


bool compare(int a,int b)
{
    string as=Num2String(a);
    string bs=Num2String(b);
    bool big=false;
    for (int i = 0; i < 3; i++) {
        if(as[i]>bs[i])return true;
        else if(bs[i]>as[i]) return false;
        if(as[1]>as[i])big=true;
    }   
    if(!big)
    return a>b;//같으면 짧은거
    else return b>a;
}
string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(),numbers.end(),compare);
    
    int size=numbers.size();
    for(int i=0;i<size;i++)
    {
        answer+=to_string(numbers[i]);
    }
    if (answer[0] == '0')
    return "0";

    return answer;
}
