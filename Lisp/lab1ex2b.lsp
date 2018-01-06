(DEFUN depth(L C)
(COND
((null L) C)
((listp (car L) ) (maximum (depth (car L) (+ 1 C)) (depth (cdr L ) 1)))
((atom (car L) ) (depth (cdr L) C))
))


(DEFUN maximum(N M)
(COND
((>= N M) N)
((< N M) M)))