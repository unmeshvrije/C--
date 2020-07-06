public class alldigits {
    public static int shuffle(int n) {
        System.out.println(n);
        if (n > 0 && n < 100) {
            return n;
        }

        int num = n;
        StringBuffer sb = new StringBuffer();
        while (num > 0) {
            int r = num % 10;
            sb.append(Integer.toString(r));
            num = num /10;
        }
        sb = sb.reverse();
        StringBuffer out = new StringBuffer();
        // 5
        for (int i = 0, j = sb.length()-1; i <= (sb.length()-1) /2; ++i, --j) {
            out.append(sb.charAt(i));
            if (i != j) {
                out.append(sb.charAt(j));
            }
        }
        System.out.println(out.toString());
        int answer = Integer.parseInt(out.toString());
        System.out.println(answer);
        return answer;
    }
    public static void main(String a[]) {
        shuffle(Integer.parseInt(a[0]));
    }
}
