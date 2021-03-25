# Modern Computer Methods in Physics I. (2020/2021/2)

This is a repository dedicated to the course named above. This repository will contain the _homeworks_ wih their deadlines stated here, the project work and its documentation about its development. This readme file will contain the descriptions of major commits. For professionality, the binary files (.exe,.bin,...etc) will be ignore when committing. (.gitignore)

## State of the project

```
Soon.
```
## Dealines
> HW1: 2020/03/14, 23:59

> HW2: 2020/03/25, 23:59

> Project: 2020/05/07, 23:59


## Commits

### 2020/03/13,16:10: Init
> After some time, this repository started with a basic setup. Containes hw1 start.

### 2020/03/13/18:22: hw1 finished almost
> There some issus with the given codes. After a couple hourse of testing and additional research, the -std=c++11 flag solved most of the issues. The code works right now.

> NOTE: more polished code could take arguments and use those for setting up precision, tolerance and printed precision.

### 2020/03/25,13:03: hw2, function fixing
> After some testing, I was able to troubleshoot coupl of things: befriending has to bedone between different classes

> What's the first difference between struct and class in C++? Their variables visibility.

> For completition I will use a struct, but it can be easily converted into a class.

> NOTE: due to my new setup, the executible file lands in the build/debug folder. [".\run1.bat" to launch!]

### 2020/03/25,15:14: hw2, testing in main.cpp
> NOTE: these functions could be added to the Vector2D struct itself and called in main. Th exercise is doing the testing, which causes them to be remain in main.

> HW2: finished, branch merging, dev deletion.
í
> MESSEGE: `returning addres of loal variable or temporary [...] MSVC(4172)`


#### Managing branches:
1. Git checkout new-branch
2. git add .
3. git commit -m "Some notes here"
4. git checkout branch
5. git merge new-branch

1. git branch -d localBranchName
2. git push origin --delete remoteBranchName