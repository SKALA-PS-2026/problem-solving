#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int num_p=0;
    int num_y=0;
    for(int i=0; i < s.length(); i++){
        if(s[i]=='p'||s[i]=='P'){
            num_p++;
        }
        else if(s[i]=='y'||s[i]=='Y'){
            num_y++;
        }
    }
    
    if(num_p!=num_y){
        answer=false;
    }

    return answer;
}