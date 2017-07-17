*-----------------------------------------------------------
* Title      :
* Written by :
* Date       :
* Description:
*-----------------------------------------------------------
    
START:  ORG $1000                ; first instruction of program

* Put program code here
            MOVE.W #14,D0
            LEA MESS,A1
            TRAP #15
            MOVE.B #4,D0
            TRAP #15
            MOVE.B D1,D2    D2 will be x
            MOVE.W #14,D0
            LEA MESS2,A1
            TRAP #15
            MOVE.W #4,D0
            TRAP #15
            MOVE.B D1,D3     D3 will be y
            CMP #12,D2       Comparing 12 to x
            BGT AC2
AC1 
            LEA GREAT,A1
            ADD D3,D2
            MOVE.W D2,D1
            MOVE.W #14,D0
            TRAP #15
            MOVE.W #3,D0
            TRAP #15
            BRA EXIT
AC2
            LEA LESS,A1
            MULU.W #2,D2
            ADD.W  #4,D2
            MOVE.W D2,D1
            MOVE.W #14,D0
            TRAP #15
            MOVE.W #3,D0
            TRAP #15
EXIT
            MOVE.W #9,D0
            TRAP #15
* Put variables and constants here
CR EQU $0D
LF EQU $0A

MESS DC.B 'ENTER THE VALUE OF X: ',CR,LF,0
MESS2 DC.B 'ENTER VALUE OF Y: ',CR,LF,0
GREAT DC.B 'X+Y is ',0
LESS DC.B '2*x+4 is ',0


    END    START        ; last line of source

*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
