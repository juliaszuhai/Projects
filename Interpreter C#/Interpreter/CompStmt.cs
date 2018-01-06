using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter
{
    namespace Model
    {
        class CompStmt : IStmt
        {
            IStmt first;
            IStmt second;

            public CompStmt (IStmt f, IStmt s)
            {
                this.first = f;
                this.second = s;
            }

            PrgState IStmt.execute(PrgState state)
            {
                MyIStack<IStmt> stk = state.getExeStack();
                stk.push(this.second);
                stk.push(this.first);
                return state;
            }

            public override string ToString()
            {
                return "(" + this.first.ToString() + " ; " + this.second.ToString() + ")";
            }
        }
    }
}
