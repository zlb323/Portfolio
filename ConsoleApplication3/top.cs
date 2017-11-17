using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    class top
    {
        //creating states;
        //possibly adding handling functions for each type that direct what happens;
        private static top instance = null;
        private static readonly object padlock = new object();
        private Dictionary<string, node> dict = new Dictionary<string, node>();

        public top()
        {
        }

        public static top get()
        {
            lock (padlock)
            {
                if(instance == null)
                {
                    instance = new top();
                }
            }
            return instance;
        }

        public void addKeyword(string word, node n)
        {
            try
            {
                dict.Add(word, n);
            }
            catch
            {
                Console.WriteLine("KeyWord already used");
            }
        }

        public node getNode(string key, node n)
        {
            if (dict.TryGetValue(key, out n))
                return n;
            else return null;
        }
    }

    class node
    {
        private string type;
        private string word;

        public string getT()
        {
            return type;
        }

        public string get()
        {
            return word;
        }

        public node(string _type, string _word)
        {
            type = _type;
            word = _word;
            top p = top.get();
            p.addKeyword(word, this);
            //Console.WriteLine(this.get());
        }
        public virtual string print()
        {
            return word;
        }

    }
    
    class group : node
    {
        List<node> nodes = new List<node>();
        List<node> names = new List<node>();
        public group(string _type, string _word)
            : base(_type, _word)
        {
        }

        public void addNode(node n)
        {
            nodes.Add(n);
        }

        public void addNames(node n)
        {
            //Console.WriteLine(n.get());
            names.Add(n);
        }

        public void print()
        {
            foreach (node nam in names)
            {
                if(nam != null) Console.WriteLine(nam.get() + "\n{");
                foreach (node nod in nodes)
                {
                    Console.WriteLine(nod.print());
                }
                Console.WriteLine("}");
            }
        }
    }

    class command : node
    {
        List<string> values = new List<string>();
        string attribute;
        public command(string _type, string _text, List<string> _values)
            :base(_type, _text)
        {
            attribute = _text;
            values = _values;
        }

        public override string print()
        { 
            string temp;
            temp = attribute + ":";
            foreach (string a in values)
            {
                temp = temp + " " + a;
            }
            return temp;
        }
    }
}
