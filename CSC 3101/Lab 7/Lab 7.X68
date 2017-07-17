*-----------------------------------------------------------
* Title      :Lab 7
* Written by :Pavan Policherla
* Date       :7/13/2016
* Description:Lab 7m 
*-----------------------------------------------------------
START:  ORG    $1000            ; first instruction of program

* Put program code here
        MOVE.W #14,D0
        LEA Prod, A1
        TRAP #15
        
        MOVE.W #3,D0
        MOVE.W X,D1
        ADD.W Y,D1
        MULU.W D1,D1
        MOVE.W Y,D2
        ADD.W Z,D2
        MULU.W D2,D2
        MULU.W D2,D1
        MOVE.W Z,D3
        ADD.W X,D3
        MULU.W D3,D3
        MULU.W D3,D1
        TRAP #15

* Put variables and constants here
X        DC.W 4
Y        DC.W 5
Z        DC.W 6      
Prod     DC.W '((X+Y)^2)*((Y+Z)^2) ((Z+X)^2) is: ', 0
         END    START        ; last line of source

*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
