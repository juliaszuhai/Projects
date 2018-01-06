package Controller;
import Repository.IRepository;

import java.util.Collection;
import java.util.Map;
import java.util.stream.Collectors;

import Model.*;
public class Controller {
	IRepository repo;
	boolean flag;
	
	public Controller(IRepository r,boolean f){
		this.repo=r;
		this.flag=f;
		
	}
	public IRepository getRepo()
	{
		return this.repo;
	}
	
	Map<Integer,Integer> conservativeGarbageCollector(Collection<Integer> symTableValues,Map<Integer,Integer> heap)
	{
			
	return heap.entrySet().stream().
			filter(e->symTableValues.contains(e.getKey())).
			collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
	}
	
	
	public PrgState oneStep(PrgState state)throws Exception{
		 MyIStack<IStmt> stk=state.getExeStack();
		 if(stk.isEmpty()) 
			 {Exception e=new Exception("ExeStack is empty.");
			 throw e;
			 }
			 
		 IStmt crtStmt = stk.pop();
		 //System.out.println(crtStmt.toString());
		 PrgState ceva=crtStmt.execute(state);
		 if( ceva==null)
		 {
			 throw new Exception("Program has terminated due to illegal open file");
		 }
		 else
		 {
			 return ceva;
		 }
		 }
	
	
	
	
	public void allStep(){
		 PrgState prg = repo.getState(); 
		 try{
			 
			 while(true){
				 oneStep(prg);
				 prg.getHeap().setContent(conservativeGarbageCollector(
						 												prg.getSymTable().getContent().values(),
						 												prg.getHeap().getContent())
						 											  );
				 this.repo.logPrgStateExec();
				 
				 if(this.flag==true)
				 {System.out.println(prg.toString());}
			 			}
			 }
		 	catch(Exception e) {
		 		MyIList<Integer> l=prg.getOut();
		 		System.out.println(l.toString());
			 }
		 finally{
			 prg.getFileTable().getKeySet().stream().forEach(s->new closeRFile(new ConstExp(s)).execute(prg));
		 }
		 
		 
		 }


}
