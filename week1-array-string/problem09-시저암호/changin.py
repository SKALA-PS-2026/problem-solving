'''
문제 이름: 시저 암호
시간복잡도: O(N)
풀이 방법: for문으로 문자열 s의 각 문자를 순회하며 공백 여부 및 대/소문자 ASCII 코드 범위(ord)를 체크하여 n만큼 밀고 26을 빼주는 방식으로 처리
'''

def solution(s, n):
    answer = ''
    for c in s:
        if c == ' ':
            answer = answer + c
        elif ord(c)<=90:
            a = ord(c) + n
            if a > 90:
                a -= 26
            answer = answer + chr(a)
        elif ord(c)>=97:
            a = ord(c) + n
            if a > 122:
                a -= 26
            answer = answer + chr(a)
    return answer

