import java.net.*;
import java.io.*;

class server{
public static void main(String[] args){
try{
ServerSocket ss = new ServerSocket(1004);
Socket s = ss.accept();
DataInputStream dis = new DataInputStream(s.getInputStream());
int n1 = (int)dis.readInt();
int n2 = (int)dis.readInt();
int n3 = n1 + n2;
System.out.println("Addition = "+n3);
ss.close();
}
catch(Exception e){System.out.println(e);}
}
}
