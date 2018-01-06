(DEFUN linear(L)
(COND
((NULL L) NIL)
((atom (car L)) (append (linear (cdr L) ) (list (car L))))
((listp(car L)) (append (linear (cdr L)) (linear (car L))))
))