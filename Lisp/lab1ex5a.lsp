(DEFUN twice (L N)
(COND
((NULL L) NIL)
((EQUAL N 1) (append (list (car L) (car L)) (cdr L)))
(T (CONS (car L) (twice (cdr L) (- N 1))))))