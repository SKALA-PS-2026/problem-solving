'''
문제 이름: 문자열 내 p와 y의 개수
시간복잡도: O(N)
풀이 방법: s.count() 메서드를 활용해 대소문자 'p/P'와 'y/Y'의 개수를 각각 센 뒤 합산하여 비교
'''

def solution(s):
    if s.count('p')+s.count('P') == s.count('y')+s.count('Y'):
        return True
    return False

