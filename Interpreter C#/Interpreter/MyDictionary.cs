using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter
{
    namespace Model
    {
        class MyDictionary<T1, T2> : MyIDictionary<T1, T2>
        {
            Dictionary<T1, T2> dict;
            public MyDictionary()
            {
                this.dict= new Dictionary<T1, T2>();
            }


            void MyIDictionary<T1, T2>.add(T1 key, T2 value)
            {
                this.dict.Add(key, value);
            }

            

            int MyIDictionary<T1, T2>.containsKey(T1 key)
            {
                if(this.dict.ContainsKey(key)==true)
                { return 1;}
                else
                { return 0; }
            }

            int MyIDictionary<T1, T2>.containsValue(T2 value)
            {
                if (this.dict.ContainsValue(value) == true)
                { return 1; }
                else
                { return 0; }
            }

            T2 MyIDictionary<T1, T2>.lookup(T1 key)
            {
                T2 val;
                this.dict.TryGetValue(key, out val);
                return val;
            }

            void MyIDictionary<T1, T2>.remove(T1 key)
            {
                this.dict.Remove(key);
            }

            
            void MyIDictionary<T1,T2>.update(T1 key, T2 value)
            {
                this.dict[key] = value;
            }
            public override string ToString()
            {
                string str="";
                foreach(KeyValuePair < T1, T2 > entry in this.dict)
                {
                    string s1 = entry.Key.ToString();
                    string s2 = entry.Value.ToString();
                    str =str+s1 + "=" + s2+"\n";        
                   
                }
                return str;
            }

            
        }
    }
}
