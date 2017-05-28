import java.net.*;
import java.io.*;

class server {
	public static void main(String args[]) throws Exception {
	ServerSocket a = new ServerSocket(9876);
	System.out.println("Address binding over");
	Socket b = a.accept();
	System.out.println("Got client");
	DataOutputStream d = new DataOutputStream(b.getOutputStream());
	d.writeUTF("Computer Networks Lab");
	d.writeUTF("Server says: Send me some string");

	DataInputStream q = new DataInputStream(b.getInputStream());
	String r = new String(q.readUTF());
	System.out.println("received from client: "+r);

	// Send response with first letter stripped
	d.writeUTF(r.substring(1));

	//Sending two string to client
	System.out.println("Sending: two strings");
	// Read from System input
	DataInputStream y = new DataInputStream(System.in);
	String g = y.readLine();
	d.writeUTF(g);
	g = y.readLine();
	d.writeUTF(g);

	// Receiving Joint string
	
	r = new String(q.readUTF());
	System.out.println("received joint string from client: "+r);
	
	
	a.close();
	}
}

class client {
	public static void main(String args[]) throws Exception {
	Socket p = new Socket(InetAddress.getLocalHost(), 9876);
	System.out.println(p+" connected!");
	DataInputStream q = new DataInputStream(p.getInputStream());
	String r = new String(q.readUTF());
	System.out.println("received: "+r);
	r = new String(q.readUTF());
	System.out.println("received: "+r);

	// Read from System input
	System.out.println("Enter input to send");
	DataInputStream y = new DataInputStream(System.in);
	String g = y.readLine();
	
	DataOutputStream d = new DataOutputStream(p.getOutputStream());
	d.writeUTF(g);
	
	// Receiving first letter stripped string
	r = new String(q.readUTF());
	System.out.println("received: "+r);

	// Receiving two strings to join
	r = new String(q.readUTF());
	String s = new String(q.readUTF());
	// Sending back joint string
	d.writeUTF(r+s);

	p.close();
	}
}

class multiserver {
	public static void main(String args[]) throws Exception {
	ServerSocket a = new ServerSocket(9876);
	System.out.println("Address binding over");
	Socket b = a.accept();
	System.out.println("Got client");

	DataInputStream q1 = new DataInputStream(b.getInputStream());
	String r = new String(q1.readUTF());
	System.out.println("received from clienta: "+r);

	Socket c = a.accept();
	System.out.println("Got client");


	DataInputStream q2 = new DataInputStream(c.getInputStream());
	String s = new String(q2.readUTF());
	System.out.println("received from clientb: "+s);

	DataOutputStream d1 = new DataOutputStream(b.getOutputStream());
	d1.writeUTF(s);

	DataOutputStream d2 = new DataOutputStream(c.getOutputStream());
	d2.writeUTF(r);
	
	a.close();
	}
}

class clienta {
	public static void main(String args[]) throws Exception {
	Socket p = new Socket(InetAddress.getLocalHost(), 9876);
	System.out.println(p+" connected!");

	// Read from System input
	System.out.println("Enter input to send");
	DataInputStream y = new DataInputStream(System.in);
	String g = y.readLine();
		
	DataOutputStream d = new DataOutputStream(p.getOutputStream());
	d.writeUTF(g);

	DataInputStream q = new DataInputStream(p.getInputStream());
	String r = new String(q.readUTF());
	System.out.println("received: "+r);

	p.close();
	}
}

class clientb {
	public static void main(String args[]) throws Exception {
	Socket p = new Socket(InetAddress.getLocalHost(), 9876);
	System.out.println(p+" connected!");
	
	// Read from System input
	System.out.println("Enter input to send");
	DataInputStream y = new DataInputStream(System.in);
	String g = y.readLine();

	DataOutputStream d = new DataOutputStream(p.getOutputStream());
	d.writeUTF(g);

	DataInputStream q = new DataInputStream(p.getInputStream());
	String r = new String(q.readUTF());
	System.out.println("received: "+r);

	p.close();
	}
}

class servera {
	public static void main(String args[]) throws Exception {
	ServerSocket a = new ServerSocket(9876);
	System.out.println("Address binding over");
	Socket b = a.accept();
	System.out.println("Got client");

	DataInputStream q1 = new DataInputStream(b.getInputStream());
	String r = new String(q1.readUTF());
	System.out.println("received from clientc: "+r);

	DataOutputStream d = new DataOutputStream(b.getOutputStream());
	d.writeUTF(r);

	r = new String(q1.readUTF());
	System.out.println("received from clientc: "+r);

	a.close();
	}
}

class serverb {
	public static void main(String args[]) throws Exception {
	ServerSocket a = new ServerSocket(9877);
	System.out.println("Address binding over");
	Socket b = a.accept();
	System.out.println("Got client");

	DataInputStream q1 = new DataInputStream(b.getInputStream());
	String r = new String(q1.readUTF());
	System.out.println("received from clientc: "+r);
	
	DataOutputStream d = new DataOutputStream(b.getOutputStream());
	d.writeUTF(r);

	r = new String(q1.readUTF());
	System.out.println("received from clientc: "+r);
	
	a.close();
	}
}

class clientc {
	public static void main(String args[]) throws Exception {
	Socket p = new Socket(InetAddress.getLocalHost(), 9876);
	System.out.println(p+" connected!");

	Socket q = new Socket(InetAddress.getLocalHost(), 9877);
	System.out.println(q+" connected!");
	
	// Read from System input
	System.out.println("Enter input to send to servera");
	DataInputStream y = new DataInputStream(System.in);
	String g = y.readLine();

	DataOutputStream d1 = new DataOutputStream(p.getOutputStream());
	d1.writeUTF(g);

	// Read from System input
	System.out.println("Enter input to send to serverb");
	y = new DataInputStream(System.in);
	g = y.readLine();

	DataOutputStream d2 = new DataOutputStream(q.getOutputStream());
	d2.writeUTF(g);

	DataInputStream q1 = new DataInputStream(p.getInputStream());
	String r = new String(q1.readUTF());
	DataInputStream q2 = new DataInputStream(q.getInputStream());
	String s = new String(q2.readUTF());
	System.out.println(r+s);

	d1.writeUTF(s);
	d2.writeUTF(r);

	p.close();
	q.close();
	}
}

class server12 {
	public static void main(String args[]) throws Exception {
	ServerSocket a = new ServerSocket(9876);
	System.out.println("Address binding over");
	Socket b = a.accept();
	System.out.println("Got client");

	DataInputStream y = new DataInputStream(System.in);
	String g = y.readLine();

	DataOutputStream d = new DataOutputStream(b.getOutputStream());
	d.writeUTF(g);
	
	a.close();
	}
}

class client12 {
	public static void main(String args[]) throws Exception {
	Socket p = new Socket(InetAddress.getLocalHost(), 9876);
	System.out.println(p+" connected!");

	DataInputStream q = new DataInputStream(p.getInputStream());
	String r = new String(q.readUTF());
	System.out.println("received: "+r);
	
	p.close();
	}
}


















