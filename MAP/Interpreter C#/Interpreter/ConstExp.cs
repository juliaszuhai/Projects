using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter
{
    namespace Model
    {
        class ConstExp:Exp
        {
            int number;

            public ConstExp(int nr)
            {
                this.number = nr;
            }

            public override int eval(MyIDictionary<string, int> tbl)
            {
                return this.number;
            }

            public override string ToString()
            {
                return this.number.ToString();
            }
        }
    }
}
