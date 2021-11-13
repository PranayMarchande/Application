import java.io.*;
import java.net.*;
import java.awt.*;  
import java.awt.event.*;

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
		
		Demo d = new Demo(); 
		
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

class Demo
{  
	Demo()
	{  

		Frame f = new Frame("Chat Box");  
		  
		Label SName = new Label("Message for Server");  
		SName.setBounds(20, 50, 120, 20);  
		  
		Label BName = new Label("Server Says:");  
		BName.setBounds(20, 150, 120, 20);  
		  
		TextField SNameTF = new TextField();  
		SNameTF.setBounds(160, 50, 150, 30); //x,y,w,h 
		  
		TextField BNameTF = new TextField();  
		BNameTF.setBounds(160, 150, 150, 30);  
		  
		Button send = new Button("send");  
		send.setBounds(120, 250, 80, 40);   
		  
		f.add(SName);  
		f.add(BName);  
		f.add(SNameTF);  
		f.add(BNameTF);  
		f.add(send);   
		  
		f.setSize(400,350);  
		f.setLayout(null);  
		f.setVisible(true); 
	
		f.addWindowListener(new WindowAdapter(){
		public void windowClosing(WindowEvent w)
		{
			System.exit(0);
		}		
		});
	}
		
} 