package com.interviewbit.LinkedLists;

public class IntersectionOfLinkedList {

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

    public static ListNode getIntersectionNode(ListNode a, ListNode b) {
        if (a == null || b == null) return null;

        int len_a = getListLength(a);
        int len_b = getListLength(b);

        if (len_a >= len_b) {
            int diff = len_a - len_b;
            ListNode curr_a = a, curr_b = b;
            while (diff-- > 0) {
                curr_a = curr_a.next;
            }
            while (curr_a != null && curr_b != null) {
                if (curr_a == curr_b) return curr_a;
                curr_a = curr_a.next;
                curr_b = curr_b.next;
            }
        } else if (len_b > len_a) {
            int diff = len_b - len_a;
            ListNode curr_a = a, curr_b = b;
            while (diff-- > 0) {
                curr_b = curr_b.next;
            }
            while (curr_a != null && curr_b != null) {
                if (curr_a == curr_b) return curr_b;
                curr_a = curr_a.next;
                curr_b = curr_b.next;
            }
        }
        return null;
    }

    public static void main(String[] args) {
        ListNode head1 = new ListNode(1);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(3);
        head1.next.next.next = new ListNode(4);
        head1.next.next.next.next = new ListNode(5);
        printList(head1);
        ListNode head2 = new ListNode(6);
        head2.next = new ListNode(7);
        head2.next.next = head1.next.next;
        printList(head2);
        printList(getIntersectionNode(head1, head2));
    }
}
