reverse([],R,R).
reverse([H|T],R,Rez):-
    reverse(T,[H|R],Rez).

%sum(L-number1,N-number2,S-sum)
%sum(i,i,o)
rev(L,N,RT):-
    reverse(L,[],R),
    reverse(N,[],Rez),
    sum(R,Rez,RT,0).

sum([],[],[],_).
sum([H1],[H2],[C],Rest):-
    Rest=:=0,
    S is H1+H2,
    S<10,
    C is mod(S,10).
sum([H1],[H2],[C],Rest):-
    Rest=:=1,
    S is H1+H2+1,
    S<10,
    C is mod(S,10).
sum([H1],[],[C],Rest):-
    Rest=:=1,
    S is H1+1,
    S<10,
    C is mod(S,10).
sum([H1],[],[C],Rest):-
    Rest=:=0,
    S is H1,
    S<10,
    C is mod(S,10).
sum([],[H1],[C|_],Rest):-
    Rest=:=0,
    S is H1,
    S<10,
    C is mod(S,10),
    sum([],[],[],_).
sum([],[H1],[C,1],Rest):-
    Rest=:=1,
    S is H1+1,
    S<10,
    C is mod(S,10).

%
sum([H1],[H2],[C,1],Rest):-
    Rest=:=0,
    S is H1+H2,
    S>=10,
    C is mod(S,10).
sum([H1],[H2],[C,1],Rest):-
    Rest=:=1,
    S is H1+H2+1,
    S>=10,
    C is mod(S,10).
sum([H1],[],[C,1],Rest):-
    Rest=:=1,
    S is H1+1,
    S>=10,
    C is mod(S,10).
sum([H1],[],[C,1],Rest):-
    Rest=:=0,
    S is H1,
    S>=10,
    C is mod(S,10).
sum([],[H1],[C,1],Rest):-
    Rest=:=0,
    S is H1,
    S>=10,
    C is mod(S,10).
sum([],[H1],[C,1],Rest):-
    Rest=:=1,
    S is H1+1,
    S>=10,
    C is mod(S,10).
sum([H1|T1],[H2|T2],[C|Rez],Rest):-
    Rest=:=0,
    S is H1+H2,
    S>=10,
    C is mod(S,10),
    sum(T1,T2,Rez,1).
sum([H1|T1],[H2|T2],[C|Rez],Rest):-
    Rest=:=1,
    S is H1+H2+1,
    S>=10,
    C is mod(S,10),
    sum(T1,T2,Rez,1).
sum([H1|T1],[H2|T2],[S|Rez],Rest):-
    Rest=:=1,
    S is H1+H2+1,
    S<10,
    sum(T1,T2,Rez,0).
sum([H1|T1],[H2|T2],[S|Rez],Rest):-
    Rest=:=0,
    S is H1+H2,
    S<10,
    sum(T1,T2,Rez,0).


