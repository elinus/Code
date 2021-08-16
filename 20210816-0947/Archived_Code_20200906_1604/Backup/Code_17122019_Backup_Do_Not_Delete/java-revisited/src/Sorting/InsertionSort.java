package Sorting;

import java.util.Arrays;

public class InsertionSort {

    public static void insertion_sort(int[] array) {
        for (int i = 0; i < array.length; i++) {
            int temp = array[i];
            int j = i;
            while (j > 0 && temp < array[j - 1]) {
                array[j] = array[j - 1];
                j--;
            }
            array[j] = temp;
        }
    }

    public static void main(String[] args) {
        int[] array = {14, 20, 24, 11, 16};
        System.out.println("Before sorting = " + Arrays.toString(array));
        insertion_sort(array);
        System.out.println("After sorting = " + Arrays.toString(array));
    }
}
