%sum(L-list,C,R-result)
%sum(i,i,o)
sum([],_,R,R):-!.
sum([H|T],1,R,S):-
    SR is R+H,
    sum(T,0,SR,S).
sum([H|T],0,R,S):-
    SR is R-H,
    sum(T,1,SR,S).



sumI(L,R):-sum(L,1,0,R).
