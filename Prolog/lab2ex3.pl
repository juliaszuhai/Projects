merge([],[],[]).
merge([H|T],[H1|T1],[H|R]):-
    H<H1,
    merge(T,[H1|T1],R).
merge([H|T],[H1|T1],[H1|R]):-
    H1<H,
    merge([H|T],T1,R).
merge([],[H|T],[H|R]):-
    merge([],T,R).
merge([H|T],[],[H|R]):-
    merge(T,[],R).

