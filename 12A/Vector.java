/*
    Jason Bonilla 2016
	This simple segment of code adds, subtracts, multiplies, finds maginutude
	dot product, and the angle between two vectors
	Vector.java
*/

public class Vector 
{
	private double x;
	private double y;

	//examples
	public static void main(String[] args)
	{
		Vector y = new Vector(4.0, 5.0);
		Vector x = new Vector(6.0, 3.0);
		System.out.println(x.add(y));
		System.out.println(x.subtract(y));
		System.out.println(x.magnitude());
		System.out.println(x.multScalar(2));
		System.out.println(x.subtract(y));
		System.out.println(x.ang(y));
		System.out.println(x.dotProduct(y));
		
	}
	//Creates empty vector
	public Vector()
	{
		x=0;
		y=0;
	}
	//Creates vector with given values
	public Vector(double a, double b)
	{
		x = a;
		y = b;
	}
	//returns first value (direction)
	public double firstNum()
	{
		return x;
	}
	//returns second value (magnitude)
	public double secondNum()
	{
		return y;
	}
	//adds two vectors
	public Vector add(Vector cur)
	{
		return new Vector(firstNum() + cur.firstNum(), secondNum() + cur.secondNum());
	}
	//subtracts two vectors
	public Vector subtract(Vector cur)
	{
		return new Vector(firstNum() - cur.firstNum(), secondNum() - cur.secondNum());
	}
	//finds magnituwde
	public double magnitude()
	{
		return Math.sqrt(y*y + x*x);
	}
	//multiplies vector by a scalar
	public Vector multScalar(int r)
	{
		return new Vector(firstNum()*r, r*secondNum());
	}
	//finds angle between two vectors
	public double ang(Vector cur)
	{
		double temp1= Math.atan2(secondNum(),firstNum());
		double temp2= Math.atan2(cur.secondNum(),cur.firstNum());
		if(temp2-temp1 < 0)
		{
			return((temp2-temp1)*-1);
		}
		else
			return temp2-temp1;
	}
	//finds the dot product between two vectors
	public double dotProduct(Vector cur)
	{
		double sum = (firstNum()*cur.firstNum() + cur.secondNum()*secondNum());
		return sum;
	}

	public String toString()
	{
		return ("vector = "+x+"."+y);

	}
	
	
}