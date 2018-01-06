package View;
import Model.*;
import Repository.*;

import java.io.BufferedReader;
import java.util.Scanner;

import Controller.*;
public class Main {

	public static void main(String[] args) {
			MyIStack<IStmt> exeStack = new MyStack<IStmt>();
	    	MyIDictionary<String, Integer> symTable = new SymTable<String, Integer>();
	    	MyIList<Integer> out = new MyList<Integer>();
	    	MyIDictionary<Integer,Tuple<String,BufferedReader>> fileTable= new FileTable<Integer,Tuple<String,BufferedReader>>();
	    	MyIDictionary<Integer,Integer> heap= new Heap<Integer,Integer>();
	    	PrgState prg = new PrgState(exeStack,symTable,out,fileTable,heap);
    	//v=90;print(v)
        /*IStmt ex1 = new CompStmt(
          							new AssignStmt("v",new ConstExp(90)), 
          							new PrintStmt(new VarExp("v")));
    	exeStack.push(ex1);*/
       	//a=2-2;(If a Then v=2 Else v=3); Print(v)
    	/*IStmt ex3 = new CompStmt(
    							new AssignStmt("a", new ArithExp('-',new ConstExp(2), new ConstExp(2))),
    							new CompStmt(
    										new IfStmt(new VarExp("a"),new AssignStmt("v",new ConstExp(2)), 
    												new AssignStmt("v", new ConstExp(3))), new PrintStmt(new VarExp("v"))
    										)
    							);*/
    	//a=2+3*5;b=a+1;Print(b)
    	/*System.out.println("Enter the filename: ");
    	Scanner input=new Scanner(System.in);
    	String filename = input.nextLine();*/
    	/*IStmt ex2 = new CompStmt(
    							new AssignStmt("a", new ArithExp('+',new ConstExp(2),new ArithExp('*',new ConstExp(3), new ConstExp(5)))),
    							new CompStmt(
    										new AssignStmt("b",new ArithExp('+',new VarExp("a"), new ConstExp(1))),
    										new PrintStmt(new VarExp("b"))
    										)
    							);*/
    	IStmt ex4=new CompStmt(
    							new CompStmt(
    										new OpenRFile("var_f","exemplu.txt"),
    										new readFile(new VarExp("var_f"),"var_c")
    										),
    							new CompStmt(
    										new readFile(new ArithExp('+',new VarExp("var_f"),new ConstExp(2)),"var_x"),
    										//new readFile(new VarExp("var_f"),"var_x"),
    										new closeRFile(new VarExp("var_f"))
    										)
    							);
        exeStack.push(ex4);
    	
    	Repository repo = new Repository(prg,"text.txt");
        
        Controller ctrl = new Controller(repo,true);
        
        ctrl.allStep();
        

	}

}
