%count(L,C)
%count(i,i)
count([],0).
count([_|T],C):-
    C=:=0,
    count(T,1).
count([_|T],C):-
    C=:=1,
    count(T,0).

counting(L):-count(L,0).
