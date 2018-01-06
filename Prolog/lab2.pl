%del(L-lista,E-element,C-contor,R-lista)
%del(i,i,i,o).
del([],_,_,[]).
del([H|T],E,C,[H|RT]):-H=\=E,
    del(T,E,C,RT).
del([H|T],E,C,[H|RT]):-C=:=0,
    del(T,E,C,RT).
del([H|T],E,C,R):-H=:=E,
    C2 is C-1,
    del(T,E,C2,R).
