maximum([],M,M).
maximum([H|T],M,R):-
    H>M,
    maximum(T,H,R).
maximum([H|T],M,R):-
    H=<M,
    maximum(T,M,R).


remove(L,R):-
    maximum(L,0,M),
    removeElm(L,M,R).

removeElm([],_,[]).
removeElm([H|T],E,R):-
    H=:=E,
    removeElm(T,E,R).
removeElm([H|T],E,[H|R]):-
    H=\=E,
    removeElm(T,E,R).
