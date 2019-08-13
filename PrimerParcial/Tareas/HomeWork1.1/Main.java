/*
    Juan Antonio Melendres Villa A00369017
    comentarios: Realiza una operacion por input, se puede compilar mandalole el arvhico por medio del compilador, por medio de una ruta que se pega en los dos metodos
    ejemplo:
        -----> java Main < Archivo.txt --- parentesisBalanceados(archivo), evaluar(archivo)
        -----> parentesisBalanceados(leerArchivo(/Users/juanantoniomelendresvilla/Desktop/Archivo.txt) & evaluar(leerArchivo(/Users/juanantoniomelendresvilla/Desktop/Archivo.txt))
*/

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Scanner;

public class Main {

    public static String leerArchivo(String archivo){
        String cadena = " ";
        String texto = " ";
        StringBuilder sb = new StringBuilder();
        try {
            FileReader f = new FileReader(archivo);
            BufferedReader br = new BufferedReader(f);
            while((cadena = br.readLine()) != null) {
                sb.append(cadena);
                sb.append('\n');
            }
            br.close();
        }
        catch(FileNotFoundException e) {
            System.out.println("El archivo no se localizo: " + e);
        }
        catch(IOException e) {
            System.out.println("El archivo no se puede leer: " + e);
        }
        texto = sb.toString();
        return texto;
    }

    public static boolean parentesisBalanceados(String archivo){
        System.out.println("La expresion matematica es: " + archivo);
        MyQueue<Character> checar = new MyQueue<Character>();
        for (int i = 0; i < archivo.length(); i++) {
            char c = archivo.charAt(i);
            if(c == '[' || c == '(' || c == '{' ) {
                checar.enqueue(c);
            }
            else if(c == ']' || c == '}' || c == ')'){
                if(checar.isEmpty()) {
                    return false;
                }
                switch(c){
                case ']':
                    if (checar.dequeue() != '[') {
                        return false;
                    }
                    break;
                    case '}':
                    if (checar.dequeue() != '{') {
                        return false;
                    }
                    break;
                case ')':
                    if (checar.dequeue() != '(') {
                        return false;
                    }
                    break;
                default:
                    break;
                }
            }
        }
        if(checar.isEmpty()) {
            return true;
        }
        return false;
    }

    public static String evaluar(String cadena) {
        cadena = cadena.replaceAll("\\s", "");
        MyStack<String> operandos = new MyStack<>();
        MyStack<String> operadores = new MyStack<>();
        StringTokenizer tokens = new StringTokenizer(cadena, "()*/+-", true);

        while (tokens.hasMoreElements()) {
            String tkn = tokens.nextToken();
            if (tkn.equals("(") || tkn.matches("[0-9]+")) {
                operandos.push(tkn);
            }
            if (tkn.equals("*") || tkn.equals("/") || tkn.equals("+") || tkn.equals("-")) {
                operadores.push(tkn);
            }
            else if (tkn.equals(")")) {
                try {
                    int op2 = Integer.parseInt(operandos.pop()); //operandos
                    String oprnd = operadores.pop();	//operadores
                    int op1 = Integer.parseInt(operandos.pop()); //operandos
                    if(!operandos.isEmpty()){
                        operandos.pop();
                    }
                    int result = 0;
                    if(oprnd.equals("*")){
                        result = op1 * op2;
                    }
                    else if(oprnd.equals("/")){
                        result = op1 / op2;
                    }
                    else if(oprnd.equals("+")){
                        result = op1 + op2;
                    }
                    else if(oprnd.equals("-")){
                        result = op1 - op2;
                    }
                    operandos.push(result+"");
                }
                catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
        String finalResult = "";
        try {
            finalResult = operandos.pop();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
        return finalResult;
    }

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        String archivo = "";
        while (input.hasNextLine()) {
            archivo = archivo + input.nextLine().toUpperCase();
        }
        System.out.println("Pevaluates a math expession in infix notation using parenthesis\n");
        if (parentesisBalanceados(archivo)) {
            System.out.println(evaluar(archivo) + "\n"); //29
        }
        else {
            System.out.println("No se puede evaluar ya que los parentesis no estan balanceados!!\n");
        }
    }

}
