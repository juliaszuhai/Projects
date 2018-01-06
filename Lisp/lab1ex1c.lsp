(DEFUN sublists(lst)
(COND 
((null lst) nil)
((listp(car lst)) (cons (car lst) (append (sublists(car lst)) (sublists(cdr lst)))))
((atom (car lst)) ( sublists(cdr lst)))
))

(DEFUN sublist (L)
(cons L (sublists L)))