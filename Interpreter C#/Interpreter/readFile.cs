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
        class readFile : IStmt
        {
            Exp exp_file_id;
            string var_name;

            public readFile(Exp e, string v)
            {
                this.exp_file_id = e;
                this.var_name = v;

            }

            PrgState IStmt.execute(PrgState state)
            {
                int i = 0;
                //IStmt stmt = state.getExeStack().pop();
                int val = this.exp_file_id.eval(state.getSymTable());
                Tuple<String, StreamReader> b = state.getFileTable().lookup(val);
                if (b == null)
                {
                    return null;
                }
                else
                {
                    String line = b.Item2.ReadLine();
                    if (line != null)
                    {
                        i = int.Parse(line);
                    }

                    if (state.getSymTable().containsKey(this.var_name) == 1)
                    {
                        state.getSymTable().update(this.var_name, i);
                    }
                    else
                    {
                        state.getSymTable().add(this.var_name, i);
                    }
                }

                return state;
            }



            public override string ToString()
            {
                return "read file (" + this.var_name + ") \n";
            }
        }
    }

}
