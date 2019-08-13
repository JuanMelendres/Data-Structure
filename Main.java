public class Main{
    public static int mystery(int a, int b){
        if (b == 0) {
            return a;
        }
        return a + mystery(a, b - 1);
    }
    public static void main(String[] args) {
    	System.out.println(mystery(4,6));
    }

}
