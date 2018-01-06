%replace(L-lista,E,L2-lista,R,Rez)
replace([],_,_,R,R).
replace([H|T],E,L2,R,Rez):-
    H=:=E,
    putList(L2,R,RT),
    replace(T,E,L2,RT,Rez).
replace([H|T],E,L2,R,Rez):-
    H=\=E,
    replace(T,E,L2,[H|R],Rez).

putList([],R,R).
putList([H|T],R,Rez):-
    putList(T,[H|R],Rez).
