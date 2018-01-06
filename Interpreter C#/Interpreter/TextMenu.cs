using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter
{
    class TextMenu
    {
        private Dictionary <String, Command> commands;

        public TextMenu() { commands = new Dictionary<string,Command>(); }

        public void addCommand(Command c) { commands.Add(c.getKey(), c); }

        private void printMenu()
        {
            foreach (Command com in this.commands.Values)
            {
                String line =com.getKey()+com.getDescription();
                Console.WriteLine(line);
            }
        }
        public void show()
        {
             
            while (true)
            {
                printMenu();
                Console.WriteLine("Input the option: ");
                String key = Console.ReadLine();
                Command com;
                commands.TryGetValue(key, out com);
                if (com == null)
                {
                    Console.WriteLine("Invalid Option");
                    continue;
                }
                com.execute();
            }
        }
    }
}
