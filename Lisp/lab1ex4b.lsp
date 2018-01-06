(DEFUN linear(L)
(cond
((null L) nil)
((atom (car L)) (append (list(car L)) (linear(cdr L))))
((listp (car L)) (append (linear(car L)) (linear(cdr L))))
))