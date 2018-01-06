package View;

import java.io.BufferedReader;

import Controller.Controller;
import Model.*;
import Repository.Repository;
public class Interpreter {

	public static void main(String[] args) {
		 
		IStmt ex1=new CompStmt(
				new AssignStmt("v",new ConstExp(2)),
				new PrintStmt(new VarExp("v")));
		
		MyIStack<IStmt> exeStack = new MyStack<IStmt>();
    	MyIDictionary<String, Integer> symTable = new SymTable<String, Integer>();
    	MyIList<Integer> out = new MyList<Integer>();
    	MyIDictionary<Integer,Tuple<String,BufferedReader>> fileTable= new FileTable<Integer,Tuple<String,BufferedReader>>();
    	MyIDictionary<Integer,Integer> heap= new Heap<Integer,Integer>();
    	PrgState prg = new PrgState(exeStack,symTable,out,fileTable,heap);
		
    	exeStack.push(ex1);
    	
    	Repository repo = new Repository(prg,"text.txt");
        
        Controller ctrl = new Controller(repo,true);
        
        IStmt ex4=new CompStmt(
				new CompStmt(
							new OpenRFile("var_f","exemplu.txt"),
							new readFile(new VarExp("var_f"),"var_c")
							),
				new CompStmt(
							//new readFile(new ArithExp('+',new VarExp("var_f"),new ConstExp(2)),"var_x"),
							new readFile(new VarExp("var_f"),"var_x"),
							new closeRFile(new VarExp("var_f"))
							)
				);
        MyIStack<IStmt> exeStack1 = new MyStack<IStmt>();
    	MyIDictionary<String, Integer> symTable1 = new SymTable<String, Integer>();
    	MyIList<Integer> out1 = new MyList<Integer>();
    	MyIDictionary<Integer,Tuple<String,BufferedReader>> fileTable1= new FileTable<Integer,Tuple<String,BufferedReader>>();
    	MyIDictionary<Integer,Integer> heap1= new Heap<Integer,Integer>();
    	PrgState prg1 = new PrgState(exeStack1,symTable1,out1,fileTable1,heap1);
    	exeStack1.push(ex4);
    	
    	Repository repo1 = new Repository(prg1,"text.txt");
        
        Controller ctrl1 = new Controller(repo1,true);
        
        

        IStmt ex2= new CompStmt(
        		new CompStmt(new AssignStmt("v",new ConstExp(10)), new NewStmt("v",new ConstExp(20))),
        		new CompStmt(new NewStmt("a",new ConstExp(22)), new PrintStmt(new VarExp("v"))));
        		
        MyIStack<IStmt> exeStack2 = new MyStack<IStmt>();
    	MyIDictionary<String, Integer> symTable2 = new SymTable<String, Integer>();
    	MyIList<Integer> out2 = new MyList<Integer>();
    	MyIDictionary<Integer,Tuple<String,BufferedReader>> fileTable2= new FileTable<Integer,Tuple<String,BufferedReader>>();
    	MyIDictionary<Integer,Integer> heap2= new Heap<Integer,Integer>();
    	PrgState prg2 = new PrgState(exeStack2,symTable2,out2,fileTable2,heap2);
    	exeStack2.push(ex2);
    	
    	Repository repo2 = new Repository(prg2,"text.txt");
        
        Controller ctrl2 = new Controller(repo2,true);
        
        
        IStmt ex3=new CompStmt(
        		new CompStmt(new AssignStmt("v",new ConstExp(10)), new NewStmt("v",new ConstExp(20))),
        		new CompStmt(new NewStmt("a",new ConstExp(22)), new PrintStmt(new ArithExp('+',new ConstExp(100),new rHExp("v")))));
        		
        MyIStack<IStmt> exeStack3 = new MyStack<IStmt>();
    	MyIDictionary<String, Integer> symTable3 = new SymTable<String, Integer>();
    	MyIList<Integer> out3 = new MyList<Integer>();
    	MyIDictionary<Integer,Tuple<String,BufferedReader>> fileTable3= new FileTable<Integer,Tuple<String,BufferedReader>>();
    	MyIDictionary<Integer,Integer> heap3= new Heap<Integer,Integer>();
    	PrgState prg3 = new PrgState(exeStack3,symTable3,out3,fileTable3,heap3);
    	exeStack3.push(ex3);
    	
    	Repository repo3 = new Repository(prg3,"text.txt");
        
        Controller ctrl3 = new Controller(repo3,true);
        
        IStmt ex5=new CompStmt(
				        		new CompStmt(new AssignStmt("v",new ConstExp(10)), new NewStmt("v",new ConstExp(20))),
				        		new CompStmt(
				        		new CompStmt(new NewStmt("a",new ConstExp(22)), new wHStmt("a", new ConstExp(30))),
				        		new CompStmt(new PrintStmt(new VarExp("a")),new PrintStmt(new rHExp("a"))))
        					);
        		
        MyIStack<IStmt> exeStack5 = new MyStack<IStmt>();
    	MyIDictionary<String, Integer> symTable5 = new SymTable<String, Integer>();
    	MyIList<Integer> out5 = new MyList<Integer>();
    	MyIDictionary<Integer,Tuple<String,BufferedReader>> fileTable5= new FileTable<Integer,Tuple<String,BufferedReader>>();
    	MyIDictionary<Integer,Integer> heap5= new Heap<Integer,Integer>();
    	PrgState prg5 = new PrgState(exeStack5,symTable5,out5,fileTable5,heap5);
    	exeStack5.push(ex5);
    	
    	Repository repo5 = new Repository(prg5,"text.txt");
        
        Controller ctrl5 = new Controller(repo5,true);
        
        IStmt ex6= new CompStmt( new AssignStmt("v",new ConstExp(10)),
        			new CompStmt(new NewStmt("v",new ConstExp(20)),new CompStmt(new NewStmt("a",new ConstExp(22)),new CompStmt(new wHStmt("a",new ConstExp(30)),new CompStmt(new PrintStmt(new VarExp("a")),new CompStmt(new PrintStmt(new rHExp("a")),new AssignStmt("a",new ConstExp(0))))))));
        MyIStack<IStmt> exeStack6 = new MyStack<IStmt>();
    	MyIDictionary<String, Integer> symTable6 = new SymTable<String, Integer>();
    	MyIList<Integer> out6 = new MyList<Integer>();
    	MyIDictionary<Integer,Tuple<String,BufferedReader>> fileTable6= new FileTable<Integer,Tuple<String,BufferedReader>>();
    	MyIDictionary<Integer,Integer> heap6= new Heap<Integer,Integer>();
    	PrgState prg6 = new PrgState(exeStack6,symTable6,out6,fileTable6,heap6);
    	exeStack6.push(ex6);
    	
    	Repository repo6 = new Repository(prg6,"text.txt");
        
        Controller ctrl6 = new Controller(repo6,true);
        
        IStmt ex7= new CompStmt(
					new CompStmt(
								new AssignStmt("v",new ArithExp('+',new ConstExp(10),new BooleanExp(new ConstExp(2),new ConstExp(6),"<"))),
								new PrintStmt(new VarExp("v"))
								),
					new CompStmt(
								new AssignStmt("a",new BooleanExp(new ArithExp('+',new ConstExp(10),new ConstExp(2)),new ConstExp(6),"<")),
								new PrintStmt(new VarExp("a"))
								)
				 	);
    MyIStack<IStmt> exeStack7 = new MyStack<IStmt>();
	MyIDictionary<String, Integer> symTable7 = new SymTable<String, Integer>();
	MyIList<Integer> out7 = new MyList<Integer>();
	MyIDictionary<Integer,Tuple<String,BufferedReader>> fileTable7= new FileTable<Integer,Tuple<String,BufferedReader>>();
	MyIDictionary<Integer,Integer> heap7= new Heap<Integer,Integer>();
	PrgState prg7 = new PrgState(exeStack7,symTable7,out7,fileTable7,heap7);
	exeStack7.push(ex7);
	
	Repository repo7 = new Repository(prg7,"text.txt");
    
    Controller ctrl7 = new Controller(repo7,true);
    
    IStmt ex8=new CompStmt(new AssignStmt("v",new ConstExp(6)),
    		new CompStmt(new WhileStmt(new ArithExp('-',new VarExp("v"),new ConstExp(4)),
    		new CompStmt(new PrintStmt(new VarExp("v")),new AssignStmt("v",new ArithExp('-',new VarExp("v"),new ConstExp(1))))),new PrintStmt(new VarExp("v"))));
    
    MyIStack<IStmt> exeStack8 = new MyStack<IStmt>();
   	MyIDictionary<String, Integer> symTable8 = new SymTable<String, Integer>();
   	MyIList<Integer> out8 = new MyList<Integer>();
   	MyIDictionary<Integer,Tuple<String,BufferedReader>> fileTable8= new FileTable<Integer,Tuple<String,BufferedReader>>();
   	MyIDictionary<Integer,Integer> heap8= new Heap<Integer,Integer>();
   	PrgState prg8 = new PrgState(exeStack8,symTable8,out8,fileTable8,heap8);
   	exeStack8.push(ex8);
   	
   	Repository repo8 = new Repository(prg8,"text.txt");
       
       Controller ctrl8 = new Controller(repo8,true);
    
    
        TextMenu menu=new TextMenu();
        menu.addCommand(new ExitCommand("0","exit"));
        menu.addCommand(new RunExample("1",ex1.toString(),ctrl));
        menu.addCommand(new RunExample("2",ex4.toString(),ctrl1));
        menu.addCommand(new RunExample("3",ex2.toString(),ctrl2));
        menu.addCommand(new RunExample("4",ex3.toString(),ctrl3));
        menu.addCommand(new RunExample("5",ex5.toString(),ctrl5));
        menu.addCommand(new RunExample("6",ex6.toString(),ctrl6));
        menu.addCommand(new RunExample("7",ex7.toString(),ctrl7));
        menu.addCommand(new RunExample("8",ex8.toString(),ctrl8));
        menu.show();
      
    	

	}

}
