notInSet([],_).
notInSet([H|T],E):-
    H=\=E,
    notInSet(T,E).

equality([],_).
equality([H|T],L):-
    not(notInSet(L,H)),
    equality(T,L).
