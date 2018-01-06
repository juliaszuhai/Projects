noOcc([],_,C,C).
noOcc([H|T],E,C,R):-
    H=:=E,
    C2 is C+1,
    noOcc(T,E,C2,R).
noOcc([H|T],E,C,R):-
    H=\=E,
    noOcc(T,E,C,R).

%remove(L-lista,R-lista)
%remove(i,o)
remove([],[]).
remove([H|T],R):-
    noOcc(T,H,1,Res),
    Res>1,
    removeElm(T,H,RRem),
    remove(RRem,R).
remove([H|T],[H|R]):-
    noOcc(T,H,1,Res),
    Res=1,
    remove(T,R).


removeElm([],_,[]).
removeElm([H|T],E,R):-
    H=:=E,
    removeElm(T,E,R).
removeElm([H|T],E,[H|R]):-
    H=\=E,
    removeElm(T,E,R).


