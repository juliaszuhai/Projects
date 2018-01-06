%nu merge...
nrOcc([],_,C,C).
nrOcc([H|T],E,C,R):-
    H=:=E,
    C2 is C+1,
    nrOcc(T,E,C2,R).
nrOcc([H|T],E,C,R):-
    H=\=E,
    nrOcc(T,E,C,R).


notInSet([],_).
notInSet([H|T],E):-
    H=\=E,
    notInSet(T,E).

firstOcc([],[]).
firstOcc([H|T],[H|R]):-
    nrOcc(T,H,0,RT),
    RT=\=0,
    firstOcc(T,R).
firstOcc([H|T],R):-
    nrOcc(T,H,0,RT),
    RT=:=0,
    not(notInSet(R,H)),
    firstOcc(T,R).
firstOcc([H|T],[H|R]):-
    nrOcc(T,H,0,RT),
    RT=:=0,
    notInSet(R,H),
    firstOcc(T,R).
