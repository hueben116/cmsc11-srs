A code which serves as a database system of the records of CMSC11 students can also be referred as a CMSC11 Student Registration System. The basic features of the database are the following:

  1.  A unique password - for the user to be able to keep the student record safe from all possible alterations without his/her permission.
  
  2.  Create, Update and Delete Student Records - Under create a student record the user will choose between creating through keyboard input or to upload a file to be synced inside the database, through the keyboard input the user will have to enter the surname, firstname, cmsc11 section, score in hex1, score in hex2, score in hex3 and 2 subjects. After succesfully creating student records there will also be a choice to update the informations of the uploaded or inputted student. Moreover, this also includes a feature where the user will be able to delete a student record.
  
  3.  Display list of all student records - Display the records of all students in alphabetical order of the surname.
  
      3.a Summary statistics for each Hands-On Exams at the bottom - Apart from just displaying the student records there is        also an extra feauture where it is able to Calculate and display the following summary statistics for each hands-on exam:
          ▪ Lowest score
          ▪ Highest score
          ▪ Average score rounded to 3 decimal places
          ▪ Standard deviation rounded to 3 decimal places
          ▪ Sum of all three Hands-On (Hex) Scores
          ▪ Grade – where it will be calculated based on the total hex score with the following grading system below:
              • HD (High Distinction) = total score of 135 or more
              • D (Distinction) = total score of 120 to 134
              • P (Pass) = total score of 100 to 119
              • C (Credit) = total score of 75 to 99
              • F (Fail) = total score of 74 and below
          
  4.  Export masterlist and save as .csv file - The code is also designed to be able to export the masterlist to a file and save it as masterlist.csv with one student record per line and each information separated by a comma.
  
  5.  Enrol or Drop a subject (maximum of 3 subjects per student) - The user is given the freehand to enrol or drop a subject in the code as long as he enters "none" if they drop a subject and just enter the subject code if they were to enroll.
  
  6.  Search Student Record - It is also able to search a student record using student’s last name and display the matched record(s). Where the search is case insensitive so, when user types in simpson, it must display any records that have the
surname simpson or Simpson, etc.

  7.  Create, Update and Delete Subject - Under create a subject record the user will choose between creating through keyboard input or to upload a file to be synced inside the database, through the keyboard input the user will have to enter the subject code, and subject title. After succesfully creating subject records there will also be a choice to update the informations of the uploaded or inputted subject. Moreover, this also includes a feature where the user will be able to delete a subject record.
  
  8.  Search Subject - The code was created to be able to search a subject given that the user will input the subjectcode/ subjectID and displays the information of the subject.
