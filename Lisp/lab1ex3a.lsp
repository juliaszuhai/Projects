(DEFUN insert(L E C)
(COND
((and(NULL L) (EQUAL C 2)) (list E ))
((NULL L) NIL)
((EQUAL C 2) (CONS E (insert L E 0)))
((not(equal C 2)) (CONS (car L) (insert (cdr L) E (+ 1 C))))
))