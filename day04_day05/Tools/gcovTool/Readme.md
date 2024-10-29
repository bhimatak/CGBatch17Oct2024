run the gcov in the following steps

$gcc -fprofile-arcs -ftest-coverage main.c
$ls
a.out main.c main.gcno
$./a.out
Enter an integer: 1
x is less than 10
$ls
a.out main.c main.gcda main.gcno
$# Note above the formation of main.gcda
$# Below command generates code coverage report
$gcov main.c
File 'main.c'
Lines executed:66.67% of 9
Creating 'main.c.gcov


$cat main.c.gcov
less than 20\n");
$
$./a.out
Enter an integer: 15
x is greater than or equal to 10 and x is less than 20
$
$gcov main.c
File 'main.c'
Lines executed:88.89% of 9
-:
-:
-:
0:Source:main.c
0:Graph:main.gcno
0:Data:main.gcda
-: 0:Runs:1
-: 1:#include <stdio.h>
-: 2:
1: 3:int main()
-: 4:{
-: 5: int x;
-: 6:
1: 7: printf("Enter an integer: ");
1: 8: scanf("%d", &x);
-: 9:
1: 10: if (x < 10)
1: 11: printf("x is less than 10\n");
#####: 12: else if (x < 20)
#####: 13: printf("x is greater than or equal to 10 and x is
-:
#####:
14:
15:
else
printf("x is greater than or equal to 20\n");
-: 16:
1: 17: return 0;
-: 18:}




like wise continue executing for rest of the test cases which give the output of gcov with 100% coverage

this will help us in identifying the unit test cases if we have missed any

