/*
 *
 * Juan Antonio Melendres Villa A0039017
 *
 * Comentario: la ultima operacion de modulo no da resultado, el programa sigue corriendo, por eso esta como comentario.
*/

public class Main {

   public static void main(String[] args) throws Exception {
	   BigNumber bn1 = new BigNumber("1234567890123456789012345678901234567890");
	   BigNumber bn2 = new BigNumber("5678990567890567890567890567890567890567890567890");
	   BigNumber bn3 = new BigNumber("38473847874728740283748237408237428347128347082134700");
	   BigNumber bn4 = new BigNumber("42893740482574097583475382");
	   BigNumber bn5 = new BigNumber("0");
	   BigNumber bn6 = new BigNumber("3847384787472874028374823740823742834712834708213470038473847874728740283748237408237428347128347082134700");
	   BigNumber bn7 = new BigNumber("82837589245u897");

	   System.out.println("La multiplicacion de bn3 * bn1 = " + bn3.multiply(bn1)); //overflow

	   System.out.println("La suma de bn2 + bn3 = " + bn2.add(bn3));  //Correct

	   System.out.println("La division de bn5 / bn4 = " + bn5.divide(bn4)); //Arithmetic error

	   System.out.println("La resta de bn3 - bn1 = " + bn3.subtract(bn1)); //correct

	   System.out.println("La resta de bn1 - bn3 = " + bn1.subtract(bn3)); //exception

	   System.out.println("La multiplicacion de bn4 * bn4 = " + bn4.multiply(bn4));  //correct

	   System.out.println("La division de bn3 / bn4 = " + bn3.divide(bn4)); //correct

	   //System.out.println("El modulo de bn3 % bn1 = " + bn3.module(bn1)); //correct
   }


}
