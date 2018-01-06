isNotInSet([],_).
isNotInSet([H|T],E):-
    H=\=E,
    isNotInSet(T,E).


difference([],_,R,R).
difference([H|T],L,R,Res):-
    isNotInSet(L,H),
    difference(T,L,[H|R],Res).
difference([H|T],L,R,Res):-
    not(isNotInSet(L,H)),
    difference(T,L,R,Res).

