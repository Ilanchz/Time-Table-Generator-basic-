
The timetable generator app is a simple bruteforce
method ultilising application that generates multiple timetables
for a university semester.
The inputs are fed using CSV files that contains the
data in the format:


<Course Code> , <Hours Per Week Allocated> , <The Maximum Hours Per Day> , < FacultyCode-Handling The Course > , < Credits >



Operation of the executable file in the project :
Sample Input: 

CSE.csv

MAT ,5,2,YK,4.5
EVS ,3,1,NP,1
FDS ,3,1,BSK,3
FPSD,3,1,RK,3
BEEE,4,1,BR,3
MEN ,1,1,AB,0
SPR ,1,1,SP,1
HSE ,2,1,PS,2
Lab-FPSD,3,3,RK,2
Lab-HSE,2,2,PS,2
Lab-EPL,3,3,BU,2

ECE.csv

MAT ,5,2,GK,4.5
EVS ,3,1,MSM,1
FED ,3,1,VV,3
CNA,4,1,BR,3
BEIE,3,1,GRV,0
MEN ,1,1,SP,1
SPR ,1,1,NA,0.5
HSE ,2,1,PS,2
Lab-CDL,3,3,RK,2
Lab-HSE,2,2,PS,2
Lab-CNA,3,3,BU,2

EEE.csv

MAT ,5,2,CK,4.5
EVS ,3,1,TSG,1
MECH ,3,1,BSK,3
EEE,3,1,USA,3
BEEE,3,1,MSK,3
MEN ,1,1,AB,0
SPR ,2,1,SP,1
HSE ,2,1,EDF,2
Lab-EEE,3,3,AVK,2
Lab-HSE,2,2,PS,2
Lab-EPL,3,3,BU,2

MECH.csv

MAT ,5,2,SY,4.5
EVS ,3,1,AM,1
FME ,3,1,VV,3
CNA,4,1,BR,3
BEEE,3,1,GRV,3
MEN ,1,1,SP,0
SPR ,1,1,NA,0.5
HSE ,2,1,PS,2
Lab-FME,3,3,RK,2
Lab-HSE,2,2,PS,2
Lab-EPL,3,3,BU,2

CIVIL.csv

MAT ,5,2,CK,4.5
EVS ,3,1,NP,1
EMECH ,3,1,PSG,3
CFP,4,1,ASG,3
BEEE,3,1,VSN,3
MEN ,1,1,NA,0
SPR ,1,1,NA,0.5
HSE ,2,1,PS,2
Lab-CFP,3,3,ASG,2
Lab-HSE,2,2,PS,2
Lab-EPL,3,3,SKV,2

CHEM.csv

MAT ,5,2,TMR,4.5
EVS ,3,1,AM,1
CHEM ,3,1,VSG,3
SMECH,3,1,RVL,3
CENG,4,2,MSN,3
MEN ,1,1,NA,0
SPR ,1,1,NA,1
HSE ,2,1,EDF,2
Lab-CAL,3,3,PSK,2
Lab-HSE,2,2,EDF,2
Lab-EPL,3,3,GRV,2

Sample Output:

Department: CSE

Department Faculty Codes: 
MAT ,EVS ,FDS ,FPSD,BEEE,MEN ,SPR ,HSE ,Lab-FPSD,Lab-HSE,Lab-EPL,
YK,NP,BSK,RK,BR,AB,SP,PS,RK,PS,BU,
Section: A

Day,1,2,3,4,,5,6,
MON,Lab-EPL,Lab-EPL,Lab-EPL,MAT ,Break,EVS ,BEEE,
TUE,FPSD,Lab-HSE,Lab-HSE,MAT ,Break,SPR ,FDS ,
WED,Lab-FPSD,Lab-FPSD,Lab-FPSD,BEEE,Break,EVS ,FPSD,
THU,HSE ,FDS ,MAT ,BEEE,Break,MEN ,MAT ,
FRI,BEEE,HSE ,FDS ,FPSD,Break,EVS ,MAT ,

Section: B

Day,1,2,3,4,,5,6,
MON,FDS ,HSE ,FPSD,EVS ,Break,MAT ,MEN ,
TUE,FDS ,MAT ,BEEE,FPSD,Break,MAT ,EVS ,
WED,BEEE,MAT ,EVS ,SPR ,Break,Lab-HSE,Lab-HSE,
THU,BEEE,Lab-EPL,Lab-EPL,Lab-EPL,Break,HSE ,FDS ,
FRI,MAT ,Lab-FPSD,Lab-FPSD,Lab-FPSD,Break,FPSD,BEEE,





Department: ECE

Department Faculty Codes: 
MAT ,EVS ,FED ,CNA,BEIE,MEN ,SPR ,HSE ,Lab-CDL,Lab-HSE,Lab-CNA,
GK,MSM,VV,BR,GRV,SP,NA,PS,RK,PS,BU,
Section: A

Day,1,2,3,4,,5,6,
MON,MAT ,BEIE,SPR ,FED ,Break,MAT ,CNA,
TUE,CNA,BEIE,HSE ,FED ,Break,MAT ,MAT ,
WED,EVS ,Lab-CDL,Lab-CDL,Lab-CDL,Break,BEIE,CNA,
THU,EVS ,HSE ,MAT ,MEN ,Break,Lab-HSE,Lab-HSE,
FRI,EVS ,Lab-CNA,Lab-CNA,Lab-CNA,Break,FED ,CNA,

Section: B

Day,1,2,3,4,,5,6,
MON,Lab-CNA,Lab-CNA,Lab-CNA,EVS ,Break,BEIE,SPR ,
TUE,MAT ,Lab-CDL,Lab-CDL,Lab-CDL,Break,EVS ,CNA,
WED,MEN ,EVS ,HSE ,CNA,Break,MAT ,FED ,
THU,Lab-HSE,Lab-HSE,BEIE,CNA,Break,FED ,MAT ,
FRI,FED ,BEIE,MAT ,CNA,Break,MAT ,HSE ,





Department: EEE

Department Faculty Codes: 
MAT ,EVS ,MECH ,EEE,BEEE,MEN ,SPR ,HSE ,Lab-EEE,Lab-HSE,Lab-EPL,
CK,TSG,BSK,USA,MSK,AB,SP,EDF,AVK,PS,BU,
Section: A

Day,1,2,3,4,,5,6,
MON,EVS ,BEEE,EEE,MAT ,Break,MAT ,HSE ,
TUE,BEEE,Lab-EEE,Lab-EEE,Lab-EEE,Break,MAT ,MECH ,
WED,Lab-EPL,Lab-EPL,Lab-EPL,EVS ,Break,BEEE,MECH ,
THU,Lab-HSE,Lab-HSE,MEN ,EEE,Break,EVS ,SPR ,
FRI,SPR ,HSE ,EEE,MAT ,Break,MECH ,MAT ,

Section: B

Day,1,2,3,4,,5,6,
MON,EEE,MAT ,HSE ,EVS ,Break,BEEE,MAT ,
TUE,MEN ,Lab-EPL,Lab-EPL,Lab-EPL,Break,EEE,BEEE,
WED,Lab-HSE,Lab-HSE,MAT ,MECH ,Break,SPR ,BEEE,
THU,SPR ,MAT ,EVS ,MECH ,Break,MAT ,EEE,
FRI,HSE ,Lab-EEE,Lab-EEE,Lab-EEE,Break,EVS ,MECH ,





Department: MECH

Department Faculty Codes: 
MAT ,EVS ,FME ,CNA,BEEE,MEN ,SPR ,HSE ,Lab-FME,Lab-HSE,Lab-EPL,
SY,AM,VV,BR,GRV,SP,NA,PS,RK,PS,BU,
Section: A

Day,1,2,3,4,,5,6,
MON,Lab-EPL,Lab-EPL,Lab-EPL,MEN ,Break,MAT ,CNA,
TUE,HSE ,BEEE,CNA,FME ,Break,EVS ,MAT ,
WED,Lab-HSE,Lab-HSE,BEEE,MAT ,Break,FME ,SPR ,
THU,Lab-FME,Lab-FME,Lab-FME,CNA,Break,EVS ,MAT ,
FRI,FME ,HSE ,CNA,MAT ,Break,BEEE,EVS ,

Section: B

Day,1,2,3,4,,5,6,
MON,CNA,Lab-FME,Lab-FME,Lab-FME,Break,MEN ,BEEE,
TUE,MAT ,SPR ,EVS ,BEEE,Break,HSE ,FME ,
WED,Lab-EPL,Lab-EPL,Lab-EPL,CNA,Break,MAT ,FME ,
THU,FME ,MAT ,EVS ,HSE ,Break,MAT ,CNA,
FRI,MAT ,CNA,BEEE,EVS ,Break,Lab-HSE,Lab-HSE,





Department: CIVIL

Department Faculty Codes: 
MAT ,EVS ,EMECH ,CFP,BEEE,MEN ,SPR ,HSE ,Lab-CFP,Lab-HSE,Lab-EPL,
CK,NP,PSG,ASG,VSN,NA,NA,PS,ASG,PS,SKV,
Section: A

Day,1,2,3,4,,5,6,
MON,CFP,MEN ,MAT ,EMECH ,Break,Lab-HSE,Lab-HSE,
TUE,HSE ,EMECH ,CFP,BEEE,Break,MAT ,MAT ,
WED,Lab-EPL,Lab-EPL,Lab-EPL,CFP,Break,EVS ,SPR ,
THU,HSE ,BEEE,EMECH ,EVS ,Break,CFP,MAT ,
FRI,Lab-CFP,Lab-CFP,Lab-CFP,EVS ,Break,BEEE,MAT ,

Section: B

Day,1,2,3,4,,5,6,
MON,Lab-CFP,Lab-CFP,Lab-CFP,EVS ,Break,MEN ,CFP,
TUE,BEEE,MAT ,SPR ,EMECH ,Break,CFP,HSE ,
WED,EVS ,Lab-HSE,Lab-HSE,BEEE,Break,HSE ,MAT ,
THU,BEEE,MAT ,MAT ,EMECH ,Break,EVS ,CFP,
FRI,MAT ,Lab-EPL,Lab-EPL,Lab-EPL,Break,CFP,EMECH ,





Department: CHEM

Department Faculty Codes: 
MAT ,EVS ,CHEM ,SMECH,CENG,MEN ,SPR ,HSE ,Lab-CAL,Lab-HSE,Lab-EPL,
TMR,AM,VSG,RVL,MSN,NA,NA,EDF,PSK,EDF,GRV,
Section: A

Day,1,2,3,4,,5,6,
MON,SMECH,CENG,MAT ,CHEM ,Break,MEN ,MAT ,
TUE,SPR ,Lab-CAL,Lab-CAL,Lab-CAL,Break,CENG,EVS ,
WED,Lab-HSE,Lab-HSE,MAT ,HSE ,Break,CHEM ,EVS ,
THU,HSE ,Lab-EPL,Lab-EPL,Lab-EPL,Break,SMECH,CHEM ,
FRI,SMECH,MAT ,MAT ,CENG,Break,EVS ,CENG,

Section: B

Day,1,2,3,4,,5,6,
MON,Lab-EPL,Lab-EPL,Lab-EPL,CENG,Break,MAT ,MEN ,
TUE,CENG,CHEM ,EVS ,HSE ,Break,SPR ,CENG,
WED,Lab-CAL,Lab-CAL,Lab-CAL,CENG,Break,MAT ,SMECH,
THU,SMECH,CHEM ,Lab-HSE,Lab-HSE,Break,MAT ,EVS ,
FRI,MAT ,EVS ,HSE ,SMECH,Break,CHEM ,MAT ,
