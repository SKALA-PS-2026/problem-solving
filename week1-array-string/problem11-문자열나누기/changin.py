'''
문제 이름: 문자열 나누기
시간복잡도: O(N)
풀이 방법: deque를 활용해 문자열 s의 첫 글자 x와 다른 글자의 출현 횟수(xcnt, bcnt)를 세어 두 카운트가 같아질 때마다 분리하고 개수(answer)를 증가
'''

from collections import deque

def solution(s):
    answer = 0
    #문자열 첫글자 x 
    #오른쪽으로 읽어나가면서 x와 x가아닌글자들 횟수 세기
    # 두횟수가 같아지는순간 멈추고 지금까지읽은문자열 분리
    
    # 남은부분에서 과정반복
    x = ''
    xcnt = 0
    bcnt = 0
    s = deque(s)
    while s:
        if x =='':
            x= s.popleft()
            xcnt +=1
        elif  x == s.popleft():
            xcnt +=1 
        else:
            bcnt +=1
        
        if xcnt == bcnt:
            answer +=1
            xcnt =0
            bcnt = 0
            x = ''
    
    if xcnt != bcnt :
        answer +=1
        
    return answer
