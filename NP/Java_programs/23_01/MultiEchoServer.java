import java.io.*;
import java.net.*;

class MultiEchoServer{
public static void main(String[] args){

try {
ServerSocket s = new ServerSocket(3420);
while(true){
Socket incoming = s.accept();
System.out.println("Client Connected..");
new ClientHandler(incoming).start();
}
} catch(Exception e){}
}
}

class ClientHandler extends Thread{
protected Socket incoming;
public ClientHandler(Socket incoming){
this.incoming = incoming;
}
public void run(){
try{
BufferedReader in = new BufferedReader(
new InputStreamReader(
incoming.getInputStream()));
PrintWriter out = new PrintWriter(
new OutputStreamWriter(
incoming.getOutputStream()));

out.println("Hello! ...");
out.println("Enter BYE to exit.");
out.flush();
while(true){
String str = in.readLine();
System.out.println(str);
if(str == null) {break;}
out.println("Echo: " + str);
out.flush();
if(str.trim().equals("BYE"))
break;
}
in.close();
out.close();
//incoming.close();
} catch(Exception e){}
}
}

