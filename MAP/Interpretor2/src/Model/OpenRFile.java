package Model;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;

public class OpenRFile implements IStmt {
	
	public String var_file_id;
	public String filename;
	public static Integer key=0;
	
	public OpenRFile(String s1,String s2)
	{
		this.var_file_id=s1;
		this.filename=s2;
		
	}
	public Integer getNextKey()
	{
		return ++this.key;
	}
	public String getFilename()
	{
		return this.filename;
	}
	public String toString()
	{
		return "Open file( "+this.filename+" )";
	}
	@Override
	public PrgState execute(PrgState state)  {
		if(state.fileTable.containsValue(new Tuple<String,BufferedReader>(this.filename,null))==true)
		{
			System.out.println("Filename already exists");
			return null;
		}
		else
		{
			try {
				BufferedReader br=new BufferedReader(new FileReader(this.filename));
				Tuple<String,BufferedReader> t=new Tuple<String,BufferedReader>(this.filename,br);
				Integer i=this.getNextKey();
				state.fileTable.add(i, t);
				state.symTable.add(this.var_file_id, this.key);
			} catch (FileNotFoundException e) {
				e.printStackTrace();
				System.out.println(e);
			}
		}
		return state;
	}

}
