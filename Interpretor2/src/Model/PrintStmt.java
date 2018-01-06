package Model;
import Model.IStmt;
public class PrintStmt implements IStmt{
	public Exp exp;
	public PrintStmt(Exp exp)
	{
		this.exp=exp;
	}
	@Override
	public String toString(){
		return "print(" +exp.toString()+")";
	}
	public PrgState execute(PrgState state){
		MyIList<Integer> out=state.getOut();
		try{
		out.add(exp.eval(state.getSymTable(),state.getHeap()));}
		catch(Exception e)
		{
			System.out.println(e);
		}
		
		return state;
	}

}
