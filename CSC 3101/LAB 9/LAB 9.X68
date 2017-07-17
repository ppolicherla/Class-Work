*-----------------------------------------------------------
* Title      :
* Written by :
* Date       :
* Description:
*-----------------------------------------------------------

START:  ORG  $1000                 ; first instruction of program
* Put program code here
             MOVEA #ARRAY,A0
             LEA SPACE,A1
             MOVE.B #1,D0         D0 is a counter for ARRAY1
             MOVE.B #1,D2         D2 is a counter for ARRAY2

NEXT                   
             MOVE.B (A0),D4
             MOVE.B 1(A0),D3
             CMP #10,D0
             BEQ INCREMENT
RUN
             CMP D4,D3
             BGE GREAT
LESS
             ADDA #1,A0
             ADD #1,D0
             BRA NEXT
GREAT
             MOVE.B D3,D5
             ADDA #1,A0
             MOVE.B D0,D6
             ADD #1,D0
             BRA NEXT
INCREMENT
             MOVE.B D5,D1
             ADD #1,D2
             MOVE.B #3,D0
             TRAP #15
             MOVE #14,D0
             TRAP #15
             MOVE.B #1,D0
             MOVE.B D6,X
             MOVE.L #0,(A0,D6)
             MOVEA #ARRAY,A0
             CMP #11,D2
             BNE NEXT
EXIT
             MOVE.B #9,D0
             TRAP #15
* Put variables and constants here

X      DC.B 0

SPACE  DC.B ', ',0

ARRAY  DC.B 1,2,5,4,8,5,4,2,11,6

    END    START        ; last line of source


*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
