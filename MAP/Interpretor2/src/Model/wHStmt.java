package Model;

public class wHStmt implements IStmt {
	
	String var_name;
	Exp expr;
	
	public wHStmt(String s, Exp e)
	{
		this.var_name=s;
		this.expr=e;
	}

	@Override
	public PrgState execute(PrgState state) {
		
		try {
			Integer addr=state.getSymTable().lookup(this.var_name);
			Integer v=this.expr.eval(state.getSymTable(), state.getHeap());
			if(addr!=null)
			{
				state.getHeap().update(addr, v);
			}
			else
			{
				throw new Exception("The variable doesn't exist");
			}
		} catch (Exception e) {
			System.out.println(e);
		}
		
		
		return state;
	}
	
	public String toString()
	{
		return "wH( "+this.var_name+","+this.expr.toString()+" )";
	}

}
