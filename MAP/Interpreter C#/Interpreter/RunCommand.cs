using Interpreter.Ctrl;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter
{
    class RunCommand:Command
    {

        private Controller ctr;


        public RunCommand(String key, String desc, Controller ctr):base(key,desc)
        {
            
            this.ctr = ctr;
        }
       
        public override void execute()
        {
            try
            {
                ctr.allStep();
            }
            catch (Exception e) { }

            }

        }
    }
