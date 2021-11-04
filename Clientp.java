import java.io.*;
import java.net.*;

class Clientp
{
	public static void main(String arg[])throws Exception
	{
		String str1,str2;
		
		Socket s = new Socket("localhost",1994);
		
		System.out.println("Client is running...");
		
		PrintStream ps = new PrintStream(s.getOutputStream());
		
		BufferedReader br1 = new BufferedReader(new InputStreamReader(s.getInputStream()));
		
		BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));
		 
		
		while(!(str1 = br2.readLine()).equalsIgnoreCase("exit"))
		{
			ps.println(str1);
			str2 = br1.readLine();
			System.out.println("Server says :"+str2);
			System.out.println("Enter messege for Server");	
		}
		
		ps.close();
		br1.close();
		br2.close();
	}
}
