addEven([],[]).
addEven([H|T],[H,1|RT]):-
    C is mod(H,2),
    C=:=0,
    addEven(T,RT).
addEven([H|T],[H|R]):-
    C is mod(H,2),
    C=:=1,
    addEven(T,R).


