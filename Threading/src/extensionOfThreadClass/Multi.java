package extensionOfThreadClass;

public class Multi extends Thread{
	
	public void run()
	{
		try {
			for(int i=0;i<5;i++)
			{
		System.out.println(i);
		Thread.sleep(500);
			}
		}
		catch(Exception e)
		{
			System.out.println(e);
			
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Multi t1=new Multi();
		Multi t2=new Multi();
		Multi t3=new Multi();
		t1.start();
		try
		{
			
		}catch(Exception e) {System.out.println(e);}
		t2.start();
		t3.start();

	}

}
