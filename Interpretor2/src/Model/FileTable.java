package Model;

import java.util.Map.Entry;

public class FileTable<T1,T2> extends MyDictionary<T1, T2> {
	
	
	public String toString()
	{
		String str="";
		for(Entry<T1,T2> entry:dict.entrySet())
		{
			Integer key=(Integer) entry.getKey();
			Tuple value=(Tuple) entry.getValue();
			str=str+key+" ="+value+"\n";
		}
		return str;
	}

}
