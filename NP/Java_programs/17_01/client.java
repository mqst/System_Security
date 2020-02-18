import java.io.*;
import java.net.*;

public class client{
public static void main(String[] args){
try{
Socket s = new Socket("localhost", 1004);
DataOutputStream dout = new DataOutputStream(s.getOutputStream());
dout.writeUTF("Hello Serverrr!");
dout.flush();
dout.close();
s.close();
}
catch(Exception e){System.out.println(e);}
}
}





