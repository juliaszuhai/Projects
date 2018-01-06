package Model;

public abstract class Exp {
	
	public abstract int eval(MyIDictionary<String,Integer> tbl,MyIDictionary<Integer,Integer> heap)throws Exception;
	

}
