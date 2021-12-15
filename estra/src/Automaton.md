(* $Id: Automaton.md,v 4.0 1993/08/26 16:06:46 grosch rel $ *)

DEFINITION MODULE Automaton;

FROM IO		IMPORT	tFile;
FROM Queues	IMPORT	tQueue;


PROCEDURE BeginAutomaton	(stopstates: INTEGER; MaxInput: INTEGER);
PROCEDURE DefineTransition	(path: tQueue; stop: INTEGER);
PROCEDURE CloseAutomaton	(VAR CombSize: INTEGER);
PROCEDURE StartIndex		(input: INTEGER): INTEGER;
PROCEDURE PackComb		(f: tFile);

(* AUTO_ *)
PROCEDURE WriteAutomaton;
PROCEDURE WriteFunction;
PROCEDURE WriteComb;
(* _AUTO *)

END Automaton.
