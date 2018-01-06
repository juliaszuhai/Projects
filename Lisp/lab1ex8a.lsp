(DEFUN isInList(L E)
(COND 
((NULL L) NIL)
((EQUAL (CAR L) E) T)
((LISTP(CAR L)) (or(isInList(CAR L) E)(isInList (CDR L) E)))
(T (isInList (CDR L) E))
))



(DEFUN difference( L R)
(COND
((NULL L) NIL)
((isInList R (car L)) (difference(cdr L) R))
((not (isInList R (car L))) (CONS (car L) (difference (cdr L) R)))
))

