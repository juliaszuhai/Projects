insert([],E,[E]).
insert([H|T],E,[H|T]):-E=:=H,!.
insert([H|T],E,[H|R]):-
    E>H,
    insert(T,E,R).
insert([H|T],E,[E,H|T]):-
    E<H.

sorted([],[]).
sorted([H|T],R):-
    sorted(T,Rez),
    insert(Rez,H,R).
