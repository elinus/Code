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

package archived.SEPT201908.InterviewPreparation2x19;

public class ObjectCreationNewInstance {

    String hello = "Hello Reflection!";

    public static void main(String[] args) {

        try {
            Class cls = Class.forName("InterviewPreparation2x19.ObjectCreationNewInstance");
            ObjectCreationNewInstance obj = (ObjectCreationNewInstance) cls.newInstance();
            System.out.println("obj.hello = " + obj.hello);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InstantiationException e) {
            e.printStackTrace();
        }
    }
}
