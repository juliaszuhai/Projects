%nu merge
evenOdd([],E,E,O,O,LE,LE,LO,LO).
evenOdd([H|T],[H|E],E1,O,O1,LE1,LE2,LO,LO2):-
    C is mod(H,2),
    C=:=0,
    LE1 is LE+1,
    evenOdd(T,E,E1,O,O1,LE,LE2,LO,LO2).
evenOdd([H|T],E,E1,[H|O],O1,LE,LE2,LO1,LO2):-
    C is mod(H,2),
    C=:=1,
    LO1 is LO+1,
    evenOdd(T,E,E1,O,O1,LE,LE2,LO,LO2).
