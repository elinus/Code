/**
 * Created on 28-Mar-19.
 *
 * @author Sunil Mourya
 * @description
 * @link
 * @Input:
 * @Output:
 * @Complexity:
 */

package InterviewPreparation2x19;

public class ObjectCreationClone implements Cloneable {

    @Override
    protected Object clone() throws CloneNotSupportedException {
        return super.clone();
    }

    String hello = "Hello Clone!";

    public static void main(String[] args) {
        ObjectCreationClone obj1 = new ObjectCreationClone();
        System.out.println("obj1.hello = " + obj1.hello);
        try {
            ObjectCreationClone obj2 = (ObjectCreationClone) obj1.clone();
            System.out.println("obj2.hello = " + obj2.hello);
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
    }
}
