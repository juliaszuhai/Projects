(DEFUN linear(L)
(COND
((NULL L) T)
((atom (car L)) (linear (cdr L)))
((listp (car L)) NIL)))