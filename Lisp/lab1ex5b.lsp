(DEFUN assList(L R)
(COND
((NULL L) NIL)
(T (CONS (CONS (CAR L) (CAR R)) (assList(cdr L) (cdr R))))
))