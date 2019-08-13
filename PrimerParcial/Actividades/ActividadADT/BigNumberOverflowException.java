public class BigNumberOverflowException extends RuntimeException{
    public BigNumberOverflowException(){
        super("El numero se sobre pasa");
    }

    public BigNumberOverflowException(String msj){
        super(msj);
    }
}
