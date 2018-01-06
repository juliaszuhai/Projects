%inserare(L-list,E-element,R-list)
%inserare(i,i,o)
inserare([],E,[E]):-!.
inserare(L,E,[E|L]).
inserare([H|T],E,[H|R]):-
    inserare(T,E,R).

%permutari(L-list,R-list)
%permutari(i,o)
permutari([],[]).
permutari([H|T],R):-
    permutari(T,RT),
    inserare(RT,H,R).

%combinari(L-list,K-number,R-list)
%combinari(i,i,o)
combinari([E|_],1,[E]).
combinari([_|T],K,R):-
    combinari(T,K,R).
combinari([H|T],K,[H|R]):-
    K1 is K-1,
    K1>0,
    combinari(T,K1,R).

%aranjamente(L-list,K-number,R-list)
%aranjamente(i,i,o)
aranjamente(L,K,R):-
    combinari(L,K,RT),
    permutari(RT,R).
%aranjament(L-list,K-number,R-list)
%aranjament(i,i,o)
%functie wrapper
aranjament(L,K,RT):-
    findall(R,aranjamente(L,K,R),RT).
