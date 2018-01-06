(DEFUN noOcc(L E)
(COND 
((NULL L) 0)
((and (atom (car L))(EQUAL E (car L))) (+ 1 (noOcc( cdr L) E)))
((and(atom(car L)) (not(EQUAL E (car L))))(noOcc( cdr L) E))
((listp(car L)) (+ (noOcc(car L) E) (noOcc(cdr L) E)))
))