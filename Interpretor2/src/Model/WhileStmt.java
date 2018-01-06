package Model;

public class WhileStmt implements IStmt {
	Exp expr;
	IStmt stmt;
	
	public WhileStmt(Exp e,IStmt s)
	{
		this.expr=e;
		this.stmt=s;
	}

	public String toString()
	{
		return "while ("+this.expr.toString()+")\n {"+this.stmt.toString()+"\n}";
		
	}
	@Override
	public PrgState execute(PrgState state) {
		try {
			if(this.expr.eval(state.getSymTable(),state.getHeap())!=0)
			{
				state.getExeStack().push(new WhileStmt(this.expr,this.stmt));
				state.getExeStack().push(this.stmt);
			}
			
		} catch (Exception e) {
			System.out.println(e);
		}
		return state;
	}

}
