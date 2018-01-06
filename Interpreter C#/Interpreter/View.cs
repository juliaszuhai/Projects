using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Interpreter.Model;
using Interpreter.Repo;
using Interpreter.Ctrl;
using System.Collections;
using System.IO;

namespace Interpreter
{
    class View
    {
        public static int Main (String[] args)
        {
            
            IStmt ex1 = new CompStmt(
            new CompStmt(
                        new openRFile("var_f", "D:/Programming/C,C++/Interpreter/Interpreter/text1.txt"),
                        new readFile(new VarExp("var_f"), "var_c")
                        ),
            new CompStmt(
                        //new readFile(new ArithExp(new VarExp("var_f"), new ConstExp(2),'+'), "var_x"),
                        new readFile(new VarExp("var_f"),"var_x"),
                        new closeRFile(new VarExp("var_f"))
                        )
            );

            MyIStack<IStmt> exeStack1 = new MyStack<IStmt>();
            MyIDictionary<String, int> symTable1 = new MyDictionary<String, int>();
            MyIList < int > outList1 = new MyList<int>();
            MyIDictionary<int, Tuple<string, StreamReader>> fileTable1 = new MyDictionary<int, Tuple<string, StreamReader>>();
            PrgState prg1 = new PrgState(exeStack1, symTable1, outList1,fileTable1);

            exeStack1.push(ex1);
            Repository repo1 = new Repository(prg1, "D:/Programming/C,C++/Interpreter/Interpreter/text.txt");

            Controller ctrl1 = new Controller(repo1);


            ///////////////////////////////////////////////////////////////////////////////////////////
            IStmt ex2 = new CompStmt(
                    new AssignStmt("v", new ConstExp(2)),
                    new PrintStmt(new VarExp("v")));
            MyIStack<IStmt> exeStack2 = new MyStack<IStmt>();
            MyIDictionary<String, int> symTable2 = new MyDictionary<String, int>();
            MyIList<int> outList2 = new MyList<int>();
            MyIDictionary<int, Tuple<string, StreamReader>> fileTable2 = new MyDictionary<int, Tuple<string, StreamReader>>();
            PrgState prg2 = new PrgState(exeStack2, symTable2, outList2, fileTable2);

            exeStack2.push(ex2);
            Repository repo2 = new Repository(prg2, "D:/Programming/C,C++/Interpreter/Interpreter/text.txt");

            Controller ctrl2 = new Controller(repo2);


            TextMenu menu = new TextMenu();
            menu.addCommand(new ExitCommand("0", "exit"));
            menu.addCommand(new RunCommand("1", ex1.ToString(), ctrl1));
            menu.addCommand(new RunCommand("2", ex2.ToString(), ctrl2));
            menu.show();






            Console.ReadKey(true);
            return 0;
        }

    }
}
