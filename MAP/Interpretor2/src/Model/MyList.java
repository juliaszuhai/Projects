package Model;

import java.util.*;

public class MyList<T> implements MyIList<T> {

	ArrayList<T> list;
	public MyList(){
		this.list=new ArrayList<T>();
	}
	public void add(T i)
	{
		this.list.add(i);
	}
	public void remove(T i)
	{
		this.list.remove(i);
	}
	@Override
	public String toString(){
		String str=" ";
		for(T t:this.list)
			str=str+" "+t;
		return str;
	}
	
}
