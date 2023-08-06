#include <stdio.h> //Welcome
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MaxIteration 10
#define MaxFirstPeriods 2

// Course List, No of Classes per week list, Lab List, No of labs per week list
// Later the labs can be visualised as continuos classes
/*
[
    [
        ["MAT","EVS","FDS","BEEE","MEN","HSE"]
        [                                    ]
        [                                    ]
        [                                    ]
        [                                    ]
                                                ]
                                                    ]
*/

int SoftConstraints(int FirstPeriodsCount[], int index,
                    float Credits[]) { // No same Periods again and again
                                       // andddd... No first less credit course
  if (FirstPeriodsCount[index] <= MaxFirstPeriods) {
    if (Credits[index]>0) { // Change
      return 1;
    }
  }
  return 0;
}

int HardConstraints(int CourseNoOfHoursPerWeek[], int MainHoursPerWeek[],
                    int CourseNoOfHoursPerDay[], int MainHoursPerDay[],
                    int index, int NoOfClasses) {
  if (CourseNoOfHoursPerWeek[index] < MainHoursPerWeek[index]) {
    if (CourseNoOfHoursPerDay[index] < MainHoursPerDay[index]) {
      return 1;
    }
  }
  return 0;
}

int randomPeriods(int NoOfCourses, int NoOfPeriods, int NoOfDays,
                  int NoOfLabCourses, int FinalTimeTableIndex[][5][6],
                  int MainHoursPerWeek[], int MainHoursPerDay[],
                  int NoOfClasses, int class, int Clash_Switch,
                  char faculty_names[][10], float Credits[]) {

  int FirstPeriodsCount[NoOfCourses];
  for (int i = 0; i < NoOfCourses; i++) {
    FirstPeriodsCount[i] = 0;
  }

  int CourseNoOfHoursPerWeek[NoOfCourses];
  int CourseNoOfHoursPerDay[NoOfCourses];
  for (int i = 0; i < NoOfCourses; i++) {
    CourseNoOfHoursPerWeek[i] = 0;
  }

  for (int i = 0; i < NoOfDays; i++) {

    for (int m = 0; m < NoOfCourses; m++) {
      CourseNoOfHoursPerDay[m] = 0;
    }
    for (int j = 0; j < NoOfPeriods; j++) {
      // FinalTimeTable[i][j]=index i.e Index should be a valid subject index
      // randomly selected and validated...
      // Freeballing down here
      // printf("i=%d, j=%d\n",i,j);
      if (FinalTimeTableIndex[class][i][j] == -1) {
        int count = 0;
        while (1) {
          int index = rand() % (NoOfCourses - NoOfLabCourses);
          // printf("index=%d, i=%d, j=%d\n",index,i,j);
          if (HardConstraints(CourseNoOfHoursPerWeek, MainHoursPerWeek,
                              CourseNoOfHoursPerDay, MainHoursPerDay, index,
                              NoOfClasses) == 1) {
            int Num = 0;
            for (int indice = 0; indice < class; indice++) {
              if (Clash_Switch == 1) {
                if (FinalTimeTableIndex[indice][i][j] != index) {
                  if (strcmp(faculty_names[(FinalTimeTableIndex[indice][i][j])],
                             faculty_names[index]) != 0) {
                    Num++;
                  }
                }
              } else {
                Num++;
              }
            }
            if (Num == class) {
              if (i == 0) {
                if (SoftConstraints(FirstPeriodsCount, index, Credits) == 1) {
                  FinalTimeTableIndex[class][i][j] = index;
                  CourseNoOfHoursPerDay[index]++;
                  CourseNoOfHoursPerWeek[index]++;
                  break;
                }
              } else {
                FinalTimeTableIndex[class][i][j] = index;
                CourseNoOfHoursPerDay[index]++;
                CourseNoOfHoursPerWeek[index]++;
                break;
              }
            }
          }
          if (count > MaxIteration) {
            return -1;
          }
          count++;

          /*
            for (int c=0;c<2;c++){
                for (int a=0;a<5;a++){
                    for(int b=0;b<6;b++){
                        int index=FinalTimeTableIndex[c][a][b];
                        printf("%d,",index);
                    }
                    printf("\n");
                }
                printf("\n\n");
            }
          */
        }
      }
    }
  }
  return 1;
}

int CheckLunchBreak(int Lunch_index, int index_col, int LabTime,
                    int NoOfPeriods) {
  if (index_col >= Lunch_index) {
    if ((NoOfPeriods - index_col) >= LabTime) {
      return 1;
    }
  }
  return 0;
}

int randomAllotment(char main_courses[][10], int MainHoursPerWeek[],
                    int FinalTimeTableIndex[][5][6], int MainHoursPerDay[],
                    int NoOfClasses, int NoOfCourses, int NoOfPeriods,
                    int NoOfDays, int NoOfLabCourses, int Lunch_index,
                    int Clash_Switch, char faculty_names[][10],
                    float Credits[]) {
  // printf("\nYes Function randomallotment called");
  /*
  int NoOfCourses=11; //Change Variables
  int NoOfPeriods=6;
  int NoOfDays=5;
  int NoOfLabCourses=3;
  int Lunch_index=4;
  */

  for (int class = 0; class < NoOfClasses; class ++) {
    for (int i = 0; i < NoOfDays; i++) {
      for (int j = 0; j < NoOfPeriods; j++) {
        FinalTimeTableIndex[class][i][j] = -1;
      }
    }
  }

  for (int class = 0; class < NoOfClasses; class ++) {

    int LabHoursPerWeek[NoOfLabCourses];
    for (int i = 0; i < NoOfLabCourses; i++) {
      LabHoursPerWeek[i] = MainHoursPerWeek[NoOfCourses - NoOfLabCourses + i];
    }

    int LabHours[NoOfLabCourses];
    for (int i = 0; i < NoOfLabCourses; i++) {
      LabHours[i] = 0;
    }
    int LabHoursWeek[NoOfDays];
    for (int i = 0; i < NoOfDays; i++) {
      LabHoursWeek[i] = 0;
    }
    int LabHoursCount = 0;
    int TotalLabHours = 0;

    for (int i = 0; i < NoOfLabCourses; i++) {
      TotalLabHours += LabHoursPerWeek[i];
    }

    // Same re-iterative process needed for this also

    while (LabHoursCount < TotalLabHours) {
      int index_col = rand() % NoOfPeriods;
      int index_row = (rand()) % NoOfDays;
      int index = rand() % NoOfLabCourses;
      if (LabHours[index] == 0) {
        if (LabHoursWeek[index_row] == 0) {
          if ((((Lunch_index - index_col) >= LabHoursPerWeek[index])) ||
              (CheckLunchBreak(Lunch_index, index_col, LabHoursPerWeek[index],
                               NoOfPeriods))) {
            // Constraint
            int Switch = 0;
            for (int indice = 0; indice < class; indice++) {
              for (int slots = 0; slots < LabHoursPerWeek[index]; slots++) {
                if (FinalTimeTableIndex[indice][index_row][index_col + slots] ==
                    index + NoOfCourses - NoOfLabCourses) {
                  Switch = 1;
                }
              }
            }
            if (Switch == 0) {
              for (int i = 0; i < LabHoursPerWeek[index]; i++) {
                FinalTimeTableIndex[class][index_row][index_col + i] =
                    index + NoOfCourses - NoOfLabCourses;
              }
              LabHours[index] = LabHoursPerWeek[index];
              LabHoursCount += LabHours[index];
              LabHoursWeek[index_row] = 1;
            } else {
              continue;
            }
          }
        }
      }
    }
  }
  // printf("\nWhole Lab Allotment is Completed!\nPeriod Allocation is being
  // Performed\n");

  int Copy_FinalTimeTableIndex[NoOfClasses][NoOfDays][NoOfPeriods];
  for (int class = 0; class < NoOfClasses; class ++) {
    for (int i = 0; i < NoOfDays; i++) {
      for (int j = 0; j < NoOfPeriods; j++) {
        Copy_FinalTimeTableIndex[class][i][j] =
            FinalTimeTableIndex[class][i][j];
      }
    }
  }
  // int class=0;printf("\nCopied TimeTable Copy!");
  int class = 0;
  int Number =
      randomPeriods(NoOfCourses, NoOfPeriods, NoOfDays, NoOfLabCourses,
                    FinalTimeTableIndex, MainHoursPerWeek, MainHoursPerDay,
                    NoOfClasses, class, Clash_Switch, faculty_names, Credits);
  // printf("Number=%d\n",Number);

  // printf("\nInitial Number Value Found");

  if (Number == 1) {
    int class = 1;
  }

  while (class < NoOfClasses) {
    while (Number == -1) {
      for (int i = 0; i < NoOfDays; i++) {
        for (int j = 0; j < NoOfPeriods; j++) {
          FinalTimeTableIndex[class][i][j] =
              Copy_FinalTimeTableIndex[class][i][j];
        }
      }
      Number = randomPeriods(NoOfCourses, NoOfPeriods, NoOfDays, NoOfLabCourses,
                             FinalTimeTableIndex, MainHoursPerWeek,
                             MainHoursPerDay, NoOfClasses, class, Clash_Switch,
                             faculty_names, Credits);
    }
    class ++;
    Number = -1;
  }
  // printf("\nFinding Again!");
}

void Inputs(char main_courses[][10], int MainHoursPerWeek[],
            int MainHoursPerDay[], char faculty_names[][10], float Credits[],int X) {
  FILE *ptr;
  char ch;
  char Text[300];
  char filename[20];
  char file[10];

  if (X%6==0){
    strcpy(filename,"Inputs/CSE.csv");
    strcpy(file,"CSE");
  }else if (X%6==1){
    strcpy(filename,"Inputs/ECE.csv");
    strcpy(file,"ECE");
  }else if(X%6==2){
    strcpy(filename,"Inputs/EEE.csv");
    strcpy(file,"EEE");
  }else if(X%6==3){
    strcpy(filename,"Inputs/MECH.csv");
    strcpy(file,"MECH");
  }else if(X%6==4){
    strcpy(filename,"Inputs/CIVIL.csv");
    strcpy(file,"CIVIL");
  }else{
    strcpy(filename,"Inputs/CHEM.csv");
    strcpy(file,"CHEM");
  }

  printf("Department: %s\n",file);

  /*printf("Enter the filename: ");
  scanf("%s",filename);
  */
  ptr = fopen(filename, "r");
  if (NULL == ptr) {
    printf("file can't be opened \n");
  } else {
    int count = 0;
    do {
      ch = fgetc(ptr);
      if (ch != EOF) {
        Text[count] = ch;
        count++;
      } else {
        Text[count] = '\0';
        break;
      }
    } while (ch != EOF);
  }
  fclose(ptr);
  int num = 0;
  char chr = Text[num];
  while (chr != '\0') {
    if (chr == '\n') {
      Text[num] = ',';
    }
    num++;
    chr = Text[num];
  }
  char *token = strtok(Text, ",");
  int count = 0;
  int INDEX = 0;
  while (token != NULL) {
    if (count % 5 == 0) {
      strcpy(main_courses[INDEX], token);
    } else if (count % 5 == 1) {
      MainHoursPerWeek[INDEX] = atoi(token);
    } else if (count % 5 == 2) {
      MainHoursPerDay[INDEX] = atoi(token);
    } else if (count % 5 == 3) {
      strcpy(faculty_names[INDEX], token);
      INDEX++;
    } else {
      Credits[INDEX] = atoi(token);
    }
    count++;
    token = strtok(NULL, ",");
  }
}

int main(){
  FILE *FPS=fopen("output.csv", "w");
  fclose(FPS);
  printf("Enter 'yes' if you want to check for reqular class clashes otherwise "
         "'no': ");

  char Option[3];

  int NoOfCourses = 11; // Change Variables
  int NoOfPeriods = 6;
  int NoOfDays = 5;
  int NoOfLabCourses = 3;
  int Lunch_index = 4;

  /*

  printf("\nEnter total no of courses along with lab courses: ");
  scanf("%d",&NoOfCourses);
  printf("\nEnter Total no of periods per day: ");
  scanf("%d",&NoOfPeriods);
  printf("\nEnter no of working days in a week: ");
  scanf("%d",&NoOfDays);
  printf("\nEnter no of Lab courses: ");
  scanf("%d",&NoOfLabCourses);
  printf("\nEnter the lunch break index: ");
  scanf("%d",&Lunch_index);

  */

  srand(time(0));

  scanf("%s", Option);
  int Clash_Switch = 0;
  if ((strcmp(Option, "yes")) == 0) {
    Clash_Switch = 1;
  }

  printf("Enter no of Departments: ");
  int NoOfDepartments;
  scanf("%d",&NoOfDepartments);


  printf("\nEnter no of Sections: ");
  int NoOfClasses = 0;
  scanf("%d", &NoOfClasses);

  printf("Started\n");
  /*

  char main_courses[][10]={"MAT ","EVS ","FDS ","FPSD","BEEE","MEN ","SPR ","HSE
  ","Lab-FPSD","Lab-HSE","Lab-EPL"}; int
  MainHoursPerWeek[]={5,3,3,3,4,1,1,2,3,2,3}; int MainHoursPerDay[]=
  {2,1,1,1,1,1,1,1,3,2,3};


  */
  FILE *OUT=freopen("output.csv", "a+", stdout);

  char Names[27];
  int i;
  for(i=0; i<26; i++){
    Names[i] = 'A'+i;
  }
  Names[i]='\0';






  for (int X=0;X<NoOfDepartments;X++){  //NoOfDepts
    
    char main_courses[NoOfCourses][10];
    int MainHoursPerWeek[NoOfCourses];
    int MainHoursPerDay[NoOfCourses];
    char faculty_names[NoOfCourses][10];
    float Credits[NoOfCourses];

    // printf("ok1");

     //Inputfiles
    

    Inputs(main_courses, MainHoursPerWeek, MainHoursPerDay, faculty_names,
            Credits,X);
    printf("\nDepartment Faculty Codes: \n");
    for (int N1=0;N1<NoOfCourses;N1++){
      printf("%s,",main_courses[N1]);
    }
    printf("\n");
    for (int N2=0;N2<NoOfCourses;N2++){
      printf("%s,",faculty_names[N2]);
    }
    printf("\n");

    
    
    int Hours_Count = 0;
    for (int i = 0; i < NoOfCourses; i++) {
        Hours_Count += MainHoursPerWeek[i];
    }
    if (Hours_Count == (NoOfDays * NoOfPeriods)) {

        int FinalTimeTableIndex[NoOfClasses][5][6];
        randomAllotment(main_courses, MainHoursPerWeek, FinalTimeTableIndex,
                        MainHoursPerDay, NoOfClasses, NoOfCourses, NoOfPeriods,
                        NoOfDays, NoOfLabCourses, Lunch_index, Clash_Switch,
                        faculty_names, Credits);
        /*
        for (int i=0;i<11;i++){
            printf("%d: %s, ",i,main_courses[i]);
        }

        printf("\n\n");


        for (int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                int index=FinalTimeTableIndex[i][j];
                printf("%d,",index);
                }
            printf("\n");

        }
        printf("\n\n");

        */

        char WeekDays[5][3] = {{'M', 'O', 'N'},
                                {'T', 'U', 'E'},
                                {'W', 'E', 'D'},
                                {'T', 'H', 'U'},
                                {'F', 'R', 'I'}};
        for (int class = 0; class < NoOfClasses; class ++) {
            printf("Section: %c\n\n",Names[class]);
            printf("Day,");
            for (int X = 0; X < 6; X++) {
              if (X==Lunch_index){
                printf(",");
              }
            printf("%d,", X + 1);
            }
            printf("\n");

            for (int i = 0; i < 5; i++) {
            for (int k = 0; k < 3; k++) {

                printf("%c", WeekDays[i][k]);
            }
            printf(",");
            for (int j = 0; j < NoOfPeriods; j++) {
                int index = FinalTimeTableIndex[class][i][j];
                if (index != -1) {
                  if (j==Lunch_index){
                    printf("Break,");
                  }
                
                  printf("%s,", main_courses[index]);
                } else {
                printf("%s,", "---");
                }
            }
            printf("\n");
            }
            printf("\n");
        }
        } else {
        printf("The No of Hours inputted is not correct!");
        }
  printf("\n\n\n\n");
  }
  // printf("\nDone!");
}
  