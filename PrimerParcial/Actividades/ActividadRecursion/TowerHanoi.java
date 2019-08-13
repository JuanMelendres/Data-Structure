public class TowerHanoi {

    static int cont;

    public static void hanoi(int d, char origen, char destino, char intermedio){
        cont++;
        if (d == 1) {
            System.out.println("Mueve el disco 1 de " + origen + " a " + destino);
        }
        else {
            // mover n-1 discos A origen a intermedio
            hanoi(d-1, origen, intermedio, destino);
            // mover disco n a destino
            System.out.println("Mueve el disco " + d + " de " + origen + " a " + destino);
            // mover n-1 intermedio destino
            hanoi(d-1, intermedio, destino, origen);
        }
    }

    public static void main(String[] args) {
        hanoi(3, 'A', 'C', 'B');
        System.out.println("Numero de pasos " + cont);
    }
}
