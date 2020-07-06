class Single {
        private Single() {
            System.out.println("Hello");
        }
}
public class singleton {

    public static void main(String a[]) {
        System.out.println("Creating object");
        Single s = new Single();
        System.out.println("done creating object");
    }
}
