%nrOcc(L-list,E-elem,C-contor,R-result)
%nrOcc(i,i,i,o)
nrOcc([],_,C,C).
nrOcc([H|T],E,C,R):-
    H=:=E,
    C2 is C+1,
    nrOcc(T,E,C2,R).
nrOcc([H|T],E,C,R):-
    H=\=E,
    nrOcc(T,E,C,R).


toSet([],[]).
toSet([H|T],R):-
    nrOcc(T,H,0,RT),
    RT=\=0,
    toSet(T,R).
toSet([H|T],[H|R]):-
    nrOcc(T,H,0,RT),
    RT=:=0,
    toSet(T,R).
