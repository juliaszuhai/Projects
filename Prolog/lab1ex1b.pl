%insert(L-list,E-elemnt,C-contor,K-pow2contor,R-list)
%insert(i,i,i,i,o)
insert([],E,C,K,[]).
insert([H|T],E,C,K,[H|R]):-
    K =\=C,
    C2 is C+1,
    insert(T,E,C2,K,R).
insert([H|T],E,C,K,[E,H|RT]):-
    C=:=K,
    C2 is C+1,
    K2 is K*2,
    insert(T,E,C2,K2,RT).


add(L,E,R):-insert(L,E,1,1,R).
