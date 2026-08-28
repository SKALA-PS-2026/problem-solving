'''
문제 이름: 배열 두배 만들기
시간복잡도: O(n)
'''

def solution(numbers):
    answer = []
    for i in numbers:
        answer.append(i*2)
    return answer