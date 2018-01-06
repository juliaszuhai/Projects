package Model;
import Model.IStmt;
public class CompStmt implements IStmt{
	public IStmt first;
	public IStmt second;
	public CompStmt(IStmt f,IStmt s)
	{
		this.first=f;
		this.second=s;
		
	}
	public PrgState execute(PrgState state){
		MyIStack<IStmt> stk=state.getExeStack();
		stk.push(this.second);
		stk.push(this.first);
		return state;
	}
	@Override
	public String toString(){
		return "("+first.toString()+";"+second.toString()+")";
	}
	

}
