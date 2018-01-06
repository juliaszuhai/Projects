package Model;

public class IfStmt implements IStmt {
	Exp exp;
	IStmt thenS;
	IStmt elseS;
	public IfStmt(Exp e,IStmt t,IStmt el)
	{
		this.exp=e;
		this.thenS=t;
		this.elseS=el;
	}
	@Override
	public String toString(){
		return "IF ("+exp.toString()+") THEN ("+thenS.toString()+") Else ("+elseS.toString()+")";
	}
	@Override
	public PrgState execute(PrgState state) {
		MyIStack<IStmt> exe=state.getExeStack();
		
		try {
			if(exp.eval(state.getSymTable(),state.getHeap())==0)
			{
				exe.push(elseS);
			}
			else
			{
				exe.push(thenS);
			}
		} catch (Exception e) {
			
		}
		return state;
	}

}
