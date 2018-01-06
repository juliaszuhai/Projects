using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter
{
    namespace Model
    {
        class openRFile : IStmt
        {
            string var_file;
            string filename;
            int key = 0;

            public openRFile(string v,string f)
            {
                this.var_file = v;
                this.filename = f;
            }

            public int getNextKey()
            {
                return ++this.key;
            }

            PrgState IStmt.execute(PrgState state)
            {
                //IStmt stmt = state.getExeStack().pop();
                if (state.getFileTable().containsValue(new Tuple<String, StreamReader>(this.filename, null)) == 1)
                {
                    Console.WriteLine("Filename already exists");
                    return null;
                }
                else
                {
                    try
                    {
                        StreamReader br = new StreamReader(this.filename);
                        Tuple<String, StreamReader> t = new Tuple<String, StreamReader>(this.filename, br);
                        int i = this.getNextKey();
                        state.getFileTable().add(i, t);
                        state.getSymTable().add(this.var_file, this.key);
                    }
                    catch (FileNotFoundException e)
                    {

                    }




                    return state;

                }
            }

            public override string ToString()
            {
                    return "open File (" + this.filename+") having variable "+this.var_file+"\n";
             }
        }
    }
}
