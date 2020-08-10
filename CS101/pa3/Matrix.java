/*
	Jason Bonilla 2018
*/
public class Matrix
{
		public class Entry
		{
			private int entryColumn; 
			private double entryValue;
			
			public Entry(){
			}
			public Entry(int column, double val)
			{
				this.entryColumn = column;
				this.entryValue = val;
			}
			public int getColumn()
			{
				return entryColumn;
			}
			public double getValue()
			{
				return entryValue;
			}
			public boolean equals(Entry x)
			{
				if(this.entryValue == x.entryValue)
				{
					return true;
				}
				return false;
			}
			public String toString()
			{
				if(entryValue == 0)
				{
					return "";
				}
				else
				{
					String temp = ("("+ entryColumn+ ", "+ entryValue+")" + " ");
					return temp;
				}
				
			}
			public void changeEntry(int column,double val)
			{
				this.entryValue = val;
				this.entryColumn = column;
			}
			public void changeValue(double n)
			{
				this.entryValue = n;
			}
		}
		

		private List[] matrixArray;
		private int arrayInitializer;
		private int matrixSize;

		public Matrix(){
		}
		public Matrix(int n)
		{
			if(n < 1)
			{
				System.err.println("Matrix needs to be at least 1 x 1");
        		System.exit(1);
			}
			matrixSize = n;
			arrayInitializer = 0;
			matrixArray = new List[n];
			while(arrayInitializer < n)
			{
				matrixArray[arrayInitializer] = new List();
				arrayInitializer++;
			}
		}
		
		public List getList(int r)
		{
			return matrixArray[r];
		}
		public int getMatrixArrayLength()
		{
			return matrixArray.length;
		}
		public int getSize()
		{
			return this.matrixSize;
		}
		public void appendToMatrix(int r, int col, double value)
		{
		

			Entry newEntry = new Entry(col, value);									
			int size = this.getSize();												
			if(r < size)
			{
				this.matrixArray[r].moveFront();
				
				if(matrixArray[r].getCursor() == null)								
				{
					
					matrixArray[r].append(newEntry);
				}
				else 																
				{
					this.matrixArray[r].moveFront();								
					Entry curEntry = (Entry)matrixArray[r].get();					
					
					if(matrixArray[r].length() <= 1)
					{
						
						if(newEntry.getColumn() < curEntry.getColumn())				
						{
							
							matrixArray[r].insertBefore(newEntry);
							this.matrixArray[r].moveFront();
						}	
						else
						if(newEntry.getColumn() > curEntry.getColumn())				
						{
							
							matrixArray[r].insertAfter(newEntry);						
							this.matrixArray[r].moveFront();
						}
					}
					else
					if(matrixArray[r].length() > 1)
					{
						
						while(curEntry != null)
						{
							if(newEntry.getColumn() < curEntry.getColumn())
							{
								
								matrixArray[r].insertBefore(newEntry);					
								this.matrixArray[r].moveFront();
								break;
							}
							else
							{
								
								this.matrixArray[r].moveNext();
								curEntry = (Entry)matrixArray[r].get();
							}	
						}
						if(curEntry == null)
						{
							matrixArray[r].append(newEntry);						
						}
					}
				}
			}
		}
		public List getMatrixArray(int r)
		{
			return this.matrixArray[r];
		}
		
		public int getNNZ()
		{
			if(this.getSize() == 0)
			{
				return 0;
			}
			int count = 0;
			int total = 0;
			while(count < getMatrixArrayLength())
			{

				total = total + matrixArray[count].length();		
				count++;											
			}
			



			int sizeOfMatrix = this.getSize();						
			int counter = 0;
			while(counter < sizeOfMatrix)							
			{
				matrixArray[counter].moveFront();					
				Entry curEntry = (Entry)matrixArray[counter].get();	

				while(curEntry != null)
				{
					if(curEntry.getValue() == 0)
					{
						total--;
					}
					
					matrixArray[counter].moveNext();				
					curEntry = (Entry)matrixArray[counter].get();	
				}
				counter++;											
			}

			return total;
		}
		void makeZero()
		{
			int count = 0;
			while(count < getMatrixArrayLength())
			{
				this.matrixArray[count] = null;
				count++;
				this.matrixSize = 0;
			}
		}
		public Matrix Copy()
		{
			Matrix newMatrix = new Matrix(this.getMatrixArrayLength());
			int sizeOfMatrix = this.getSize();						
			int counter = 0;
			while(counter < sizeOfMatrix)							
			{
				matrixArray[counter].moveFront();					
				Entry curEntry = (Entry)matrixArray[counter].get();	

				while(curEntry != null)
				{
					newMatrix.appendToMatrix(counter, curEntry.getColumn(),curEntry.getValue());
					
					matrixArray[counter].moveNext();				
					curEntry = (Entry)matrixArray[counter].get();	
				}
				counter++;											
			}

			return newMatrix;
		}
		void changeEntry(int r, int col, double value)
		{
			Entry newEntry = new Entry(col, value);
			matrixArray[r].moveFront();	
			Entry curEntry = (Entry)matrixArray[r].get();
			if(matrixArray[r].isEmpty() )
			{
				return;
			}			
			while(curEntry != null)
			{
				if(curEntry.getColumn() == col)
				{
					curEntry.changeValue(value);
				}
				matrixArray[r].moveNext();					
				curEntry = (Entry)matrixArray[r].get();
			}
		}
		void scalarMult(double x)
		{
			int sizeOfMatrix = this.getSize();						
			int counter = 0;
			while(counter < sizeOfMatrix)							
			{
				matrixArray[counter].moveFront();					
				Entry curEntry = (Entry)matrixArray[counter].get();	
				while(curEntry != null)
				{
					curEntry.changeValue((curEntry.getValue()*x));	
					matrixArray[counter].moveNext();				
					curEntry = (Entry)matrixArray[counter].get();	
				}
				counter++;											
			}
		}
		Matrix add(Matrix m)
		{
			int sizeOfMatrixOne = this.getSize();
			int sizeOfMatrixTwo = m.getSize();
			if(sizeOfMatrixOne != sizeOfMatrixTwo)
			{
				System.err.println("Error: Matrices are different sizes");
				System.exit(1);
			}
			int entryColOne;
			int entryColTwo;
			int counter = 0;
			Matrix newMatrix = new Matrix(sizeOfMatrixOne);					
			while(counter < sizeOfMatrixOne)
			{
				this.matrixArray[counter].moveFront();						
				m.matrixArray[counter].moveFront();							
				Entry curEntryOne = (Entry)this.matrixArray[counter].get();	
				Entry curEntryTwo = (Entry)m.matrixArray[counter].get();	
				
				
				while(curEntryOne != null || curEntryTwo != null)			
				{

					if(curEntryOne == null)									
					{
						
						newMatrix.appendToMatrix(counter,curEntryTwo.getColumn(),curEntryTwo.getValue());
						m.matrixArray[counter].moveNext();
						
					}
					else
					if(curEntryTwo == null)									
					{
						
						newMatrix.appendToMatrix(counter,curEntryOne.getColumn(),curEntryOne.getValue());
						this.matrixArray[counter].moveNext();
						
					}
					else
					{
						entryColOne =	curEntryOne.getColumn();
						entryColTwo =	curEntryTwo.getColumn();
						if(entryColOne < entryColTwo)						
						{													
							
							newMatrix.appendToMatrix(counter,entryColOne,curEntryOne.getValue());
							this.matrixArray[counter].moveNext();
							
						}
						else
						if(entryColOne > entryColTwo)						
						{
							
							newMatrix.appendToMatrix(counter,entryColTwo,curEntryTwo.getValue());
							m.matrixArray[counter].moveNext();
							
						}
						else
						if (entryColOne == entryColTwo) 						
						{
							
							newMatrix.appendToMatrix(counter,entryColOne,(curEntryOne.getValue()+curEntryTwo.getValue()));
							this.matrixArray[counter].moveNext();
							m.matrixArray[counter].moveNext();	
							
						}
					}
					curEntryOne = (Entry)this.matrixArray[counter].get();	
					curEntryTwo = (Entry)m.matrixArray[counter].get();
				}
				counter++;
			}
			return newMatrix;
		}
		Matrix sub(Matrix m)
		{
			int sizeOfMatrixOne = this.getSize();
			int sizeOfMatrixTwo = m.getSize();
			if(sizeOfMatrixOne != sizeOfMatrixTwo)
			{
				System.err.println("Error: Matrices are different sizes");
				System.exit(1);
			}
			int entryColOne;
			int entryColTwo;
			int counter = 0;
			Matrix newMatrix = new Matrix(sizeOfMatrixOne);					
			while(counter < sizeOfMatrixOne)
			{
				this.matrixArray[counter].moveFront();						
				m.matrixArray[counter].moveFront();							
				Entry curEntryOne = (Entry)this.matrixArray[counter].get();	
				Entry curEntryTwo = (Entry)m.matrixArray[counter].get();	
				
				
				while(curEntryOne != null || curEntryTwo != null)			
				{

					if(curEntryOne == null)									
					{
						
						newMatrix.appendToMatrix(counter,curEntryTwo.getColumn(),(curEntryTwo.getValue()*-1));
						m.matrixArray[counter].moveNext();
						
					}
					else
					if(curEntryTwo == null)									
					{
						
						newMatrix.appendToMatrix(counter,curEntryOne.getColumn(),curEntryOne.getValue());
						this.matrixArray[counter].moveNext();
						
					}
					else
					{
						entryColOne =	curEntryOne.getColumn();
						entryColTwo =	curEntryTwo.getColumn();
						if(entryColOne < entryColTwo)						
						{													
							
							newMatrix.appendToMatrix(counter,entryColOne,curEntryOne.getValue());
							this.matrixArray[counter].moveNext();
							
						}
						else
						if(entryColOne > entryColTwo)						
						{
							
							newMatrix.appendToMatrix(counter,entryColTwo,(curEntryTwo.getValue()*-1));
							
							m.matrixArray[counter].moveNext();
							
						}
						else
						if (entryColOne == entryColTwo) 						
						{
							
							newMatrix.appendToMatrix(counter,entryColTwo,(curEntryOne.getValue()-curEntryTwo.getValue()));
							
							this.matrixArray[counter].moveNext();
							m.matrixArray[counter].moveNext();	
							
						}
					}
					curEntryOne = (Entry)this.matrixArray[counter].get();	
					curEntryTwo = (Entry)m.matrixArray[counter].get();
				}
				counter++;
				
			}
			return newMatrix;
		}
		static double dot(List p, List q)
		{
			double total = 0;
			double product = 0;
			if(p.length() != 0 && q.length() != 0)
			{
				p.moveFront();
				q.moveFront();
				Entry pEntry = (Entry)p.get();
				Entry qEntry = (Entry)q.get();
				while(pEntry != null || qEntry != null)
				{
					

					if(qEntry == null && pEntry != null)
					{
						
						p.moveNext();
					}
					else
					if(pEntry == null && qEntry != null)
					{
						q.moveNext();
						
					}
					else
					if(pEntry.getColumn() < qEntry.getColumn())
					{
						
						p.moveNext();
					}
					else
					if(pEntry.getColumn() > qEntry.getColumn())
					{
						q.moveNext();
						
					}
					else
					if(pEntry.getColumn() == qEntry.getColumn())
					{
						product = (pEntry.getValue()*qEntry.getValue());
						total = total + product;
						
						p.moveNext();
						q.moveNext();
					}
					
					
					
					pEntry = (Entry)p.get();
					qEntry = (Entry)q.get();
				}
			}
			return total;
		}
		Matrix transpose()
		{
			

			int sizeOfMatrix = this.getSize();						
			int counter = 0;										
			double curValue;
			int curColumn;									
			Matrix datnewnew = new Matrix(sizeOfMatrix);
			while(counter < sizeOfMatrix)
			{
				matrixArray[counter].moveFront();					
				Entry curEntry = (Entry)matrixArray[counter].get();	
				while(curEntry != null)
				{
					curValue = curEntry.getValue();
					curColumn = curEntry.getColumn();
					datnewnew.appendToMatrix(curColumn-1,counter+1, curValue);
					matrixArray[counter].moveNext();
					curEntry = (Entry)matrixArray[counter].get();
				}
				counter++;
			}
			return datnewnew;
		}
		Matrix mult(Matrix m)
		{
			
			

			
			int sizeofMatrix1 = this.getSize();											
			Matrix newMatrix = new Matrix(sizeofMatrix1);								
			int newMatrixcounter = 0;													
			int newMatrixcounterrow = 0;
			Matrix transMatrix = m.transpose();											
			int counter = 0;
			double newValue;															
			while(counter < sizeofMatrix1)
			{
					

				while(newMatrixcounter < sizeofMatrix1)
				{
					newValue = dot(matrixArray[counter], transMatrix.matrixArray[newMatrixcounter]);
					newMatrix.appendToMatrix(counter,newMatrixcounter+1,newValue);
					
					newMatrixcounter++;
				}
				newMatrixcounter = 0;
				counter++;

			}
			return newMatrix;
		}
		public boolean zeroList(List l)
		{
			
			int count = 0;
			boolean empty = true;
			int check = l.length();
			l.moveFront();
			Entry curEntryOne = (Entry)l.get();			
			
			while(curEntryOne != null)					
			{
				
				if(curEntryOne.getValue() != 0)			
				{
					
					return false;
				}

				l.moveNext();					
				curEntryOne = (Entry)l.get();
				count++;
			}
			return empty;
		}
		public String toString()
		{
			
			
			String temp = "";
			String totalString = "";
			
			if (this.getSize() == 0) {								
				System.out.println("Matrix is Empty");
			}
			else
			{
				int count = 0;
				int row = 0;
				String x;
				while(count < this.getSize())									
				{
					if(zeroList(matrixArray[count]))							
					{
						temp ="";
						count++;
					}
					else
					{
						x = matrixArray[count].toString();				
						
						temp = (count+1)+": "+ x;
						totalString = totalString +temp + '\n';
						count++;
					}
					
	
				}
			}
			return totalString;
			
		}
		


}
