%intersection(L-List,C-list,R-accumulator list,Rez-final list)
%intersection(i,i,i,o)
intersection([],_,R,R).
intersection([H|T],L,R,Rez):-
    not(notsearch(L,H)),
    intersection(T,L,[H|R],Rez).
intersection([H|T],L,R,Rez):-
    notsearch(L,H),
    intersection(T,L,R,Rez).

notsearch([],_).
notsearch([H|T],E):-
    H=\=E,
    notsearch(T,E).
