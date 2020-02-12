import java.util.*;
import java.net.*;
public class IPFinder{
public static void main(String[] args){
String host;
Scanner input = new Scanner(System.in);
System.out.println("======================================================");
System.out.println("Enter host name: ");
host=input.next();

try{
InetAddress address = InetAddress.getByName(host);
System.out.println("\nIP address: "+address.toString());
}
catch(UnknownHostException e){
System.out.println("\nCould not find: "+host);

}


}
}
