# UNICKI
Unicki is a lightweight C unit testing framework.
Supports Linux and Windows.

# Installation

## Linux
### Requirements
gcc, make
```
sudo apt install gcc make
```
### Install Unicki
```bash
git clone https://github.com/mats3/unicki.git
make installLib
```
# How to use
```C
// test.c
  1 #include<unicki.h>
  3 
  4 int getSum(int x, int y) {
  5     return x + y;
  6 }
  7 
  8 _testSection_
  9 
 10 suite("calculation") {
 11     suite("func: getSum") {
 12         test("return the sum of x, y") {
 13             assertIntEq(10, getSum(5, 5));
 14         } 
 15     }_end;
 16 }_end;
 17 
 18 _endSection_
 ```
### Execute Tests
```
gcc test.c -lunicki -o test
./test
```
```
 25 ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁                                         
 26 ▏                    ▕                                                
 27 ▏     Unit Tests     ▕                                                
 28 ▏      [UNICKI]      ▕                                                
 29 ▏                    ▕                                                
 30 ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔                                                
 31 calculation:                                                          
 32    func: getSum:                          
 33       ✔ return the sum of x, y            
 34                                           
 35 PASSED:     1                         
 36 FAILED:     0                                                         
 37 PENDING:    0  
 ```
