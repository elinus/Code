package com.interviewbit.LinkedLists;

public class MergeTwoSortedLists {

    static class ListNode {
        int val;
        ListNode next;
        ListNode(int value) {
            val = value;
            next = null;
        }
    }

    public static int getListLength(final ListNode head) {
        int length = 0;
        ListNode curr = head;
        while (curr != null) {
            length++;
            curr = curr.next;
        }
        return length;
    }

    public static void printList(final ListNode head) {
        ListNode curr = head;
        while (curr != null) {
            System.out.print(curr.val + " ");
            curr = curr.next;
        }
        System.out.println();
    }

    public static ListNode mergeTwoLists(ListNode head_a, ListNode head_b) {
        if (head_a == null) return head_b;
        if (head_b == null) return head_a;
        ListNode dummy = new ListNode(-1);
        ListNode curr_a = head_a, curr_b = head_b, tail = dummy;
        while (curr_a != null && curr_b != null) {
            if (curr_a.val <= curr_b.val) {
                tail.next = curr_a;
                curr_a = curr_a.next;
            } else {
                tail.next = curr_b;
                curr_b = curr_b.next;
            }
            tail = tail.next;
        }
        while (curr_a != null) {
            tail.next = curr_a;
            tail = tail.next;
            curr_a = curr_a.next;
        }
        while (curr_b != null) {
            tail.next = curr_b;
            tail = tail.next;
            curr_b = curr_b.next;
        }
        return dummy.next;
    }

    public static void main(String[] args) {
        ListNode head1 = new ListNode(5);
        head1.next = new ListNode(8);
        head1.next.next = new ListNode(20);
        printList(head1);

        ListNode head2 = new ListNode(4);
        head2.next = new ListNode(11);
        head2.next.next = new ListNode(15);
        printList(head2);

        printList(mergeTwoLists(head1, head2));
    }
}
