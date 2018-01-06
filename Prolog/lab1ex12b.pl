%removeN(L,N,R)
removeN([_|T],1,T):-!.
removeN([H|T],N,[H|R]):-
    N>0,
    N2 is N-1,
    removeN(T,N2,R),!.
