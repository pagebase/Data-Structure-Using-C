@echo off
set s0="C:\Data-Structure-Using-C\Binary serch tree"
set destination="C:\Sink"
set s1="C:\Data-Structure-Using-C\Graph"
set s2="C:\Data-Structure-Using-C\Linked List"
set s3="C:\Data-Structure-Using-C\Practice_Codes"
set s4="C:\Data-Structure-Using-C\Queue"
set s5="C:\Data-Structure-Using-C\Stack"

if not exist %destination% mkdir %destination%

move %s0%\*.exe %destination%
move %s1%\*.exe %destination%
move %s2%\*.exe %destination%
move %s3%\*.exe %destination%
move %s5%\*.exe %destination%
move %s6%\*.exe %destination%