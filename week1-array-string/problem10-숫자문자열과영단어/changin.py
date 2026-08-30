'''
문제 이름: 숫자 문자열과 영단어
시간복잡도: O(N)
풀이 방법: 0부터 9까지의 영단어를 replace() 메서드로 각각 대응하는 숫자 문자열로 치환한 뒤 int()로 정수 변환
'''

def solution(s):
    s = s.replace("zero","0")
    s= s.replace("one","1")
    s = s.replace("two","2")
    s=s.replace("three","3")
    s=s.replace("four","4")
    s=s.replace("five","5")
    s=s.replace("six","6")
    s=s.replace("seven","7")
    s=s.replace("eight","8")
    s=s.replace("nine","9")
    return int(s)
