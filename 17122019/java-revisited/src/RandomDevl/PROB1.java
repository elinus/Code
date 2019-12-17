package RandomDevl;

import java.util.Arrays;

public class PROB1 {

    static int[] alpha_hash = new int[26];
    static int string_length = 0;
    static char[] string = new char[20];
    static int[][] grid = new int[26][20];

    static void init(int N, char[] init_string) {
        string_length = N;
        for (int i = 0; i < 26; i++) {
            alpha_hash[i] = 0;
            for (int j = 0; j < 20; j++) {
                grid[i][j] = -1;
            }
        }
        for (int i = 0; i < N; i++) {
            string[i] = init_string[i];
            grid[init_string[i] - 'a'][alpha_hash[init_string[i] - 'a']] = i;
            alpha_hash[init_string[i] - 'a']++;
        }
        System.out.println("alpha = " + Arrays.toString(alpha_hash));
        System.out.println("grid:");
        for (int i = 0; i < 2; i++) {
            System.out.println(Arrays.toString(grid[i]));
        }
    }

    static boolean safe(int i, int j, int k) {
        if (i >= 0 && i < string_length && j >= 0 && j < string_length && k >= 0 && k < string_length)
            return true;
        return false;
    }

    static int change(char[] string_A, char[] string_B) {
        int res = 0;
        int ch_index = string_A[0] - 'a';
        int string_index= 0;
        for (int i = 0; grid[ch_index][i] != -1 /*&& grid[ch_index][i] != -2*/; i++) {
            System.out.println("-----" + ch_index + ", " + i
                    + " [" + grid[ch_index][i] + "] -----");
            int index = grid[ch_index][i];
            if (!safe(index, index + 1, index + 2)) return res;

            if (index > string_index &&string[index] == string_A[0]
                    && string[index + 1] == string_A[1]
                    && string[index + 2] == string_A[2]) {

                string[index] = string_B[0];
                grid[string_B[0] - 'a'][alpha_hash[string_B[0] - 'a']++] = index;

                string[index + 1] = string_B[1];
                grid[string_B[1] - 'a'][alpha_hash[string_B[1] - 'a']++] = index + 1;

                string[index + 2] = string_B[2];
                grid[string_B[2] - 'a'][alpha_hash[string_B[2] - 'a']++] = index + 2;

                System.out.println(Arrays.toString(alpha_hash));
                System.out.println("grid:");
                for (int k = 0; k < 2; k++) {
                    System.out.println(Arrays.toString(grid[k]));
                }
                res++;
                string_index = index + 2;
            }
        }
        return res;
    }

    static void result(char[] res) {
        int i = 0;
        for (i = 0; i < string_length; i++) {
            res[i] = string[i];
        }
        res[i] = '\0';
        System.out.println("result = " + String.copyValueOf(res, 0, i));
    }

    public static void main(String[] args) {
        String testString = "abaabbbbbb";
        char[] stringToCharArray = testString.toCharArray();
        System.out.println(stringToCharArray);

        System.out.println("########## INIT ##########");
        init(stringToCharArray.length, stringToCharArray);

        System.out.println("########## CHANGE ##########");
        System.out.println(change("baa".toCharArray(), "aba".toCharArray()));
        System.out.println(change("aaa".toCharArray(), "bba".toCharArray()));
        System.out.println(change("bbb".toCharArray(), "abb".toCharArray()));

        System.out.println("########## RESULT ##########");
        char[] res = new char[20];
        result(res);
    }
}
