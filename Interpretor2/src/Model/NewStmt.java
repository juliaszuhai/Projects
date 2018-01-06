package Model;

public class NewStmt implements IStmt {
	
	String var_name;
	Exp expr;
	static Integer i=0;
	
	public NewStmt(String n,Exp e)
	{
		this.var_name=n;
		this.expr=e;
	}
	
	public Integer getNextLocation()
	{
		return ++this.i;
	}

	@Override
	public PrgState execute(PrgState state) {
		try {
			Integer val=this.expr.eval(state.getSymTable(), state.getHeap());
			Integer loc=this.getNextLocation();
			state.getHeap().add(loc, val);
			if(state.getSymTable().containsKey(this.var_name)==true)
			{
				state.getSymTable().update(this.var_name, loc);
			}
			else
			{
				state.getSymTable().add(this.var_name, loc);
			}
			
			
		} catch (Exception e) {
			
			System.out.println(e);
		}
		return state;
		
		
	}
	
	public String toString()
	{
		return "new( "+this.var_name+","+this.expr.toString()+" )";
	}

}
