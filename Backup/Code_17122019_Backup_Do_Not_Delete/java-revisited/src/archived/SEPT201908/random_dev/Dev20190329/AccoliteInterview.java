/**
 * Created on 29-Mar-19.
 *
 * @author Sunil Mourya
 * @description
 * @link
 * @Input:
 * @Output:
 * @Complexity:
 */

package archived.SEPT201908.random_dev.Dev20190329;

public class AccoliteInterview {
    public static void main(String[] args) {
        assert getFirstNonRepeating("apple").equals("a") : true;
        assert getFirstNonRepeating("abdsv").equals("a") : true;
        assert getFirstNonRepeating("bannasb").equals("s") : true;
        assert getFirstNonRepeating("").equals(null) : true;
        assert getFirstNonRepeating("aabboozoo").equals("z") : true;
        System.out.println("passed");
    }

    public static String getFirstNonRepeating(String input) {
        int[] indexArr = new int[26];
        int[] countArr = new int[26];
        for (int i = 0; i < 26; i++) {
            indexArr[i] = -1;
            countArr[i] = 0;
        }
        for (int i = 0; i < input.length(); i++) {
            int index = input.charAt(i) - 'a';
            if (indexArr[index] == -1) {
                indexArr[index] = i;
            }
            countArr[index]++;
        }
        int min_index = -1;
        int index = -1;
        for (int i = 0; i < 26; i++) {
            if (countArr[i] == 1 && indexArr[i] != -1) {
                index = indexArr[i];
                if (min_index == -1 || index < min_index) {
                    min_index = index;
                }
            }
        }
        if (min_index != -1)
            return Character.toString(input.charAt(min_index));
        return null;
    }
}
