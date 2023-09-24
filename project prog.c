/***************************************************************/
/*NAME   : Mohammed Ramadan                                    */
/*DATE   : 12/8/2023                                           */
/*Version: V1                                                  */
/***************************************************************/

#include <stdio.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "project interface.h"
#include <string.h>
/*
gcc  "project prog.c" "project app.c"
*/
u8 G_u8StudentArrayIndex = 0 ;
Student_t R_xStudents [MAX_NUMBER_OF_STUDENT] ;
void main (void)
{
	while (1)
	{
	    u8 L_u8CouseId ;
	    printf ("     (1)Add student    : \n") ;
	    printf ("     (2)Remove student : \n") ;
	    printf ("     (3)Search student : \n") ;
	    printf ("     (4)Enroll course  : \n") ;
	    printf ("     (5)End program : \n") ;
	    printf ("Enter number of operation (1-2-3-4-5) : ") ;
		fflush (stdin) ;
	    scanf  ("%c" , &L_u8CouseId) ;
	    if (L_u8CouseId < '1' || L_u8CouseId > '5')
	    {
	    	printf ("Error operation \n") ;
	    }
	    else if (L_u8CouseId == '1')
	    {
	    	APP_voidAddStudent () ;
	    }
		else if (L_u8CouseId == '2')
	    {
	    	APP_voidRemoveStudent () ;
	    }
		else if (L_u8CouseId == '3')
	    {
	    	APP_voidSearchStudent () ;
	    }
		else if (L_u8CouseId == '4')
	    {
	    	APP_voidEnrollCourse () ;
	    }
		else if (L_u8CouseId == '5')
		{
			printf ("Thank you \n") ;
			break ;
		}
		
		printf ("\n\n*********************\n\n") ;
	}
}

void APP_voidAddStudent (void) 
{
	u8 R_u8StudentName [100] ;
    u8 L_u8IndexStudentName = 0 ;
    u8 L_u8SpaceNumber = 0 ;
	u8 R_u8StudentId [10] ;
	u8 L_u8StudentGender ;
	u8 L_u8StudentYear   ;
	/*******************ask name************************/
	if (G_u8StudentArrayIndex >= (MAX_NUMBER_OF_STUDENT - 1))
	{
		printf ("Data Base of Student is Full\n") ;
	}
	else 
	{
		do 
		{			
		    printf ("Enter first, last of Student Name : ") ;
		    fflush (stdin) ;
		    gets (R_u8StudentName) ;
		    while (R_u8StudentName [L_u8IndexStudentName] != '\0')
		    {
		    	if (R_u8StudentName [L_u8IndexStudentName] == ' ')
		    	{
		    		L_u8SpaceNumber ++ ;
		    	}
		    	if (L_u8SpaceNumber > 1)
		    	{
		    		printf ("Enter only first and last name\n") ;
		    		break ;
		    	}
		    	L_u8IndexStudentName ++ ;
		    }
		    if (L_u8SpaceNumber == 1)
		    {
				strcpy (R_xStudents [G_u8StudentArrayIndex].Name , R_u8StudentName )  ;
		    	break ;
		    }
		}while (1) ;
	    /*******************ask Id**************************/
		while (1)
		{
	        printf ("Enter ID :") ;
	        gets (R_u8StudentId) ;
			u8 L_u8Flag = 0 ;
			if (R_u8StudentId [0] == '0' || strlen(R_u8StudentId) != 7)
			{
				L_u8Flag = 1 ;
			}
			for (u32 i = 0 ; i < L_u8IndexStudentName ; i++)
			{
				if (!strcmp (R_u8StudentId , R_xStudents [i].Id))
				{
					L_u8Flag = 2 ;
				}
			}
			if (L_u8Flag == 1)
			{
				printf ("ID must be 7 digits Not started with 0\n"); 
			}
			else if (L_u8Flag == 2)
			{
				printf ("ID must be uniqe\n");
			}
			else 
			{
				strcpy (R_xStudents [G_u8StudentArrayIndex].Id   , R_u8StudentId   ) ;
				break ;
			}
		}
	    /*******************ask Gender**********************/
	    printf ("Enter Gender (M for male, F for female: ") ;
	    //fflush (stdin) ;
	    scanf ("%c" , &L_u8StudentGender) ;
		R_xStudents [G_u8StudentArrayIndex].Gender = L_u8StudentGender ;
	    /*******************ask Year************************/
		while (1)
		{
			printf ("Enter acadmic Year : ") ;
	        fflush (stdin) ;
	        scanf ("%d" , &L_u8StudentYear) ;
			if (L_u8StudentYear > MAX_ACDMIC_YEARS)
			{
				printf ("Error, acadmic year larger than %d \n" , MAX_ACDMIC_YEARS) ;
			}
			else 
			{
				R_xStudents [G_u8StudentArrayIndex].Year   = L_u8StudentYear;
				break ;
			}
		}
		G_u8StudentArrayIndex ++ ;
	}
}

void APP_voidRemoveStudent (void) 
{
	u8 R_u8check_id [10] ;
	u8 L_u8Flag = 0 ;
	u32 i = 0 ;
	printf ("Enter Student Id : ") ;
	scanf ("%s" , R_u8check_id) ;
	for (; i < G_u8StudentArrayIndex ; i++)
	{
		if (!strcmp (R_u8check_id , R_xStudents [i].Id))
		{
			L_u8Flag = 1 ;
			break ;
		}
	}
	if (!L_u8Flag)
	{
		printf ("can't find that student\n") ;
	}
	else 
	{
		for (int j = i ; j < G_u8StudentArrayIndex - 1 ; j ++)
		{
			strcpy (R_xStudents [j].Name , R_xStudents [j +1].Name) ;
			strcpy (R_xStudents [j].Id , R_xStudents [j +1].Id) ;
			R_xStudents [j].Gender = R_xStudents [j +1].Gender ;
			R_xStudents [j].Year   = R_xStudents [j +1].Year   ;
			R_xStudents [j].GPA    = R_xStudents [j +1].GPA    ;
		}
		printf ("studend removed\n") ;
		G_u8StudentArrayIndex -- ;
	}
}

void APP_voidSearchStudent (void) 
{
	u8 R_u8check_id [10] ;
	u8 L_u8Flag = 0 ;
	u32 i = 0 ;
	printf ("Enter Student Id : ") ;
	scanf ("%s" , R_u8check_id) ;
	for (; i < G_u8StudentArrayIndex ; i++)
	{
		if (!strcmp (R_u8check_id , R_xStudents [i].Id))
		{
			L_u8Flag = 1 ;
			break ;
		}
	}
	if (!L_u8Flag)
	{
		printf ("can't find that student\n") ;
	}
	else 
	{
		/************calc GPA*********************/
		u32 L_u8SumHours = 0 ;
		for (u8 j = 0 ; j < MAX_ACDMIC_YEARS ; j ++)
		{
			if (R_xStudents [i].ArrGrades [j])
			{
				L_u8SumHours += R_xCources [j].CreditHours ;
			}
			R_xStudents [i].GPA += (f32) (R_xStudents [i].ArrGrades [j] * R_xCources [j].CreditHours);
		}
		R_xStudents [i].GPA /= L_u8SumHours;
		printf ("Name : %s\n"         , R_xStudents [i].Name) ;
		printf ("ID : %s\n"           , R_xStudents [i].Id) ;
		printf ("Gender : %c\n"       , R_xStudents [i].Gender) ;
		printf ("Acadmic year : %d\n" , R_xStudents [i].Year) ;
		printf ("GPA : %.2f\n"        , R_xStudents [i].GPA) ;
	}
}

void APP_voidEnrollCourse (void)
{
	u8 R_u8check_id [10] ;
	u8 L_u8Flag = 0 ;
	u8 i = 0 ;
	printf ("Enter Student Id : ") ;
	scanf ("%s" , R_u8check_id) ;
	for (; i < G_u8StudentArrayIndex ; i++)
	{
		if (!strcmp (R_u8check_id , R_xStudents [i].Id))
		{
			L_u8Flag = 1 ;
			break ;
		}
	}
	if (!L_u8Flag)
	{
		printf ("can't find that student\n") ;
	}
	else 
	{
		u8 R_Course_id [10] ;
	    u8 L_u8FlagCourse = 0 ;
	    u8 j = 0 ;
	    printf ("Enter Course Id : ") ;
	    scanf ("%s" , R_Course_id) ;
	    for (; j < MAx_NUMBER_OF_COURCES ; j++)
	    {
	    	if (!strcmp (R_Course_id , R_xCources [j].Id))
	    	{
	    		L_u8FlagCourse = 1 ;
	    		break ;
	    	}
	    }
	    if (!L_u8FlagCourse)
	    {
	    	printf ("error id course\n") ;
	    }
	    else 
	    {
			u8 L_u8Grade ;
	    	printf ("Enter your Grade : ") ;
			scanf ("%d" , &R_xStudents [i].ArrGrades [j]) ;
	    }
	}
}