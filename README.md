# Modern Computer Methods in Physics I. (2020/2021/2)

This is a repository dedicated to the course named above. This repository will contain the _homeworks_ wih their deadlines stated here, the project work and its documentation about its development. This readme file will contain the descriptions of major commits. For professionality, the binary files (.exe,.bin,...etc) will be ignore when committing. (.gitignore). 2021/04/29 build folders are now ignored. Fixed 2020->2021

## State of the project

### 2021/04/29: ideas pushed

> Project is initialized. Ideas are written down, R&D soon starting.

### 2021/05/04: RK4 and vectorN header added

> The needed tools for the project are done and somewhat good in this state

> NOTE: no control for unmathcing sizes of different vectors. Using vectorN.hpp is not advised now. Solution is to compare sizes, extend the smaller with zeros and then do the operation.

> More progress later on...

### 2021/05/06: main frame update

> The needed data structure became real. -> more in report.

> Due to some issue, no rea development.

> This updatecomes with the structure, file loading, printing and state update. Mainly, I am writing and something that is closer to an N-body problem. This means somewhat slower delepoment. Due to it being a many body problem, more data buffers are required with the same structure. Furthermore, for more general usage, the dimensionality can be changed. A coordinate system should be considered: Descartes. This way the TRV will contain vectors, that each have the following structure: (t,x1,x2,x3,v1,v2,v3). The number of vectors in TRV corresponds to body count. Different approuch: (t,r,theta,nu,v,phi,khi) (polar coordinates.). To show the speciality of this binary system, this will be needed during analysis.

> Choosen measurents: kg, AU, year.

> NOTE: no error control, apart from checking if the file is opened.

### 2021/05/07: almost works

> The development of the code is almost finished. There are a couple of wierd things it outputs but i need jupyter notebook to print out its results. Ofc, I am running itwith a weird binary system (nothing moves almost), which may be the cause of these weird outputs. It next couple of ours i will further investigate and polish the code and create the report.

> NOTE: finally.

```
Soon.
```
## Dealines
> HW1: 2021/03/14, 23:59 - Finished

> HW2: 2021/03/25, 23:59 - Finished

> HW3: 2021/03/18, 23:59 - Finished

> HW4: 2021/04.25, 23:59 - Finished

> Project: 2020/05/07, 23:59 - Working


## Commits

### 2021/03/13,16:10: Init
> After some time, this repository started with a basic setup. Containes hw1 start.

### 2021/03/13/18:22: hw1 finished almost
> There some issus with the given codes. After a couple hourse of testing and additional research, the -std=c++11 flag solved most of the issues. The code works right now.

> NOTE: more polished code could take arguments and use those for setting up precision, tolerance and printed precision.

### 2021/03/25,13:03: hw2, function fixing
> After some testing, I was able to troubleshoot coupl of things: befriending has to bedone between different classes

> What's the first difference between struct and class in C++? Their variables visibility.

> For completition I will use a struct, but it can be easily converted into a class.

> NOTE: due to my new setup, the executible file lands in the build/debug folder. [".\run1.bat" to launch!]

### 2021/03/25,15:14: hw2, testing in main.cpp
> NOTE: these functions could be added to the Vector2D struct itself and called in main. Th exercise is doing the testing, which causes them to be remain in main.

> HW2: finished, branch merging, dev deletion.

> MESSEGE: `returning addres of loal variable or temporary [...] MSVC(4172)`

### 2021/04/17,15:20: hw3, finished and polished

> NOTE: it does what it should. Tested with more n (10,100,1000,...etc) and even 100 does the %1 error.

### 2021/04/17,15:39: hw3, finished and results in .csv

> NOTE: this is the finishing of hw3, soon to be onto hw4 and project!

### 2021/04/25, 21:34, hw4 finshed, result in .csv

> NOTE: hw4 is finished, some idiot forgot to commit and push it... Not me though!

> MESSEGE: MSVC(C4244), conversation between double to int irritates it. Its not a lossless conversation between int and double, understandable warning! (rare)

#### Managing branches:
1. Git checkout new-branch
2. git add .
3. git commit -m "Some notes here"
4. git checkout branch
5. git merge new-branch

1. git branch -d localBranchName
2. git push origin --delete remoteBranchName