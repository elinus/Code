package Sorting;

import java.util.Arrays;

public class QuickSort {

    public static int partition(int[] array, int start, int end) {
        int i = start + 1;
        int pivot = array[start];
        for (int j = start + 1; j <= end ; j++) {
            if (array[j] < pivot) {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
                i++;
            }
        }
        int temp = array[start];
        array[start] = array[i - 1];
        array[i - 1] = temp;
        return i - 1;
    }

    public static void quick_sort(int[] array, int start, int end) {
        if (start < end) {
            int pivot = partition(array, start, end);
            quick_sort(array, start, pivot - 1);
            quick_sort(array, pivot + 1, end);
        }
    }

    public static void main(String[] args) {
        int[] array = {14, 20, 24, 11, 16};
        System.out.println("Before sorting = " + Arrays.toString(array));
        quick_sort(array, 0, array.length - 1);
        System.out.println("After sorting = " + Arrays.toString(array));
    }
}
