using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter
{
    namespace Model
    {
        interface IStmt
        {
            
            PrgState execute(PrgState state);

        }
    }
}
