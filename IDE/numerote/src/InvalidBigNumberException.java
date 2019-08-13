/*
 * 
 * Juan Antonio Melendres Villa A0039017
 * 
*/

public class InvalidBigNumberException extends RuntimeException{
    public InvalidBigNumberException(){
        super("Numero invalido");
    }

    public InvalidBigNumberException(String msj){
        super(msj);
    }
}
