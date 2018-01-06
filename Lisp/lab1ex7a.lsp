(DEFUN nthElem(L N)
(COND
((NULL L) NIL)
((EQUAL N 1) (cdr L))
(T (cons (car L) (nthElem(cdr L) (- N 1))))
))