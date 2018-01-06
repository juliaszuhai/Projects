using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter
{
    namespace Model
    {
        class PrintStmt : IStmt
        {
            Exp exp;

            public PrintStmt(Exp e)
            {
                this.exp = e;
            }

            PrgState IStmt.execute(PrgState state)
            {
                MyIList<int> output = state.getOut();
                output.add(this.exp.eval(state.getSymTable()));
                return state;
            }

            public override string ToString()
            {
                return "print (" + this.exp.ToString() + ")";
            }
        }
    }
}
