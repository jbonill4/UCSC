/*
	Jason Bonilla 2018
*/
public class MatrixTest
{
	public static void main(String[] args) {
		Matrix a = new Matrix(3);
		Matrix b = new Matrix(3);
		Matrix result;
		String printHelp;
		double value = 1.0;

		for(int row =0; row< a.getSize(); row++)
		{
			for (int col = 0;col <a.getSize();col++ ) 
			{
				a.appendToMatrix(row,col,value);
				value++;
				
			}
		}

		for(int row =0; row< a.getSize(); row++)
		{
			for (int col = 0;col <b.getSize();col++ ) 
			{
				
				b.appendToMatrix(row,col,value);
			}
		}
		
		b.changeEntry(1,0,5.0);
		b.changeEntry(0,0,5.0);
		b.changeEntry(1,1,7.0);
		List dot1 = b.getList(0);
		List dot2 = b.getList(1);

		double x = Matrix.dot(dot1,dot2);
		
		printHelp = a.getList(0).toString();
		System.out.println(" A Row: " +(1)+" "+ printHelp);
		printHelp = a.getList(1).toString();
		System.out.println(" A Row: " +(2)+" "+ printHelp);
		printHelp = a.getList(2).toString();
		System.out.println(" A Row: " +(3)+" "+ printHelp);


		Matrix c = a.transpose();
		printHelp = c.getList(0).toString();
		System.out.println(" C Row: " +(1)+" "+ printHelp);
		printHelp = c.getList(1).toString();
		System.out.println(" C Row: " +(2)+" "+ printHelp);
		printHelp = c.getList(2).toString();
		System.out.println(" C Row: " +(3)+" "+ printHelp);
		
		Matrix d = a.mult(c);
		printHelp = d.getList(0).toString();
		System.out.println(" D Row: " +(1)+" "+ printHelp);
		printHelp = d.getList(1).toString();
		System.out.println(" D Row: " +(2)+" "+ printHelp);
		printHelp = d.getList(2).toString();
		System.out.println(" D Row: " +(3)+" "+ printHelp);
		d.toString();
		System.out.println("The product of the dot product:" + x);
		for(int ro =0; ro< a.getSize(); ro++)
		{
			printHelp = b.getList(ro).toString();
     		System.out.println("Testing b before change: " +(ro+1)+" "+ printHelp);
		}
		b.changeEntry(1,0,5.0);
		System.out.println("");

		for(int ro =0; ro< a.getSize(); ro++)
		{
			printHelp = b.getList(ro).toString();
     		System.out.println("Testing b AFTER change: " +(ro+1)+" "+ printHelp);
		}
		System.out.println("Total number of NonZeroTerms in b: " + b.getNNZ());	
		result = a.sub(b);
		for(int ro =0; ro< a.getSize(); ro++)
		{
			printHelp = result.getList(ro).toString();
     		System.out.println("Testing sub: " +(ro+1)+" "+ printHelp);
		}
		System.out.println("Total number of NonZeroTerms in the result: " + result.getNNZ());
		System.out.println("");
		result = a.add(b);
		
		for(int r =0; r< a.getSize(); r++)
		{
			printHelp = result.getList(r).toString();
     		System.out.println("Testing scalarMult: " +(r+1)+" "+ printHelp);
		}
		System.out.println("Total number of NonZeroTerms in a: " + a.getNNZ());
		System.out.println("");
		a.scalarMult(2.0);
		for(int ro =0; ro< a.getSize(); ro++)
		{
			printHelp = a.getList(ro).toString();
     		System.out.println("Testing sub: " +(ro+1)+" "+ printHelp);
		}
		System.out.println("");
		
		a.makeZero();
		System.out.println("Total number of NonZeroTerms in a after makeZero: " + a.getNNZ());

	}
}
