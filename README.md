# ENPM808X-Midterm
# PID_Control_Group6_Team2

## Overview
### Task
- For Acme Robotics, we need to create a PID controller implementation for a new mobile robot product development!
- Simulate Pair Programming and Test Driven Development
- Use Git Version control to coordinate 
- 
### Group  
| `Bharadwaj Chukkala` | 
| `Venkata Sairam Polina`|

### Part 1 
- The Teams created their tentative UML Class Diagram for implementing the code.
- In the next step both teams created necessary classes and methods.
- The Team created the test cases for essentially how the detection is supposed to work.
- CMakeLists were created appropriately as seen in the content tree below.
- All this was done using git version control and detailed commits were written for each P-request
- The teams programmed the code such that multiple test cases pass without fail and merged their changes to main branch.
- cpplinting and checking was done for both the packages
- The code has been standardly documented using Doxygen


## Contents



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
### Run cppcheck and cpplint
Run cppcheck: Results are stored in `./results/cpp_check.pdf`
```
sh run_cppcheck.sh
```

Run cpplint: Results are stored in `./results/cpplint.pdf`
```
sh run_cpplint.sh
```
### The UML class diagrams



*Fig 1 :  UML class diagram*




*Fig 2 :  Activity diagram*

