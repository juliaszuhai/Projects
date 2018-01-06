isNotInList([],_).
isNotInList([H|T],E):-
    H=\=E,
    isNotInList(T,E).


mult(_,[],L,L).
mult(L,[H|T],RT,Rez):-
    isNotInList(RT,H),
    mult(L,T,[H|RT],Rez).
mult(L,[H|T],RT,Rez):-
    not(isNotInList(RT,H)),
    mult(L,T,RT,Rez).


unionSet(L,R,RT):-
    mult(L,R,L,RT).


