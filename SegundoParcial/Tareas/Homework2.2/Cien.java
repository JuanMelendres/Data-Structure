public class Main{

    public static void main(String[] args){
        float aux = 0.00001;
        int a = 100000000;
        float res = 0.0;
        for(int i = 0; i < a; i++){
            res+=aux;
        }
        System.out.println(res);
    }

}