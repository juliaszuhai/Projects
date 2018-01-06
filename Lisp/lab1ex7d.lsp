(DEFUN isSet(L)
(COND
((NULL L) T)
((isInList (cdr L) (car L)) NIL)
((not(isInList(cdr L) (car L))) (isSet (cdr L)))
))











(DEFUN isInList(L E)
(COND 
((NULL L) NIL)
((EQUAL (CAR L) E) T)
((LISTP(CAR L)) (or(isInList(CAR L) E)(isInList (CDR L) E)))
(T (isInList (CDR L) E))
))