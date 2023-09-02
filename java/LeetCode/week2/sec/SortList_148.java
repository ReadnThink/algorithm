package LeetCode.week2.sec;

import java.util.ArrayList;
import java.util.Collections;
import java.util.StringJoiner;

public class SortList_148 {

    public static class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }

        @Override
        public String toString() {
            if (next == null) return String.valueOf(val);

            return new StringJoiner(" -> ")
                    .add(String.valueOf(val))
                    .add(next.toString())
                    .toString();
        }
    }
    public ListNode sortList(ListNode head) {
        System.out.println("sort list : " + head.toString());
        if(head==null || head.next==null){
            return head;
        }
        ListNode slow=head;
        ListNode fast=head;
        ListNode prev=null;

        while(fast!=null && fast.next!=null){
            prev=slow;
            slow=slow.next;
            fast=fast.next.next;
        }
        prev.next=null;
        ListNode l1=sortList(head);
        ListNode l2=sortList(slow);
//        System.out.println("오른쪽은 : " + l1.val);
        return mergeSort(l1,l2);
    }
    public static ListNode mergeSort(ListNode l1,ListNode l2){
        System.out.println("병합 시작");
        System.out.println("왼쪽 : "+l1.toString());
        System.out.println("오른쪽 : "+l2.toString());
        ListNode fh=null;
        ListNode ft=null;

        while(l1!=null && l2!=null){
            if(fh==null && ft==null){
                if(l1.val>l2.val){
                    fh=l2;
                    ft=l2;
                    l2=l2.next;
                }
                else{
                    fh=l1;
                    ft=l1;
                    l1=l1.next;
                }
            }
            if(l1!=null && l2!=null){
                if(l1.val<l2.val){
                    ft.next=l1;
                    ft=ft.next;
                    l1=l1.next;
                }
                else{
                    ft.next=l2;
                    ft=ft.next;
                    l2=l2.next;
                }
            }
        }
        if(l1!=null){
            ft.next=l1;
        }
        if(l2!=null){
            ft.next=l2;
        }
        System.out.println("병합 완료 : " + fh.toString());
        return fh;
    }

    public static void main(String[] args) {
        SortList_148 s = new SortList_148();

        ListNode testList = makeListNode(4,2,1,3);
//        ListNode testList = makeListNode(-1,5,3,4,0);
//        ListNode testList = makeListNode();
        s.sortList(testList);
    }

    private static ListNode makeListNode(int... values) {
        ListNode dummy = new ListNode();
        ListNode tail = dummy;
        for (var value : values) {
            tail.next = new ListNode(value);
            tail = tail.next;
        }
        System.out.println("Test List가 생성되었습니다.");
        System.out.println(dummy.toString());
        return dummy.next;
    }
}
