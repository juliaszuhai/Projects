(DEFUN isInList(L E)
(COND 
((NULL L) NIL)
((EQUAL (CAR L) E) T)
((LISTP(CAR L)) (or(isInList(CAR L) E)(isInList (CDR L) E)))
(T (isInList (CDR L) E))
))


(defun intersect( L R)
(COND
((and(null L) (null R)) NIL)
((isInList R (car L)) (cons (car L) (intersect (cdr L) R)))))