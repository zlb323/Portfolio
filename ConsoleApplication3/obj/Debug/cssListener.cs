//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     ANTLR Version: 4.6.4
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from C:\Users\zach1\Desktop\School\classes\C#\ConsoleApplication3\ConsoleApplication3\css.g4 by ANTLR 4.6.4

// Unreachable code detected
#pragma warning disable 0162
// The variable '...' is assigned but its value is never used
#pragma warning disable 0219
// Missing XML comment for publicly visible type or member '...'
#pragma warning disable 1591
// Ambiguous reference in cref attribute
#pragma warning disable 419

namespace ConsoleApplication3 {
using Antlr4.Runtime.Misc;
using IParseTreeListener = Antlr4.Runtime.Tree.IParseTreeListener;
using IToken = Antlr4.Runtime.IToken;

/// <summary>
/// This interface defines a complete listener for a parse tree produced by
/// <see cref="cssParser"/>.
/// </summary>
[System.CodeDom.Compiler.GeneratedCode("ANTLR", "4.6.4")]
[System.CLSCompliant(false)]
public interface IcssListener : IParseTreeListener {
	/// <summary>
	/// Enter a parse tree produced by the <c>groupassign</c>
	/// labeled alternative in <see cref="cssParser.expression"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void EnterGroupassign([NotNull] cssParser.GroupassignContext context);
	/// <summary>
	/// Exit a parse tree produced by the <c>groupassign</c>
	/// labeled alternative in <see cref="cssParser.expression"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void ExitGroupassign([NotNull] cssParser.GroupassignContext context);

	/// <summary>
	/// Enter a parse tree produced by the <c>word</c>
	/// labeled alternative in <see cref="cssParser.expression"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void EnterWord([NotNull] cssParser.WordContext context);
	/// <summary>
	/// Exit a parse tree produced by the <c>word</c>
	/// labeled alternative in <see cref="cssParser.expression"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void ExitWord([NotNull] cssParser.WordContext context);

	/// <summary>
	/// Enter a parse tree produced by the <c>command</c>
	/// labeled alternative in <see cref="cssParser.expression"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void EnterCommand([NotNull] cssParser.CommandContext context);
	/// <summary>
	/// Exit a parse tree produced by the <c>command</c>
	/// labeled alternative in <see cref="cssParser.expression"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void ExitCommand([NotNull] cssParser.CommandContext context);

	/// <summary>
	/// Enter a parse tree produced by <see cref="cssParser.expression"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void EnterExpression([NotNull] cssParser.ExpressionContext context);
	/// <summary>
	/// Exit a parse tree produced by <see cref="cssParser.expression"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void ExitExpression([NotNull] cssParser.ExpressionContext context);
}
} // namespace ConsoleApplication3