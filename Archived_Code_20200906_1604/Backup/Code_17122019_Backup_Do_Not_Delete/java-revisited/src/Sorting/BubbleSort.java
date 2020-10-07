package Sorting;

import java.util.Arrays;

public class BubbleSort {

    public static void bubble_sort(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            for (int j = 0; j < array.length - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] array = {14, 20, 24, 11, 16};
        System.out.println("Before sorting = " + Arrays.toString(array));
        bubble_sort(array);
        System.out.println("After sorting = " + Arrays.toString(array));
    }
}
