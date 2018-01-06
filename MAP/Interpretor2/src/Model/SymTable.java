package Model;

import java.util.Map.Entry;

public class SymTable<T1, T2> extends MyDictionary<T1, T2> {

	public String toString()
	{
		
		String str="";
		for(Entry<T1,T2> entry:dict.entrySet())
		{
			String key=(String) entry.getKey();
			Integer value=(Integer) entry.getValue();
			str=str+key+" ="+value+"\n";
		}
		return str;
	}
}