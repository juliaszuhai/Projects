pairs([_],Res,Res).
pairs([H|T],R,Rez):-
    makePairs(H,T,R,Res),
    pairs(T,Res,Rez).


%makePairs(E,L,Res).
makePairs(_,[],RT,RT):-!.
makePairs(E,[H|T],RT,Res):-
    makePairs(E,T,[[E,H]|RT],Res).


fct(L,Rez):-
    pairs(L,[],Rez).
