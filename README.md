# Xmake
<img src="https://img.icons8.com/fluency/96/000000/wrench.png"/>
Xmake is an alternative to Make

Xmake has its own syntax

##Example 
```
//this is a comment it will be ignored
$main
echo this is a command
$other_function
!EXIT
$another_function
!PAUSE
```
## Syntax

### Functions
To define a function use a `$` sign to define a function like this
```
$Function_1
Code goes here for function 1
$Function_2
Code goes here for function 2
```
### Commands
Anything that has no `!`,`//` or `$` is a command that is sent to the OS
### ! Commands
An `!` is a command that is sent to Xmake
#### !PAUSE
This will pause the Xmake script untill a enter key is pressed
#### !EXIT
This stops the program
### Comments 
A comment is made by adding `//` to the start of the line
```
//This is a comment
This is not a comment
```
## Compiling
### Compile for windows
<img src="https://img.icons8.com/fluency/48/000000/visual-studio-2019.png"/>

To Compile you need Visual Studio 2022
#### [Visual Studio 2022 Download Page](https://visualstudio.microsoft.com/)
Now open the installer and check Desktop development with C++

![](https://raw.githubusercontent.com/awesomelewis2007/WinCat/main/Documentation/Compiling/Install_C%2B%2B.png)

Now open the Visual Studo command prompt

![](https://raw.githubusercontent.com/awesomelewis2007/WinCat/main/Documentation/Compiling/Cmd.png)

Now check if `cl` is installed

![](https://raw.githubusercontent.com/awesomelewis2007/WinCat/main/Documentation/Compiling/Verify.png)

Now clone this repo `https://github.com/awesomelewis2007/Xmake`.
Now change diectory over to the `Xmake` folder

To compile run `cl Xmake.cpp function.cpp`

To run the compiled app run `./Xmake.exe`

### Compile for linux

To compile for linux you need `g++`

to install `g++` run
```
audo apt update
sudo apt install build-essential
sudo apt install g++
```
to compile run `g++ Xmake.cpp function.cpp`
