using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter
{
    namespace Model
    {
        class MyStack<T> : MyIStack<T>
        {
            Stack<T> stack;

          public MyStack()
            {
                this.stack = new Stack<T>();
            }

            T MyIStack<T>.pop()
            {
                return this.stack.Pop();
            }

            void MyIStack<T>.push(T v)
            {
                this.stack.Push(v);
            }

            public override string ToString()
            {
                string str=" ";
                foreach(T i in this.stack)
                {
                    str = str + i.ToString();
                }
                return str;
            }

            Boolean MyIStack<T>.isEmpty()
            {
                return this.stack.Count() == 0;
            }
        }
    }
}
