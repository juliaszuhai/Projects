(DEFUN rev(L)
(COND
((NULL L) NIL)
((atom (car L)) (append (rev (cdr L)) (list (car L))))
((listp (car L)) (append (rev (cdr L)) (list(rev(car l)))))
))