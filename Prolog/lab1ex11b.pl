%sublist(L,M,N,C,R)
%sublist(i,i,i,i,o)
sublist([],_,_,_,R,R):-!.
sublist([H|T],M,N,C,R,Rez):-
    C>=M,
    C=<N,
    C2 is C+1,
    sublist(T,M,N,C2,[H|R],Rez).
sublist([H|T],M,N,C,R,Rez):-
    C>=N,
    C2 is C+1,
    sublist(T,M,N,C2,R,Rez),!.
sublist([H|T],M,N,C,R,Rez):-
    C=<M,
    C2 is C+1,
    sublist(T,M,N,C2,R,Rez),!.


sublista(L,M,N,R):-sublist(L,M,N,[],R).
