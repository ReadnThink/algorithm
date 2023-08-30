package LeetCode.week2.first;

import java.util.ArrayList;

public class MinStack {
    int top;
    int min;
    ArrayList<Integer[]> stack;

    public MinStack() {
        top = -1;
        min = Integer.MAX_VALUE;
        stack = new ArrayList<>();
    }

    public void push(int val) {
        min = Math.min(min, val);
        stack.add(new Integer[]{val, min});
        top++;
    }

    public void pop() {
        stack.remove(top--);
        if (stack.size() != 0)
            min = stack.get(top)[1];
        if (stack.size() == 0)
            min = Integer.MAX_VALUE;
    }

    public int top() {
        return stack.get(top)[0];
    }

    public int getMin() {
        return min;
    }

    public static void main(String[] args) {
        MinStack s = new MinStack();
        s.push(2147483646);
        s.push(2147483646);
        s.push(2147483647);
        System.out.println(s.top());
        s.pop();
        System.out.println(s.getMin());
        s.pop();
        System.out.println(s.getMin());
        s.pop();
        s.push(2147483647);
        System.out.println(s.top());
        System.out.println(s.getMin());
        s.push(-2147483648);
        System.out.println(s.top());
        System.out.println(s.getMin());
        s.pop();
        System.out.println(s.getMin());
    }
}
