(DEFUN listA(L C)
(COND
((NULL L) C)
((listp (car L)) (listA (car L) (listA (cdr L) C)))
((isInList C (car L)) (listA (cdr L) C))
((not(isInList C (car L))) (listA (cdr L) (cons (car L) C)))
))






(DEFUN isInList(L E)
(COND 
((NULL L) NIL)
((EQUAL (CAR L) E) T)
((LISTP(CAR L)) (or(isInList(CAR L) E)(isInList (CDR L) E)))
(T (isInList (CDR L) E))
))