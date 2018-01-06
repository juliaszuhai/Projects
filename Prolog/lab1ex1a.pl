%cmmdc(i,i,o)
cmmdc(_,0,inf):-!.
cmmdc(0,_,inf):-!.
cmmdc(A,A,A).
cmmdc(A,B,R):-A>B,
    RT is A-B,
    cmmdc(RT,B,R).
cmmdc(A,B,R):-B>A,
    RT is B-A,
    cmmdc(A,RT,R).

cmmmc(_,0,inf):-!.
cmmmc(0,_,inf):-!.
cmmmc(A,B,R):-
    cmmdc(A,B,C),
    R is (A*B)/C.

cmmmcList([E],E).
cmmmcList([A,B|T],R):-
    cmmmc(A,B,D),
    cmmmcList([D|T],R).
