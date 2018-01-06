package Model;
import Model.IStmt;
public class AssignStmt implements IStmt{
	public String id;
	public Exp exp;
	public AssignStmt(String id,Exp exp)
	{
		this.id=id;
		this.exp=exp;
	}
	@Override
	public String toString(){
		return id+"="+exp.toString();
	}
	public PrgState execute(PrgState state) 
	{
		//MyIStack<IStmt>stk=state.getExeStack();
		MyIDictionary<String,Integer>symTbl=state.getSymTable();
		MyIDictionary<Integer,Integer>heap=state.getHeap();
		try{
			int val=exp.eval(symTbl,heap);
			if (symTbl.containsKey(id) )
			{
				symTbl.update(id, val);
			}
		 else 
			 {
			 	symTbl.add(id,val);
			 }
		
		}
		catch(Exception e)
		{
			System.out.println(e);
			
		}
		return state;
	
	}
	
}
