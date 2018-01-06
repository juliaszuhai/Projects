(DEFUN dotProduct(L R)
(cond
((and(null L)(null R)) 0)
((and (numberp(car L)) (numberp(car R))) (+ (* (car L) (car R)) (dotProduct (cdr L) (cdr R))))))