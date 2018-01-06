package Model;

import java.util.Enumeration;
import java.util.Map;
import java.util.Set;
import java.util.Map.Entry;

public interface MyIDictionary<T1,T2> {
	public Object add(T1 key, T2 value);
	public Object remove(T1 key);
	public int size();
	public boolean containsKey(T1 key);
	public boolean containsValue(T2 value);
	public T2 lookup(T1 id);
	public void update(T1 key,T2 value);
	public void setContent(Map<T1,T2> m);
	public Map<T1,T2> getContent();
	public Set<Entry<T1, T2>> entrySet();
	public Map<T1,T2> getMap();
	public Set<T1> getKeySet();
}
