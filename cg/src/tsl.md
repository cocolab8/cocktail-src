DEFINITION MODULE tsl;

IMPORT SYSTEM, IO, Tree;

VAR yyf	: IO.tFile;
VAR yyb	: BOOLEAN;
VAR Exit	: PROC;

PROCEDURE tsl (yyP1: Tree.tTree);

PROCEDURE Begintsl;
PROCEDURE Closetsl;

END tsl.
