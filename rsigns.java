import java.util.*;
import java.math.*;


class rsigns
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int l=0;l<t;l++)
		{
			double k = sc.nextDouble();

			if(k<=5)
			{
				int total_signs =(int) Math.pow(10,k);
				int counter = 0;
				for(int i=0;i<total_signs;i++)
				{
					
					String s = Integer.toString(i);
					int  k2 = total_signs-i-1;
					String s2 = Integer.toString(k2);
					char[] sarr2 = new char[s2.length()];
					char[] sarr = new char[s.length()];
					s2.getChars(0,s2.length(),sarr2,0);
					s.getChars(0,s.length(),sarr,0);
					Set setA = new HashSet();
					Set setB = new HashSet();

					for(int j=0;j<s.length();j++)
					{
						setA.add(sarr[j]);
					}
					for(int j=0;j<s2.length();j++)
					{
						setB.add(sarr2[j]);
					}

					//System.out.println(setA.size() + " " + setB.size()+ " " +i+ " " +k2+" "+setA+" "+setB);
					Set setC = new HashSet();

					Iterator iterator = setA.iterator();
					while(iterator.hasNext())
					{
						setC.add(iterator.next());
					}
					iterator = setB.iterator();
					while(iterator.hasNext())
					{
						setC.add(iterator.next());
					}

					if(setC.size() == 2)
					{
						
						counter++;
					}

					

				
				}

				System.out.println(counter);
			}
			else
			{
				System.out.println(1);	
			}
			
		}
	
	}

}
