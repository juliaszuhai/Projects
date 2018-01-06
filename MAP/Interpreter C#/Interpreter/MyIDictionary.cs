using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter
{
    namespace Model
    {
        interface MyIDictionary<T1,T2>
        {
            void add(T1 key, T2 value);
            int containsKey(T1 key);
            int containsValue(T2 value);
            void remove(T1 key);
            
            void update(T1 key, T2 value);
            T2 lookup(T1 key);
           
        }
    }
}
