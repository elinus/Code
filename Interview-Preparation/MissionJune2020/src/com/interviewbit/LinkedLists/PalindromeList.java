package com.interviewbit.LinkedLists;

public class PalindromeList {

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

    public static ListNode reverseList(ListNode head) {
        ListNode curr = head, prev = null, next = null;
        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    public static int isPalindrome(ListNode head) {
        if (head == null || head.next == null) return 1;
        int length = getListLength(head);
        ListNode first = head, mid = null, last = head;
        if (length % 2 != 0) {
            int counter = length / 2;
            while (--counter > 0) {
                last = last.next;
            }
            mid = last.next;
            last.next = null;
            last = mid.next;
            last = reverseList(last);
        } else {
            int counter = length / 2;
            while (--counter > 0) {
                last = last.next;
            }
            ListNode temp = last;
            last = last.next;
            temp.next = null;
            last = reverseList(last);
        }
        while (first != null && last != null) {
            if (first.val != last.val) return 0;
            first = first.next;
            last = last.next;
        }
        return 1;
    }

    public static void main(String[] args) {

        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(1);
        head.next.next.next = new ListNode(1);
        //head.next.next.next.next = new ListNode(1);
        printList(head);
        System.out.println(isPalindrome(head));
    }
}
