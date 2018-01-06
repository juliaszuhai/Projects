using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter
{
    namespace Model
    {
        class VarExp:Exp
        {
            string id;

            public VarExp(string id)
            {
                this.id = id;
            }

            public override int eval(MyIDictionary<string, int> tbl)
            {
                return tbl.lookup(this.id);
            }

            public override string ToString()
            {
                return this.id;
            }
        }
    }
}
