using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Antlr4.Runtime.Misc;
using Antlr4.Runtime.Tree;
namespace ConsoleApplication3
{
    public class CSSVisitor : cssBaseVisitor<object>
    {        
        public override object VisitWord(cssParser.WordContext context)
        {
            node knew = new node("Word", context.WORD().GetText());
            return knew;
        }
        public override object VisitGroupassign([NotNull] cssParser.GroupassignContext context)
        {
            group knew = new group("Group", context.WORD(0).GetText());
            int j = 1;
            while(context.WORD(j) != null)
            {
                knew.addNames(new node("word", context.WORD(j).GetText()));
                j++;
            }
            int i = 0;
            while (context.expression(i) != null)
            {
                knew.addNode((command)Visit(context.expression(i)));
                i++;
            }
            knew.print();
            return knew;
        }

       /* public override object VisitGroupadd([NotNull] cssParser.GroupaddContext context)
        {
            group knew = new group("group", context.WORD(0).GetText());
            int i = 1;
            while (context.WORD(i) != null)
            {
                
            }
            return base.VisitGroupadd(context);
        }

        public override object VisitGroup([NotNull] cssParser.GroupContext context)
        {
            group knew = new group("Group", context.WORD().GetText());
            
            return knew;
        }*/
        
        public override object VisitCommand([NotNull] cssParser.CommandContext context)
        {
            List<string> temp = new List<string>();
            int i = 1;
            while (context.WORD(i) != null)
            {
                temp.Add(context.WORD(i).GetText());
                i++;
            }
            command knew = new command("command", context.WORD(0).GetText(), temp);
            knew.get();
            return knew;
        }
        /*public override object VisitNum(CPGrammarParser.NumContext context)
        {
            return double.Parse(context.NUMBER().GetText());
        }
        public override object VisitParenth(CalculatorParser.ParenthContext context)
        {
            return Visit(context.expression());
        }
        public override object VisitMult(CalculatorParser.MultContext context)
        {
            return ((double)Visit(context.expression(0)) * (double)Visit(context.expression(1)));
        }
        public override object VisitDiv(CalculatorParser.DivContext context)
        {
            return ((double)Visit(context.expression(0)) / (double)Visit(context.expression(1)));

        }
        public override object VisitAdd(CalculatorParser.AddContext context)
        {
            return ((double)Visit(context.expression(0)) + (double)Visit(context.expression(1)));
        }
        public override object VisitSub(CalculatorParser.SubContext context)
        {
            return ((double)Visit(context.expression(0)) - (double)Visit(context.expression(1)));
        }*/
    }
}
