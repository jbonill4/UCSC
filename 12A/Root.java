/*
	Jason Bonilla 2016
	Finds roots in between two endpoints
*/
import java.util.Scanner;
public class Root
{
	public static void main(String[] args)
	{
		double resolution = .01;
		double tolerance = .0000001;
		double threshold = .001;
		double degree, co, leftE, rightE, end;
		double[] arr = new double[100];
		//arr[0] = -1;
		Scanner sc = new Scanner(System.in);
		

		System.out.println("Enter the degree:");
		degree = sc.nextInt();

		System.out.println("Enter"+ (degree+1) +"coefficients:");
		int wq = (int)degree+1;
		double[] pol = new double[wq];
		for(int i = 0; i< (degree+1); i++)
		{
			pol[i] = sc.nextInt();
		}

		System.out.println("Enter left and right endpoints");
		leftE = sc.nextInt();
		rightE = sc.nextInt();
		int temp = 0;
		for(double i =leftE; (Math.abs(leftE-rightE))>threshold;i+=resolution)
		{

			if(poly(pol,i)*poly(pol,leftE)<=0)//regular change in sign
			{
				arr[temp]=findRoot(pol,leftE,rightE,tolerance);
				
				temp++;
			}
			else
			if((poly(diff(pol),i)*poly(diff(pol),leftE)) <=0)//derivative change in sign
			{
				arr[temp] = findRoot(diff(pol),leftE,rightE,tolerance);
				temp++;
			}
			leftE=i;
		}
        double[] real = new double[temp];

		int x =0;
		for(int i =0; i<arr.length;i++)
		{
			real[i] = arr[i];
		}
		if(real.length >0)
		{
			System.out.println("No roots were found");
		}
		else
		if(arr.length > 0)
		{
			for(int i = 0;i< arr.length;i++)
			{
				System.out.println("Root found at "+real[i]);
			}
		}
    }

	public static double poly(double[] C, double x)
	{
		double total = 0;
		double[] temp = new double[C.length];
		for(int i = 1; i < C.length;i++)
		{
			total += (Math.pow(x,i)*C[i]);
		}
		return total+C[0];
	}
	public static double[] diff(double[] c)
	{
		double[] D = new double[c.length-1];
		for(int i = 1; i < c.length;i++)
		{
			D[i-1] = (c[i]*i);
			
		}
		return D;

	}
	public static double findRoot(double[] c, double a, double b, double tolerance)
	{
		
		double width = b-a;
		double middle = 0;
		while(width> tolerance)
		{
			middle = (a+b)/(double)2;
			if(poly(c, a)*poly(c,middle) <= 0)
			{
				a = middle;
			}
			else
			{
				b = middle;
			}
			width = b-a;
	    }
	return middle;
	}


}
