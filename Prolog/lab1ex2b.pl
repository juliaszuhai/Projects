noOcc([],_,C,C).
noOcc([H|T],E,C,R):-
    H=:=E,
    C2 is C+1,
    noOcc(T,E,C2,R).
noOcc([H|T],E,C,R):-
    H=\=E,
    noOcc(T,E,C,R).

notInList([H|T],E):- is_list(H),
    verify(H,E),
    notInList(T,E).
notInList([],_).


verify([H,T],E):-
    H=\=E.

%numberatom(L-list,R-list)
%numberatom(i,o)
numberatom([],R,R).
numberatom([H|T],R,Res):-
    notInList(R,H),
    noOcc(T,H,1,C),
    numberatom(T,[[H,C]|R],Res).
numberatom([H|T],R,Res):-
    not(notInList(R,H)),
    numberatom(T,R,Res).

