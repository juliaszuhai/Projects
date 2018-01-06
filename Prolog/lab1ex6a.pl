%noOcc(L-lista,E-element,C,R)
%noOcc(i,i,o,o)
noOcc([],_,C,C).
noOcc([H|T],E,C,R):-
    E=:=H,
    C2 is C+1,
    noOcc(T,E,C2,R).
noOcc([H|T],E,C,R):-
    E=\=H,
    noOcc(T,E,C,R).


%isSet(L-lista)
%isSet(i)
isSet([]).
isSet([H|T]):-
    noOcc(T,H,0,R2),
    R2=:=0,
    isSet(T).


