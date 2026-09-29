// 문제: 괄호 회전하기
// 접근 방식: 
// 시간복잡도: O(N)

// Date: 29SEP2026
// Author: Jung Minkyu

import java.util.*;

class Solution {
    private Stack<Character> st1;
    private Stack<Character> st2;
    private Stack<Character> st3;
    
    boolean isOne(char ch) {
        if (ch == '(' || ch == ')') return true;
        return false;
    }

    boolean isTwo(char ch) {
        if (ch == '[' || ch == ']') return true;
        return false;
    }

    boolean isThree(char ch) {
        if (ch == '{' || ch == '}') return true;
        return false;
    }

    public int solution(String s) {
        
        int answer = 0;
        
        for (int i = 0; i < s.length(); i++) {
            st1 = new Stack<>();
            st2 = new Stack<>();
            st3 = new Stack<>();
            
            boolean firstTest = true;
            for (int j = i; j < s.length(); j++) {
                if (isOne(s.charAt(j))) {
                    // Secondary Validation
                    if (s.charAt(j) == ')') {
                        if (st1.size() == 0) {
                            firstTest = false;
                            break; // fail!!
                        } else {
                            st1.pop(); // pop!!
                        }
                    } else {
                        st1.push('('); // push!!
                    }
                }

                if (isTwo(s.charAt(j))) {
                    // Secondary Validation
                    if (s.charAt(j) == '}') {
                        if (st2.size() == 0) {
                            firstTest = false;
                            break; // fail!!
                        } else {
                            st2.pop(); // pop!!
                        }
                    } else {
                        st2.push('{'); // push!!
                    }

                }

                if (isThree(s.charAt(j))) {
                    // Secondary Validation
                    if (s.charAt(j) == ']') {
                        if (st3.size() == 0) {
                            firstTest = false;
                            break; // fail!!
                        } else {
                            st3.pop(); // pop!!
                        }
                    } else {
                        st3.push('['); // push!!
                    }

                }
                
            }
            
            if (firstTest) {
                // SecondTest
                boolean secondTest = true;
                for (int j = 0; j < i; j++) {
                    if (isOne(s.charAt(i))) {
                        // Secondary Validation
                        if (s.charAt(j) == ')') {
                            if (st1.size() == 0) {
                                secondTest = false;
                                break; // fail!!
                            } else {
                                st1.pop(); // pop!!
                            }
                        } else {
                            st1.push('('); // push!!
                        }
                    }

                    if (isTwo(s.charAt(j))) {
                        // Secondary Validation
                        if (s.charAt(j) == '}') {
                            if (st2.size() == 0) {
                                secondTest = false;
                                break; // fail!!
                            } else {
                                st2.pop(); // pop!!
                            }
                        } else {
                            st2.push('{'); // push!!
                        }

                    }

                    if (isThree(s.charAt(j))) {
                        // Secondary Validation
                        if (s.charAt(j) == ']') {
                            if (st3.size() == 0) {
                                secondTest = false;
                                break; // fail!!
                            } else {
                                st3.pop(); // pop!!
                            }
                        } else {
                            st3.push('['); // push!!
                        }
                    }

                }
                if (secondTest) {
                    answer++;
                }
            }
            
            
            
        }
        
        
        return answer;
    }
}

/*
import java.util.Stack;

class Solution {
    private Stack<Character> stack;
    
    public int solution(String s) {
        this.stack = new Stack<>();
        int answer = 0;
        
        char[] toChar = s.toCharArray();
        
        for (int i = 0; i < toChar.length; i++) {
            
            boolean res = true;
            
            // 괄호 알고리즘
            for (int j = i, count = 0; count < toChar.length; j++, count++) {
                if (j >= toChar.length) j %= toChar.length;
                
                char cur = toChar[j];
                
                // 열린 기호 만났을 때,
                if (cur == '(' || cur == '{' || cur == '[') {
                    stack.push(cur);                
                } else {
                    // 닫힌 기호 만났을 때
                    if (stack.empty()) {
                        res = false;
                        break;
                    }

                    char top = stack.pop();
                    if (top == '(' && cur != ')') {
                        res = false;
                        break;
                    }
                    if (top == '{' && cur != '}') {
                        res = false;
                        break;
                    }
                    if (top == '[' && cur != ']') {
                        res = false;
                        break;
                    }
                }  
            }
            if (res && stack.empty()) answer++;
            stack.clear();
        }        
        return answer;
    }
}
*/