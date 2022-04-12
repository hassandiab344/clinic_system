#ifndef HEAD_H
#define HEAD_H
typedef struct Patient_Node Patient;
struct Patient_Node{
	u8 Patient_Name[100];
	u32 Patient_Age;
	u8 Patient_Gender[10];
	u32 Patient_ID;
	Patient *next;
};
void Add_Patient(u8 copy_u8Patient_Name[],u32 copy_u32Patient_Age,u8 copy_u8Patient_Gender[],u32 copy_u32Patient_ID);
void Edit_List(u32 copy_u32Patient_ID);
void Delete_Patient(u32 copy_u32Patient_INFO);
void Time_Reservation();
void Cancel_Reservation(u32 copy_u32ID);
void Print_Patient_List(u32 copy_u32Patient_ID);
void print_Patient_Reservation();

#endif