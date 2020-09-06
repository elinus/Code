package Sorting;

import java.util.Arrays;

public class SelectionSort {

    public static void selection_sort(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            int minimum = i;
            for (int j = i + 1; j < array.length; j++) {
                if (array[j] < array[minimum])
                    minimum = j;
            }
            int temp = array[minimum];
            array[minimum] = array[i];
            array[i] = temp;
        }
    }

    public static void main(String[] args) {
        int[] array = {14, 20, 24, 11, 16};
        System.out.println("Before sorting = " + Arrays.toString(array));
        selection_sort(array);
        System.out.println("After sorting = " + Arrays.toString(array));
    }
}
