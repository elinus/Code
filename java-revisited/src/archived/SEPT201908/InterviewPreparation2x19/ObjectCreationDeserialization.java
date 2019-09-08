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

import java.io.*;

public class ObjectCreationDeserialization implements Serializable {

    private String hello;

    public ObjectCreationDeserialization(String hello) {
        this.hello = hello;
    }

    public static void main(String[] args) {
        // Serializing an Object
        ObjectCreationDeserialization obj1 =
                new ObjectCreationDeserialization("Hello Deserialization!");
        try {
            FileOutputStream fos = new FileOutputStream("file.txt");
            ObjectOutputStream oss = new ObjectOutputStream(fos);
            oss.writeObject(obj1);
            oss.close();
            fos.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Deserialization of Object
        try {
            ObjectCreationDeserialization obj2;
            FileInputStream fis = new FileInputStream("file.txt");
            ObjectInputStream ois = new ObjectInputStream(fis);
            obj2 = (ObjectCreationDeserialization) ois.readObject();
            System.out.println("obj2.hello = " + obj2.hello);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
