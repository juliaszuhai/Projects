package Model;
import java.io.BufferedReader;
public class readFile implements IStmt {
	public Exp exp_file_id;
	public String var_name;
	
	public readFile(Exp e,String s)
	{
		this.exp_file_id=e;
		this.var_name=s;
	}
	
	public Exp getExpFileId()
	{
		return this.exp_file_id;
	}
	
	public String getVarName()
	{
		return this.var_name;
	}
	public String toString()
	{
		return "Read file( "+this.var_name+" )";
	}

	@Override
	public PrgState execute(PrgState state) {
		try {
			Integer i=0;
			Integer val=this.exp_file_id.eval(state.getSymTable(),state.getHeap());
			Tuple<String, BufferedReader> b=state.fileTable.lookup(val);
			if( b==null)
			{
				return null;
			}
			else
			{
				String line =b.descriptor.readLine();
				if (line!=null)
				{
					i=Integer.parseInt(line);
				}
				
				if(state.symTable.containsKey(this.var_name)==true)
				{
					state.symTable.update(this.var_name, i);
				}
				else
				{
				state.symTable.add(this.var_name, i);
				}
			}
				
		} catch (Exception e) {
			e.printStackTrace();
			System.out.println(e);
		}
		
		return state;
	}

}
