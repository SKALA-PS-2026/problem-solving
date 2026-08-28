'''
문제 이름: 문자열 다루기 기본
시간복잡도: O(N)
풀이 방법: 문자열 s의 길이가 4 또는 6인지 먼저 검사한 뒤, for문으로 각 문자의 ASCII 코드 값(ord)을 확인해 모두 숫자 범위('0'~'9', 48~57)에 해당하는지 검사
'''

def solution(arr):
    answer = []
    prev = -1
    for c in arr:
        if prev == -1 :
            prev = c 
            answer.append(c)
        elif prev == c :
            continue
        else:
            prev = c
            answer.append(c)
    return answer

