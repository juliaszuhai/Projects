package Model;

import java.util.Stack;

public class MyStack<T> implements MyIStack<T> {
	Stack<T> stack;
	
public MyStack()
{
	this.stack=new Stack <T>() ;
}
public void push(T elem)
{
	this.stack.push(elem);
}
public T pop()
{
	return this.stack.pop();
}
public boolean isEmpty()
{
	return this.stack.isEmpty();
}
@Override
public String toString(){
	String str="";
	for(T e:this.stack)
	{
		str=str+e.toString()+" ";
	}
	return str;
}


}
