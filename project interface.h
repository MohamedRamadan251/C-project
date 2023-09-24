/***************************************************************/
/*NAME   : Mohammed Ramadan                                    */
/*DATE   : 12/8/2023                                           */
/*Version: V1                                                  */
/***************************************************************/

#ifndef PROJECT_INTERFACE_H
#define PROJECT_INTERFACE_H

#define MAX_NUMBER_OF_STUDENT 200
#define MAX_ACDMIC_YEARS      5
#define MAx_NUMBER_OF_COURCES 5

typedef struct 
{
	u8 Id   [10]                     ;
	u8 Gender                        ;
	u8 Year                          ;
	f32 GPA                          ;
	u32 ArrGrades [MAX_ACDMIC_YEARS] ;
	u8 Name [100]                    ;
}Student_t ;

typedef struct 
{
	u8 CreditHours ;
	u8 Id   [10]  ;
	u8 Name [100] ;
}Course_t ;

Course_t  R_xCources  [MAx_NUMBER_OF_COURCES] =
{
  {.Name = "Engineering Economics"     , .Id = "L12" , .CreditHours = 40},
  {.Name = "Power Systems Analysis"    , .Id = "M13" , .CreditHours = 45},
  {.Name = "Electronic Circuits"       , .Id = "R18" , .CreditHours = 50},
  {.Name = "Engineering Management"    , .Id = "X24" , .CreditHours = 55},
  {.Name = "Environmental Engineering" , .Id = "C24" , .CreditHours = 60}
}; 

/*
Function Name :APP_voidAddStudent
Function input :void
Function output :void
Function Discription : ask name (must be first & last name),
                           Id (7 digit not start with 0 and uniqe), 
						   Gender (Male 'M' or Female 'F') ,
						   Year (1 --> MAX_ACDMIC_YEARS)
*/
void APP_voidAddStudent    (void) ;

/*
Function Name :APP_voidRemoveStudent
Function input :void
Function output :void
Function Discription : ask id and remove student from data base
*/
void APP_voidRemoveStudent (void) ;

/*
Function Name :APP_voidSearchStudent
Function input :void
Function output :void
Function Discription :ask id and print data of student
*/
void APP_voidSearchStudent (void) ;

/*
Function Name :APP_voidEnrollCourse
Function input :void
Function output :void
Function Discription :ask id  of student ask id of course add new course 
*/
void APP_voidEnrollCourse (void) ;
#endif 