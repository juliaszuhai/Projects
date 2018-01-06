using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter
{
    namespace Model
    {
        class IfStmt:IStmt
        {
            Exp exp;
            IStmt thenS;
            IStmt elseS;

            public IfStmt(Exp e, IStmt t,IStmt el)
            {
                this.exp = e;
                this.thenS = t;
                this.elseS = el;
            }

            public override string ToString()
   
            {
                return "IF(" + this.exp.ToString() + ") THEN(" + this.thenS.ToString() + ")ELSE(" + this.elseS.ToString() + ")";
            }

            PrgState IStmt.execute(PrgState state)
            {
                MyIStack<IStmt> exeStack = state.getExeStack();
                if (this.exp.eval(state.getSymTable())==0)
                {
                    exeStack.push(this.thenS);
                }
                else
                {
                    exeStack.push(this.elseS);
                }
                return state;
            }
        }
    }
}
