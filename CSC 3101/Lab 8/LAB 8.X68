*-----------------------------------------------------------
* Title      :
* Written by :
* Date       :
* Description:
*-----------------------------------------------------------
    
START:     ORG    $1000     ; first instruction of program

* Put program code here
                  MOVE.W #14,D0
                  LEA MESS,A1
                  TRAP #15
                  MOVE.W #4,D0
                  TRAP #15
                  MOVE.B D1,D5
                  MOVE.B X,D2
                  MOVE.B Y,D3
REPEAT
                  CMP D2,D1
                  BLE EXIT
                  
                  
AC2
                  MOVE.W D2,D4
                  DIVU.W #2,D4
                  CMP D4,D3
                  BEQ IF
ELSE              
                  ADD.W #1,D2
                  BRA REPEAT

IF                
                  MOVE.W D2,D1
                  MOVE.W #3,D0
                  TRAP #15
                  ADD.W #1,D2
                  ADD.W #1,D3
                  BRA REPEAT
EXIT
                  MOVE #9,D0
                  TRAP #15
                  
                  
                  

* Put variables and constants here

X DC.B 0
Y DC.B 0
CR EQU $0D
LF EQU $0A
MESS DC.B 'ENTER AN UPPER LIMIT: ',CR,LF,0

    END    START        ; last line of source

*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
