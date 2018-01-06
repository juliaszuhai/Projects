package Model;

public class ArithExp extends Exp {

	Exp e1;
	Exp e2;
	char op;
	
	public ArithExp(char o,Exp a1,Exp a2)
	{
		this.e1=a1;
		this.e2=a2;
		this.op=o;
	}
	@Override
	public int eval(MyIDictionary<String, Integer> tbl,MyIDictionary<Integer,Integer> heap) throws Exception {
		switch(this.op)
		{
		case '+':
			return e1.eval(tbl,heap)+e2.eval(tbl,heap);
		case '-':
			return e1.eval(tbl,heap)-e2.eval(tbl,heap);
		case '*':
			return e1.eval(tbl,heap)*e2.eval(tbl,heap);
		case '/':
			if(e2.eval(tbl,heap)==0)
				throw new Exception("Division by 0 not permitted");
			else
				return e1.eval(tbl,heap)/e2.eval(tbl,heap);
			}
		return 0;
	}
	public String toString(){
		switch(this.op)
		{
		case '+':
			return e1.toString()+'+'+e2.toString();
		case '-':
			return e1.toString()+'-'+e2.toString();
		case '*':
			return e1.toString()+'*'+e2.toString();
		case '/':
			return e1.toString()+'/'+e2.toString();
		}
		return " ";
	}

}
