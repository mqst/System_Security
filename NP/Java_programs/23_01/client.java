// Addition of two numbers
import java.util.Scanner;
import java.io.*;
import java.net.*;

public class client{
public static void main(String[] args){
try{
Socket s = new Socket("localhost", 3420);
//DataOutputStream dout = new DataOutputStream(s.getOutputStream());


Scanner sc = new Scanner(System.in);
//System.out.println("Enter two numbers: \n");
//int n1 = sc.nextInt();
//int n2 = sc.nextInt();
//dout.writeInt(n1);
//dout.writeInt(n2);

BufferedReader in = new BufferedReader(
new InputStreamReader(
s.getInputStream()));

PrintWriter out = new PrintWriter(
new OutputStreamWriter(
s.getOutputStream()));
System.out.println("Started..");
String s1;
s1 = in.readLine();
System.out.println(s1);
s1 = in.readLine();
System.out.println(s1);

//while(true){
String s2 = sc.next();
out.print(s2);	
out.flush();
//out.close();
s1 = in.readLine();
System.out.println(s1);
//}
//s.close();
}
catch(Exception e){System.out.println(e);}
}
}
