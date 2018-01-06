(DEFUN counting(L)
(COND
((NULL L) 0)
((numberp(car L)) (+ 1 (counting (cdr L))))
(T (counting (cdr L)))))