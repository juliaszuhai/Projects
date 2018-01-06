package Model;

import java.io.BufferedReader;

public class PrgState {
	MyIStack<IStmt> exeStack;
	MyIDictionary<String,Integer> symTable;
	MyIList<Integer> out;
	MyIDictionary<Integer,Tuple<String,BufferedReader>> fileTable;
	MyIDictionary<Integer,Integer> heap;
	IStmt originalProgram;
	
	public PrgState(MyIStack<IStmt> e,	MyIDictionary<String,Integer> s,	MyIList<Integer> o,MyIDictionary<Integer,Tuple<String,BufferedReader>> t,MyIDictionary<Integer,Integer> h)
	{
		this.exeStack=e;
		this.symTable=s;
		this.out=o;
		this.fileTable=t;
		this.heap=h;
	}
	public MyIStack<IStmt> getExeStack()
	{
		return this.exeStack;
	}
	public MyIDictionary<String,Integer> getSymTable()
	{
		return this.symTable;
	}
	public MyIDictionary<Integer,Integer> getHeap()
	{
		return this.heap;
	}
	public MyIList<Integer> getOut()
	{
		return this.out;
	}
	public MyIDictionary<Integer,Tuple<String,BufferedReader>> getFileTable()
	{
		return this.fileTable;
	}
	@Override
	public String toString(){
		return "\nExeStack:\n"+this.exeStack.toString()+"\n-----------------------\n"+
				"\nSymTable:\n"+ this.symTable.toString()+"\n------------------------\n"+
				"Out:\n" + this.out.toString()+"\n------------------------\n"+
				"FileTable:\n"+this.fileTable.toString()+"\n------------------------\n"+
				"Heap:\n"+this.heap.toString()+"\n---------------------------------\n";
		//return this.exeStack.toString();
		}
	
}
