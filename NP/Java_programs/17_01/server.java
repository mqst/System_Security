import java.net.*;
import java.io.*;

class server{
public static void main(String[] args){
try{
ServerSocket ss = new ServerSocket(1004);
Socket s = ss.accept();
DataInputStream dis = new DataInputStream(s.getInputStream());
String str = (String)dis.readUTF();
System.out.println("Message = "+str);
ss.close();
}
catch(Exception e){System.out.println(e);}
}
}
