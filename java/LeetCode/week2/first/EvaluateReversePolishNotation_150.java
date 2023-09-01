package LeetCode.week2.first;

import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Stack;

public class EvaluateReversePolishNotation_150 {
    HashSet<String> OPERATERS = new HashSet<>(Arrays.asList("+", "-", "*", "/"));
    public int evalRPN(String[] tokens) {
        Stack<Integer> stk = new Stack<>();

        for (int i = 0; i < tokens.length; i++) {
            if (OPERATERS.contains(tokens[i])) {
                Integer first = stk.pop();
                Integer sec = stk.pop();

                stk.push(culcurate(first, sec, tokens[i].charAt(0)));
            } else {
                stk.push(Integer.valueOf(tokens[i]));
            }
            System.out.println(stk.peek());
        }
        Integer result = stk.pop();
        System.out.println(result);
        return result;
    }

    private Integer culcurate(final Integer first, final Integer sec, char token) {
        Integer sum = 0;
        if (token == '+') {
            sum = first + sec;
        } else if (token == '-') {
            sum = sec - first;
        } else if (token == '*') {
            sum = first * sec;
        }else if (token == '/') {
            sum = sec / first;
        }
        return sum;
    }

    public static void main(String[] args) {
        EvaluateReversePolishNotation_150 e = new EvaluateReversePolishNotation_150();
        System.out.println(e.evalRPN(new String[]{"10","6","9","3","+","-11","*","/","*","17","+","5","+"}));
    }

}
