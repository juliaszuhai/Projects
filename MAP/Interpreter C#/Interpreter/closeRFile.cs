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
       
        class closeRFile : IStmt
        {
            Exp exp_file_id;

            public closeRFile(Exp e)
            {
                this.exp_file_id = e;
            }

            PrgState IStmt.execute(PrgState state)
            {
                //IStmt stmt = state.getExeStack().pop();
                int val = this.exp_file_id.eval(state.getSymTable());
                Tuple<String, StreamReader> t = state.getFileTable().lookup(val);
                if (t == null)
                {
                    return null;
                }
                else
                {
                    t.Item2.Close();
                    state.getFileTable().remove(val);
                }
                return state;
            }

            public override string ToString()
            {
                return "close file :" + this.exp_file_id.ToString() + ") \n";
            }
        }
    }
}
