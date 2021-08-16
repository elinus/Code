package com.interviewbit.LinkedLists;

public class RemoveNthNodeFromListEnd {

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

    public static ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null) return null;
        int length = getListLength(head);
        if (n >= length) {
            head = head.next;
            return head;
        }
        ListNode curr = head, prev = null;
        int diff = length - n + 1;
        while (--diff > 0) {
            prev = curr;
            curr = curr.next;
        }
        if (curr.next != null) prev.next = curr.next;
        else prev.next = null;
        return head;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        printList(head);
        printList(removeNthFromEnd(head, 5));
    }
}
