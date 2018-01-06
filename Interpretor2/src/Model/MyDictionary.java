package Model;

import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;


public abstract class MyDictionary<T1,T2> implements MyIDictionary<T1, T2> {
	Map<T1,T2> dict;
	
public MyDictionary(){
	this.dict=new Hashtable<T1,T2>();
}

public Object add(T1 key, T2 value)
{
	return this.dict.put(key,value);
}
public Object remove(T1 key)
{
	return this.dict.remove(key);
}
public int size()
{
	return this.dict.size();
}
public boolean containsKey(T1 key)
{
	return this.dict.containsKey(key);
}
public boolean containsValue(T2 value)
{
	return this.dict.containsValue(value);
}
public T2 lookup(T1 id)
{
	return (T2)dict.get(id);
}
public void update(T1 key,T2 value)
{
	this.dict.replace(key, value);
}
@Override
public void setContent(Map<T1,T2> m)
{
	this.dict=m;
	
}
@Override
public Map<T1,T2> getContent()
{
return this.dict;	
}

public Map<T1,T2> getMap()
{
	return this.dict;
}
public Set<T1> getKeySet()
{
	return this.dict.keySet();
}

public Set<Entry<T1, T2>> entrySet()
{
	return this.dict.entrySet();
}

}
