using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter
{
    namespace Model
    {
        class ArithExp:Exp
        {
            Exp e1;
            Exp e2;
            char op;

            public ArithExp(Exp e1,Exp e2,char op)
            {
                this.e1 = e1;
                this.e2 = e2;
                this.op = op;
            }


            public override int eval(MyIDictionary<string, int> tbl)
            {
                switch (this.op)
                {
                    case '+':
                        return e1.eval(tbl) + e2.eval(tbl);
                    case '-':
                        return e1.eval(tbl) - e2.eval(tbl);
                    case '*':
                        return e1.eval(tbl) * e2.eval(tbl);
                    case '/':
                        if (e2.eval(tbl) == 0)
                            throw new Exception("Division by 0 not permitted");
                        else
                            return e1.eval(tbl) / e2.eval(tbl);
                }
                return 0;
            }

            public override string ToString()
            {
                switch (this.op)
                {
                    case '+':
                        return e1.ToString()+ '+' + e2.ToString();
                    case '-':
                        return e1.ToString() + '-' + e2.ToString();
                    case '*':
                        return e1.ToString() + '*' + e2.ToString();
                    case '/':
                        return e1.ToString() + '/' + e2.ToString();
                }
                return " ";
            }
        }
    }
}
