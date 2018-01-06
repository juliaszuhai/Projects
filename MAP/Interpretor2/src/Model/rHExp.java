package Model;

public class rHExp extends Exp {
	
	String var;
	
	public rHExp(String s)
	{
		this.var=s;
	}
	

	@Override
	public int eval(MyIDictionary<String, Integer> tbl, MyIDictionary<Integer, Integer> heap) throws Exception {
		Integer loc=tbl.lookup(this.var);
		return heap.lookup(loc);
		
		
	}
	
	public String toString()
	{
		return "rH( "+this.var+" )";
	}

}
