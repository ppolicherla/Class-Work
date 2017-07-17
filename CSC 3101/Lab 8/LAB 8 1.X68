*-----------------------------------------------------------
* Title      :
* Written by :
* Date       :
* Description:
*-----------------------------------------------------------
      ORG $400
      MOVEA #T,A0
      MOVEA #J,A1
      MOVE.B #1,D0 D0 is a counter to hold I
      MOVE.B #5,D1 X = 5
      MOVE.B #7,D2 Y = 7
NEXT
      ADD.B D0,D2 Y = Y + I
      MOVE.B (A0),D3
      MOVE.B (A1),D4
      MOVE.B D4,D5 D5 is a temp copy of J(I)
      ADD.B D1,D5
      CMP D5,D3 IF T(I) = J(I) + X
      BNE ELSE
      MULU #4,D3
      SUB.B D2,D3
      MOVE.B D3,(A1)
      BRA END_LOOP
ELSE
      SUB D3,D4 J(I) = J(I) - T(i)
      MOVE.B D4,(A1)
END_LOOP  
      ADDA #1,A0 POINT TO NEXT ELEMENT IN T
      ADDA #1,A1 POINT TO NEXT ELEMENT IN J
      ADD #1,D0
      CMP #9,D0
      BNE NEXT
      MOVE.B #9,D0
      TRAP #15 ; halt simulator
* Variables and Strings
T DC.B 6,2,5,9,9,7,3,1,0
J DC.B 5,7,1,4,2,5,6,6,1
  END $400 ; last line of source

*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
