using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Interpreter.Model;

namespace Interpreter
{
    namespace Repo
    {
        
        class Repository:IRepository
        {
            List<PrgState> lst;
            int index;
            string pathFile;

            public Repository(PrgState p,string path)
            {
                this.lst = new List<PrgState>();
                this.lst.Add(p);
                this.index = 0;
                this.pathFile = path;
            }

            public List<PrgState> Programs
            {
                set
                {
                    this.lst = value;
                    this.index = 0;
                }
                get { return this.lst; }

            }

            PrgState IRepository.getCrtPrg()
            {
                return this.lst.ElementAt(this.index);
            }

            void IRepository.logPrgStateExec()
            {
                using (System.IO.StreamWriter file =
            new System.IO.StreamWriter(this.pathFile,true))
                {
                    foreach (PrgState program in this.lst)
                    {
                        file.WriteLine(program.ToString());
                        file.WriteLine("\n----------------------------------------------------------\n");
                       
                    }
                }

            }
        }
    }
}
