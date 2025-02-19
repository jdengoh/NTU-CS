import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

public class Rfc865UdpClient {
	public static void main(String[] argv) throws SocketException, UnknownHostException {
		// 1. Open UDP Socket
		DatagramSocket socket = new DatagramSocket();
		InetAddress address = InetAddress.getByName("hwlab1.scse.ntu.edu.sg"); // quote of the day server
		//InetAddress address = InetAddress.getByName("127.0.0.1"); // loopback to send to Rfc865UdpServer.java
		//InetAddress address = InetAddress.getByName("ip_address_put_here"); // Donald Duck
		
		byte[] buffer = new byte[512];
		
		try {
			// 2. Send UDP Request to Server
			String message = new String("Jden, SCS4, 10.96.177.109");
			buffer = message.getBytes();
			DatagramPacket request = new DatagramPacket(buffer, buffer.length, address, 17); // QOTD port 17
			socket.send(request);
			
			// 3. Receive UDP Reply from Server
			buffer = new byte[65535];
			DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
			socket.receive(reply);
			String received = new String(reply.getData(), 0, reply.getLength());
			System.out.println(received);
		} catch (IOException e) {} 
		
		System.out.println("Closing Socket...");
		socket.close();
	}
}
