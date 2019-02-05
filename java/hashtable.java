import java.util.*;

public class hashtable {
    public static void main(String a[]) {
        Hashtable <Integer, String> test = new Hashtable<Integer, String>();
        test.put(1, "one");
        test.put(2, "two");

        String str = test.get(1);
        if (str != null) {
            System.out.println(str);
        }
    }
}
