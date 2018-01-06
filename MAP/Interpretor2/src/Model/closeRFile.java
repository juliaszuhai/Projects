package Model;

import java.io.BufferedReader;

public class closeRFile implements IStmt {
	
	public Exp exp_file_id;
	
	public closeRFile(Exp e)
	{
		this.exp_file_id=e;
	}
	public String toString()
	{
		return "Close file ("+this.exp_file_id.toString()+" )";
	}

	public Exp getExp()
	{
		return this.exp_file_id;
	}
	
	@Override
	public PrgState execute(PrgState state) {
		try {
			Integer val=this.exp_file_id.eval(state.symTable,state.heap);
			Tuple<String,BufferedReader> t=state.fileTable.lookup(val);
			if(t==null)
			{
				return null;
			}
			else
			{
				t.descriptor.close();
				state.fileTable.remove(val);
			}
		} catch (Exception e) {
			System.out.println(e);
			e.printStackTrace();
		}
		return state;
		
	}

}
