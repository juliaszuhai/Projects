using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Interpreter.Repo;
using Interpreter.Model;

namespace Interpreter
{
    namespace Ctrl
    {
        class Controller
        {
            IRepository repo;
            public Controller(IRepository r)
            {
                this.repo = r;
            }

            public PrgState oneStep(PrgState state)
            {
                MyIStack<IStmt> stk = state.getExeStack();
                if (stk.isEmpty())
                {
                    throw new Exception(" No more instructions");
                }
                IStmt crtStmt = stk.pop();
                return crtStmt.execute(state);

            }
            public void allStep()
            {
                PrgState prg = repo.getCrtPrg(); // repo is the controller field of type
                                                 // MyRepoInterface
                try
                {
                    while (true)
                    {
                        oneStep(prg);

                        this.repo.logPrgStateExec();

                        Console.WriteLine(prg.ToString());
                    }
                }
                catch (Exception e) {

                    //Console.WriteLine(e);
                }
            }
        }

        }
    }

