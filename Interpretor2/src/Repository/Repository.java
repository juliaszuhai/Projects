package Repository;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

import Model.*;
public class Repository implements IRepository {
	List<PrgState> list;
	int index;
	String  logFilePath;
	public Repository(PrgState s,String path)
	{
		this.list=new ArrayList<PrgState>();
		this.list.add(s);
		this.index=0;
		this.logFilePath=path;
	}
	public PrgState getState(){
		return this.list.get(this.index);
	}
	public void logPrgStateExec() throws Exception
	{
		try{	
		PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(this.logFilePath, true)));
			//System.out.println(this.logFilePath);
			logFile.append(this.list.get(this.index).toString());
			logFile.flush();
			//logFile.close();
		}
		catch(Exception e)
		{
			
		}
	}
}
