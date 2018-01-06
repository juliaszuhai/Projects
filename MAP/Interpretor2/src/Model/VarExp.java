package Model;

public class VarExp extends Exp {

	String id;
	
	
	public VarExp(String i)
	{
		this.id=i;
		
	}
	
	@Override
	public int eval(MyIDictionary<String, Integer> tbl,MyIDictionary<Integer,Integer> heap) throws Exception {
		return tbl.lookup(id);
	}
	@Override
	public String toString(){
		return id;
	}

}
