package LeetCode.week1.sec;

import static LeetCode.week1.sec.LinkedListCycle_141.ListNode;

public class MergeTwoSortedLists_21 {

    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode listNode = new ListNode(-1);
        ListNode cur = listNode;

        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                cur.next = list1;
                list1 = list1.next;
            } else {
                cur.next = list2;
                list2 = list2.next;
            }
            cur = cur.next;
        }

        if (list1 == null) {
            cur.next = list2;
        } else {
            cur.next = list1;
        }

        return listNode.next;
    }

    public static void main(String[] args) {
        MergeTwoSortedLists_21 m = new MergeTwoSortedLists_21();
        final ListNode listNode = new ListNode(1);
        listNode.setNext(new ListNode(2));
        listNode.next.setNext(new ListNode(4));

        final ListNode listNode1 = new ListNode(1);
        listNode1.setNext(new ListNode(3));
        listNode1.next.setNext(new ListNode(4));

        System.out.println(m.mergeTwoLists(listNode, listNode1));
    }
}
