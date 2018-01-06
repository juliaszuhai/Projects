%substitute(L,E,L,R)
substitute([],_,_,[]).
substitute([H|T],E,L,R):-
    H=:=E,
    putInList(L,R),
    substitute(T,E,L,R).
substitute([H|T],E,L,[H|R]):-
    H=\=E,
    substitute(T,E,L,R).

putInList([],[]).
putInList([H|T],[H|R]):-
    putInList(T,R).
