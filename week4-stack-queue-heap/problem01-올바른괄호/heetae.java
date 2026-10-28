// 문제: 올바른 괄호
/*
접근 방식: 스택으로 (를 만나면 푸쉬, 스택이 비거나 닫혀있는 상태인데 닫힌 괄호를 만나면 false 반환
  정상적일경우 pop, 마지막에 다 내보내지 못해서 스택이 비지 않은 경우에도 false
*/
// 시간복잡도: O(n)

import java.util.*;
class Solution {
    boolean solution(String s) {
        Stack<Character> stack = new Stack<>();
        for(int i=0;i<s.length();i++){
            char current = s.charAt(i);
            if(stack.isEmpty())
                if(current==')')return false;
                else stack.push(current);
            else{
                if(stack.peek()==')' && current==')') return false;
                else if(stack.peek()=='(' && current==')') stack.pop();
                else stack.push(current);
            }
        }

        return stack.isEmpty()? true : false;
    }
}
