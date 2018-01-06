(DEFUN suma(L)
(COND
((NULL L) 0)
((numberp(car L)) (+ (car L) (suma(cdr L))))
(T (suma (cdr L)))))