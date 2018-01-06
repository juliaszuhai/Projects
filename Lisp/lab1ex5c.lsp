(DEFUN sublist(L)
(COND 
((NULL L) 0)
((atom (car L)) (sublist (cdr L)))
((listp (car L)) (+ 1 (sublist(car L)) (sublist (cdr L))))
))

(DEFUN nr_sublist(L)
(+ 1 (sublist L)))