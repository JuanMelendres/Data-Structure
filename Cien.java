public class Cien{

    public static void main(String[] args){
        double aux = 0.00001;
        int a = 100000000;
        double res = 0.0;
        for(int i = 0; i < a+1; i++){
            res+=aux;
        }
        System.out.println(res);
    }

}