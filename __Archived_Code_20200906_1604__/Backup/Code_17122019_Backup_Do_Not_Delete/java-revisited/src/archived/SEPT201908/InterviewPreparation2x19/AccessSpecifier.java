/**
 * Created on 27-Mar-19.
 *
 * @author Sunil Mourya
 * @description
 * @link
 * @Input:
 * @Output:
 * @Complexity:
 */

package archived.SEPT201908.InterviewPreparation2x19;

public class AccessSpecifier {
    private int one;
    public int two;
    protected int three;
    int four;
    public static final int five = 5;

    public static void main(String[] args) {
        AccessSpecifier ref = new AccessSpecifier();
        ref.one = 1;
        ref.two = 2;
        ref.three = 3;
        ref.four = 4;
        System.out.println(AccessSpecifier.five);
    }
}
