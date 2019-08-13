public class ArithmeticException extends RuntimeException{
    public ArithmeticException(){
        super("Operacion invalida");
    }

    public ArithmeticException(String msj){
        super(msj);
    }
}
