using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter
{
    namespace Model
    {
        class AssignStmt : IStmt
        {
            string id;
            Exp exp;

            public AssignStmt(string i,Exp e)
            {
                this.id = i;
                this.exp = e;
            }

            public override string ToString()
            {
                return this.id + " = " + this.exp.ToString();
            }

            PrgState IStmt.execute(PrgState state)
            {
                MyIStack<IStmt> stk = state.getExeStack();
                MyIDictionary<string, int> symTbl = state.getSymTable();
                int val = exp.eval(symTbl);
                if (symTbl.containsKey(this.id)==1)
                {
                    symTbl.update(id, val);
                }
                else
                {
                    symTbl.add(id, val);
                }
                return state;
            }
        }
    }
}
