package Model;

public class ConstExp extends Exp {
	Integer n;
	public ConstExp(Integer i)
	{
		this.n=i;
		
	}

	@Override
	public int eval(MyIDictionary<String, Integer> tbl,MyIDictionary<Integer,Integer> heap) throws Exception {
		return this.n;
	}
	@Override
	public String toString()
	{
		return this.n.toString();
	}
	

}
