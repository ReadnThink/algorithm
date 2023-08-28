package LeetCode.week1.sec;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;

public class LinkedListCycle_141 {
    static class ListNode {
        int val;
        ListNode next;


        ListNode(int x) {
            val = x;
            next = null;
        }

        public ListNode(final int val, final ListNode next) {
            this.val = val;
            this.next = next;
        }

        public void setNext(final ListNode next) {
            this.next = next;
        }
    }

    public boolean hasCycle(ListNode head){
        if(head == null || head.next == null) return false;
        if(head.next == head) return true;
        ListNode nextNode = head.next;
        head.next = head;
        return hasCycle(nextNode);
    }

    public static void main(String[] args) {
        LinkedListCycle_141 l = new LinkedListCycle_141();
        final ListNode listNode = new ListNode(3);
        final ListNode listNode1 = new ListNode(2);
        listNode.setNext(listNode1);
        listNode.next.setNext(new ListNode(0));
        listNode.next.next.setNext(new ListNode(-1));
        listNode.next.next.next.setNext(listNode1);

        System.out.println(l.hasCycle(listNode));
    }
}
