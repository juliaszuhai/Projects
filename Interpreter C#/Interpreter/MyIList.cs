using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter
{
    namespace Model
    {
        interface MyIList<T>
        {
            void add(T v);
            void remove(T v);
            
        }
    }
}
