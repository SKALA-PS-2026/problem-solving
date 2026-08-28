'''
문제 이름:  같은 숫자는 싫어
시간복잡도: O(N)
풀이 방법: prev 변수로 직전 원소를 기록하며 for문으로 arr의 모든 원소를 순회하여 연속 중복값 제거
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

