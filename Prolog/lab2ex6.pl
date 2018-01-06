reverse([],R,R).
reverse([H|T],R,Res):-
    reverse(T,[H|R],Res).
product(L1,E,R):-
    reverse(L1,[],R1),
    prod(R1,E,0,Res),
    reverse(Res,[],R).

prod([],_,0,[]):-!.
prod([],_,CF,[CF]):-!.

prod([H|T],E,CF,[M|R]):-
    MUL is H*E+CF,
    MUL>=10,
    M is mod(MUL,10),
    CF is MUL/10,
    prod(T,E,CF,R).
prod([H|T],E,CF,[MUL|R]):-
    MUL is H*E+CF,
    MUL<10,
    prod(T,E,0,R).
