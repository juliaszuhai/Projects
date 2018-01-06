using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter
{
    namespace Model
    {
        class MyList<T> : MyIList<T>
        {
            List<T> list;
            public MyList()
            {
                this.list = new List<T>();
            }
            void MyIList<T>.add(T v)
            {
                this.list.Add(v);
            }

            void MyIList<T>.remove(T v)
            {
                this.list.Remove(v);
            }

            public override string ToString()
            {
                string str = " ";
                foreach(T i in this.list)
                {
                    str = str + i.ToString();
                }
                return str;
            }
        }
    }

}
