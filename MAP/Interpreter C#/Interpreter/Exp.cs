using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter
{
    namespace Model
    {
        abstract class Exp
        {
            public abstract int eval(MyIDictionary<String, int> tbl);
            public abstract string ToString();
        }
    }

}
