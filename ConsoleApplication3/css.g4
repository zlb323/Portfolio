grammar css;
 

 expression			: WORD WORD+ ';'					#command
					| WORD								#word
				//	| GROUP WORD						#group
				//	| GROUP WORD+						#groupadd
					| GROUP WORD+ '{' expression+ '}'	#groupassign
					;
 
 fragment DIGIT		: [0-9];
 fragment LETTER	: [a-zA-Z];

 GROUP				: 'Group';

 WORD				: LETTER+;
 NUMBER				: DIGIT+ ;
 
WHITESPACE          : (' '|'\t')+ -> skip ;