package Model;

public class BooleanExp extends Exp {
	
	Exp exp1;
	Exp exp2;
	String op;
	
	public BooleanExp(Exp e1,Exp e2,String op)
	{
		this.exp1=e1;
		this.exp2=e2;
		this.op=op;
	}
	
	public int boolToInt(boolean e)
	{
		if(e==true)
			return 1;
		else
			return 0;
	}
	public String toString()
	{
		switch(this.op)
		{
		case "<":
			return this.exp1.toString()+"<"+this.exp2.toString();
		case "<=":
			return this.exp1.toString()+"<="+this.exp2.toString();
		case "==":
			return this.exp1.toString()+"=="+this.exp2.toString();
		case "!=":
			return this.exp1.toString()+"!="+this.exp2.toString();
		case ">":
			return this.exp1.toString()+">"+this.exp2.toString();
		case ">=":
			return this.exp1.toString()+">="+this.exp2.toString();}
		return "";
		
	}
	
	

	@Override
	public int eval(MyIDictionary<String, Integer> tbl, MyIDictionary<Integer, Integer> heap) throws Exception {
		switch(this.op)
		{
		case "<":
			return this.boolToInt(this.exp1.eval(tbl, heap)<this.exp2.eval(tbl, heap));
		case "<=":
			return this.boolToInt(this.exp1.eval(tbl, heap)<=this.exp2.eval(tbl, heap));
		case "==":
			return this.boolToInt(this.exp1.eval(tbl, heap)==this.exp2.eval(tbl, heap));
		case "!=":
			return this.boolToInt(this.exp1.eval(tbl, heap)!=this.exp2.eval(tbl, heap));
		case ">":
			return this.boolToInt(this.exp1.eval(tbl, heap)>this.exp2.eval(tbl, heap));
		case ">=":
			return this.boolToInt(this.exp1.eval(tbl, heap)>=this.exp2.eval(tbl, heap));
			}
		return 0;
	}

}
