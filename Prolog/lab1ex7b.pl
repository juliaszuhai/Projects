%interval(M-number,N-number,R-list,Rez)
%interval(i,i,i,o)
interval(N,N,R,[N|R]):-!.
interval(M,N,R,Rez):-
    M1 is M+1,
    interval(M1,N,[M|R],Rez),!.


wrapper(M,N,R):-interval(M,N,[],R).
