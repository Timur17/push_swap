# push_swap
xwq

Ваша программа должна использование 2 стека для сортировки целочисленного массива с помощью определенных команд:

|instructions	|Description
|----:|:----:|
|sa	|swap first two elements of stack A
|sb	|swap first two elements of stack B
|ss	|sa and sb at the same time
|pa	|pops the first elememt on B and puts it on top of A
|pb	|pops the first elememt on A and puts it on top of B
|ra	|rotates stuck A up by one
|rb	|rotates stuck B up by one
|rr	|rotates both A and B up by one
|rra	|rotates stuck A down by one
|rrb	|rotates stuck B down by one
|rrr	|rotates both A and B down by one

Также есть ограничение в передвежение чисел внутри самих стеках и между ними:

- no more than 2-3 operations for 3 integers
- no more than 12 operations for 5 integers
- no more than 700 operations for 100 integers
- no more than 5300 operations for 500 integers
