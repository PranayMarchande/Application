import java.io.*;
import java.net.*;

class Serverp
{
	public static void main(String arg[])throws Exception
	{
		String str1,str2;
		
		ServerSocket ss = new ServerSocket(1994);
		
		System.out.println("Server is running...");
		
		Socket s = ss.accept();
		
		System.out.println("\n\nConnection is successfully established...\n\n");
		
		PrintStream ps = new PrintStream(s.getOutputStream());
		
		BufferedReader br1 = new BufferedReader(new InputStreamReader(s.getInputStream()));
		
		BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));
		 
		
		while((str1 = br1.readLine()) != null)
		{
			System.out.println("Client says : "+str1);
			System.out.println("Enter message for Client");
			str2 = br2.readLine();
			ps.println(str2);
		}
		
		ps.close();
		br1.close();
		br2.close();
		
	}
}
		