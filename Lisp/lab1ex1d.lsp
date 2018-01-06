(DEFUN makeSet(L)
(COND 
((null L ) nil)
((isInList( cdr l) (car l)) (makeSet (cdr L)))
((not(isInList (cdr l) (car l))) (cons (car l) (makeSet(cdr L))))
))


(DEFUN isInList(L E)
(COND 
((NULL L) NIL)
((EQUAL (CAR L) E) T)
((LISTP(CAR L)) (or(isInList(CAR L) E)(isInList (CDR L) E)))
(T (isInList (CDR L) E))
))