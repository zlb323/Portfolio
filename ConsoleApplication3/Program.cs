using Antlr4.Runtime;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//using Antlr4.Runtime.Standard;


namespace ConsoleApplication3
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine();
            try
            {
                AntlrInputStream inputStream = new AntlrInputStream(input);
                cssLexer cl = new cssLexer(inputStream);
                CommonTokenStream cms = new CommonTokenStream(cl);
                cssParser cp = new cssParser(cms);

                cssParser.ExpressionContext expressioncontext = cp.expression();
                CSSVisitor visitor = new CSSVisitor();

                visitor.Visit(expressioncontext);

                Console.ReadKey();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex);
            }
            Console.ReadKey();

        }
    }
}
