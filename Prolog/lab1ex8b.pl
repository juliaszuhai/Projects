%minimum(L,M)
%minimum(i,o)
minimum([],MIN,MIN).
minimum([H|T],M,MIN):-
    H<M,
    minimum(T,H,MIN).
minimum([H|T],M,MIN):-
    H>=M,
    minimum(T,M,MIN).

minim(L,R):-minimum(L,9999999,R).


%deletare(L,E,R).
%deletare(i,i,o)
deletare([],_,[],_).
deletare([H|T],E,R,C):-
    H=:=E,
    C=:=0,
    deletare(T,E,R,1).
deletare([H|T],E,[H|R],C):-
    H=\=E,
    C=:=0,
    deletare(T,E,R,C).
deletare(L,_,L,1):-!.

deletMin(L,R):-
    minim(L,MIN),
    deletare(L,MIN,R,0).
