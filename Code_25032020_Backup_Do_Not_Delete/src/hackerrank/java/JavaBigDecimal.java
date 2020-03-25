package hackerrank.java;

import java.math.BigDecimal;
import java.util.*;

public class JavaBigDecimal {
    public static void main(String []args){
        Scanner sc= new Scanner(System.in);
        int n=sc.nextInt();
        String[] s = new String[n+2];
        for(int i=0;i<n;i++){
            s[i]=sc.next();
        }
        sc.close();

        String[] bgArr = new String[n];
        for (int i = 0; i < bgArr.length; i++) {
            bgArr[i] = s[i];
        }
        Arrays.sort(bgArr, Collections.reverseOrder(new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                BigDecimal bd1 = new BigDecimal(s1);
                BigDecimal bd2 = new BigDecimal(s2);
                return bd1.compareTo(bd2);
            }
        }));
        for (int i = 0; i < bgArr.length; i++) {
            s[i] = bgArr[i];
        }
        for(int i=0;i<n;i++)
        {
            System.out.println(s[i]);
        }
    }
}
