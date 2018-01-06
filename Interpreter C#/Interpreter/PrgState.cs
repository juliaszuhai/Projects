using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Interpreter
{
    namespace Model
    {
        class PrgState
        {
            MyIStack<IStmt> exeStack;
            MyIDictionary<String, int> symTable;
            MyIList<int> outList;
            MyIDictionary<int, Tuple<string,StreamReader>> fileTable;
            IStmt originalProgram;

            public PrgState(MyIStack<IStmt> stk, MyIDictionary<String, int> symtbl, MyIList<int> ot, MyIDictionary<int, Tuple<string, StreamReader>> fileTable)
            {
                this.exeStack = stk;
                this.symTable = symtbl;
                this.outList = ot;
                this.fileTable = fileTable;
            }
            public MyIStack<IStmt> getExeStack()
            {
                return this.exeStack;
            }
            public MyIDictionary<String, int> getSymTable()
            {
                return this.symTable;
            }
            public MyIList<int> getOut()
            {
                return this.outList;
            }
            public MyIDictionary<int, Tuple<string, StreamReader>> getFileTable()
            {
                return this.fileTable;
            }
            public override  String ToString()
            {
                return "\nExeStack:\n" + this.exeStack.ToString() + "\n-----------------------\n" +
                        "\nSymTable:\n" + this.symTable.ToString() + "\n------------------------\n" +
                        "Out:\n" + this.outList.ToString() + "\n------------------------\n" +
                        "FileTable:\n" + this.fileTable.ToString() + "\n-----------------------------\n";

            }


        }
    }
}
