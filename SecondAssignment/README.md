### Implementation of linux commands
#### myEcho.c
**echo** (printing all input strings)
compilation command : gcc -o myEcho myEcho.c
running command : ./myEcho string1 string2 string3 .....
> result :
```
Checking argments program start
argv = 4
argume number[0] : ./myEcho
argume number[1] : string1
argume number[2] : string2
argume number[3] : string3
Program is finished
```

#### myPWD.c
**pwd** (printing the working path)
compilation command : gcc -o myPWD myPWD.c
running command : ./myPWD
> result :
```
Getting my working path program start
pwd: /home/mrostom/LinuxTraining/LinuxTraining/SecondAssignment.
Program is finished
```

#### myCp.c
**cp** (copying files)
compilation command : gcc -o myCp myCp.c
running command : ./myCp test.txt test1.txt
> result :
```
Copying program start.
Copying file in progress (1024 KB).
Copying file in progress (2048 KB).
Copying file in progress (3072 KB).
Copying file in progress (4096 KB).
Copying file in progress (5120 KB).
Copying file in progress (6144 KB).
Copying file in progress (7168 KB).
Copying file in progress (8192 KB).
Copying file in progress (8262 KB).
Program finished
```

#### myMv.c
**mv** (moving files)
compilation command : gcc -o myMv myMv.c
running command : ./myMv test.txt test1.txt
> result :
```
Copying program start.
Copying file in progress (1024 KB).
Copying file in progress (2048 KB).
Copying file in progress (3072 KB).
Copying file in progress (4096 KB).
Copying file in progress (5120 KB).
Copying file in progress (6144 KB).
Copying file in progress (7168 KB).
Copying file in progress (8192 KB).
Copying file in progress (8262 KB).
Program finished
```



