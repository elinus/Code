package Sorting;

import java.util.Arrays;

public class MergeSort {

    public static void merge(int[] array, int start, int mid, int end) {
        int p = start, q = mid + 1;
        int k = 0;
        int[] arr = new int[end - start + 1];
        for (int i = start; i <= end; i++) {
            if (p > mid)
                arr[k++] = array[q++];
            else if (q > end)
                arr[k++] = array[p++];
            else if (array[p] < array[q])
                arr[k++] = array[p++];
            else
                arr[k++] = array[q++];
        }

        for (int i = 0; i < k; i++) {
            array[start++] = arr[i];
        }
    }

    public static void merge_sort(int[] array, int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            merge_sort(array, start, mid);
            merge_sort(array, mid + 1, end);
            merge(array, start, mid, end);
        }
    }

    public static void main(String[] args) {
        int[] array = {14, 20, 24, 11, 16};
        System.out.println("Before sorting = " + Arrays.toString(array));
        merge_sort(array, 0, array.length - 1);
        System.out.println("After sorting = " + Arrays.toString(array));
    }
}
