'''
문제 이름: 자연수 뒤집어 배열로 만들기
시간복잡도: O(log N)
풀이 방법: 리스트 컴프리헨션으로 뒤집고 for문으로 꺼내면서 배열 생성
'''

def solution(n):
    answer = []
    for i in str(n)[::-1]:
        answer.append(int(i))
    return answer