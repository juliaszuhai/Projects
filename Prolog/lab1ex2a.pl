%remove(L-list,E-element,R-list).
%remove(i,i,o)
remove([],_,[]).
remove([H|T],E,R):-
    H=:=E,
    remove(T,E,R).
remove([H|T],E,[H|R]):-
    H=\=E,
    remove(T,E,R).


