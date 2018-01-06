package Model;

import java.io.BufferedReader;

public class Tuple<T1,T2> {
	public T1 filename;
	public T2 descriptor;
	
	public Tuple(T1 s,T2 b)
	{
		this.filename=s;
		this.descriptor=b;
	}
	
	public T1 getFilename()
	{
		return this.filename;
	}
	
	public T2 getDescriptor()
	{
		return this.descriptor;
	}
	
	public String toString()
	{
		return this.filename.toString()+this.descriptor.toString();
	}
	public boolean equals(Tuple<T1,T2> t)
	{
		return this.filename.equals(t.getFilename());
	}
}
