(DEFUN isInList(L E)
(COND
((null L ) nil)
((and(atom (car L)) (equal (car l) E) ) T)
((and (atom(car L))  (not(equal (car L) E))) (isInList( cdr L) E))
((listp(car l)) (or (isInList(car L) E) (isInList(cdr L) e)))
))