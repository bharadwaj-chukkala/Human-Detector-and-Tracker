# Human Obstacle Detection and Tracking
[![Build Status](https://travis-ci.org/dpiet/cpp-boilerplate.svg?branch=master)](https://travis-ci.org/dpiet/cpp-boilerplate)
[![Coverage Status](https://coveralls.io/repos/github/dpiet/cpp-boilerplate/badge.svg?branch=master)](https://coveralls.io/github/dpiet/cpp-boilerplate?branch=master)
---

## Overview
This project involves the development of a Perception Module for Human Obstacle Detection and Tracking for a ACME Robotics product.

### Task
- We need to create a Perception module for an AGV product of ACME Robotics 
- Simulate Pair Programming and Test Driven Development
- Use Software Development Process AIP  
- Use Git Version control to coordinate
- Code Coverage and Continuous Integration with TravisCI and Coveralls
- 
### Group  
`Bharadwaj Chukkala` | `Venkata Sairam Polina` | `Shelvin Pauly`

### Part 1 
- The Teams created their tentative UML Class Diagram for implementing the code.
- In the next step both teams created necessary classes and methods.
- The Team created the test cases for essentially how the detection is supposed to work.
- CMakeLists were created appropriately as seen in the content tree below.
- All this was done using git version control and detailed commits were written for each P-request
- The teams programmed the code such that multiple test cases pass without fail and merged their changes to main branch.
- cpplinting and checking was done for both the packages
- The code will be standardly documented using Doxygen


## Contents

<pre>├── <font color="#3465A4"><b>app</b></font>
│   ├── CMakeLists.txt
│   └── main.cpp
├── <font color="#3465A4"><b>build</b></font>
│   ├── <font color="#3465A4"><b>app</b></font>
│   ├── CMakeCache.txt
│   ├── <font color="#3465A4"><b>CMakeFiles</b></font>
│   ├── cmake_install.cmake
│   ├── compile_commands.json
│   ├── Makefile
│   ├── <font color="#3465A4"><b>test</b></font>
│   └── <font color="#3465A4"><b>vendor</b></font>
├── <font color="#3465A4"><b>cmake</b></font>
│   └── CodeCoverage.cmake
├── CMakeLists.txt
├── <font color="#3465A4"><b>include</b></font>
│   └── lib.hpp
├── MId term proposal ENPM08X.docx
├── readme.md
├── README.md
├── <font color="#3465A4"><b>test</b></font>
│   ├── CMakeLists.txt
│   ├── main.cpp
│   └── test.cpp
└── <font color="#3465A4"><b>vendor</b></font>
    └── <font color="#3465A4"><b>googletest</b></font>
</pre>

## Instructions to run the code
- Clone the Repository
### Building the package
```
mkdir build
cd build
cmake ..
make
```
### Running the package
```
./app/shell-app
```
### Testing the package
```
./test/cpp-test
```
### View code coverage
```
sudo apt-get install lcov [install lcov]
cd build
firefox coverage/index.html` [install firefox]
```  

### The UML Class Diagrams

![Class Diagram](https://user-images.githubusercontent.com/106445479/195428101-53fa582a-ed0f-48cc-b707-a5aeedcb2053.png)
*Fig 1 :  UML class diagram*


![Activity Diagram](https://user-images.githubusercontent.com/106445479/195427932-de4681d8-850a-4c22-8239-b083cc1708c9.png =250x )
*Fig 2 :  Activity diagram*

