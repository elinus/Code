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

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

public class ObjectCreationReflection {
    private String name;

    public ObjectCreationReflection() {
    }

    public void setName(String name) {
        this.name = name;
    }

    public static void main(String[] args) {
        try {
            Constructor<ObjectCreationReflection> constructor =
                    ObjectCreationReflection.class.getDeclaredConstructor();
            ObjectCreationReflection reflection = constructor.newInstance();
            reflection.setName("Hello Reflection!!");
            System.out.println("reflection.name = " + reflection.name);
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InstantiationException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        }
    }
}
