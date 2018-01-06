insert([],E,[E]).
insert([H|T],E,[H|R]):-E>=H,
    insert(T,E,R).
insert([H|T],E,[E,H|T]):-
    E<H.

sorting([],[]).
sorting([H|T],R):-
    sorting(T,Rez),
    insert(Rez,H,R).
