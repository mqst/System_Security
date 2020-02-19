// Addition of two numbers
import java.util.Scanner;
import java.io.*;
import java.net.*;

public class client{
public static void main(String[] args){
try{
Socket s = new Socket("localhost", 1004);
DataOutputStream dout = new DataOutputStream(s.getOutputStream());
Scanner sc = new Scanner(System.in);

System.out.println("Enter two numbers: \n");
int n1 = sc.nextInt();
int n2 = sc.nextInt();
dout.writeInt(n1);
dout.writeInt(n2);

dout.flush();
dout.close();
s.close();
}
catch(Exception e){System.out.println(e);}
}
}
