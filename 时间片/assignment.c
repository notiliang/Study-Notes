#include "headfile.h"

/**************************************************************************************
   Variable definition                            
**************************************************************************************/
 TASK_COMPONENTS TaskComps[ALL_TASKS_MAX] = //����ȷ����Ա����������assign_count()������׼ȷ
{
  //Base_assignment(��������)
    {0,0, 10, 10, Task0,0},                    // ����0 ��ʱ10ms    //0
    {1,0,  5,  5, get_speed,0},                // ��ȡ�ٶ�         //1
    {0, 0 , 5 ,5 ,calculate,0},                //����                  //2 
    {1,0, 200, 200, screen_display,0},         // ��Ļ��ʾ    //3
    {0,0, 5, 5, MotorOutput,0},                 // ������         //4
   
   //Foreground_job(ǰ̨����ʼ) 
    {0,0, 1, 1, JOB_To_QR_code_area,0},  //5     ȥ��ɨ��ص�
    {0,0, 1, 1, JOB_QR_code_scan,0}, //6    ɨ���ά��
    {0,0, 1, 1, JOB_To_Color_scan_area,0}, //7    ȥ����ɫʶ��ص�
    {0,0, 1, 1,JOB_color_scan ,0},     //8   �ϲ���ɫʶ�� 
   
//    //ԭ�����ϲ�ץȡ
    {0,0, 1, 1,JOB_To_M_UP_T1,0},//9    ȥ��ԭ����ץȡ�ص�1 
    {0,0, 1, 1,JOB_Do_M_UP_T1,0},    
    {0,0, 1, 1,JOB_To_M_UP_T2,0},
    {0,0, 1, 1,JOB_Do_M_UP_T2,0},     
    {0,0, 1, 1,JOB_To_M_UP_T3,0},
    {0,0, 1, 1,JOB_Do_M_UP_T3,0},   
// 
//    //�ּӹ�������1
    {0,0, 1, 1,JOB_To_Rough_machining_noarea1,0},   //������     
    
    {0,0, 1, 1,JOB_To_R_UP_P1,0},  
    {0,0, 1, 1,JOB_Do_R_UP_P1,0},      
    {0,0, 1, 1,JOB_To_R_UP_P2,0}, 
    {0,0, 1, 1,JOB_Do_R_UP_P2,0},            
    {0,0, 1, 1,JOB_To_R_UP_P3,0},      
    {0,0, 1, 1,JOB_Do_R_UP_P3,0}, 
    //�ּӹ���ץȡ
    {0,0, 1, 1,JOB_To_R_UP_T1,0},  
    {0,0, 1, 1,JOB_Do_R_UP_T1,0},     
    {0,0, 1, 1,JOB_To_R_UP_T2,0},    
    {0,0, 1, 1,JOB_Do_R_UP_T2,0},     
    {0,0, 1, 1,JOB_To_R_UP_T3,0}, 
    {0,0, 1, 1,JOB_Do_R_UP_T3,0},  
    
    
    //���Ʒ����һ�η���
    {0,0, 1, 1,JOB_To_H_UP_P1,0},    
    {0,0, 1, 1,JOB_Do_H_UP_P1,0},     
    {0,0, 1, 1,JOB_To_H_UP_P2,0},   
    {0,0, 1, 1,JOB_Do_H_UP_P2,0},     
    {0,0, 1, 1,JOB_To_H_UP_P3,0}, 
    {0,0, 1, 1,JOB_Do_H_UP_P3,0},   
       
    //****�²�ץȡ
    {0,0, 1, 1,JOB_To_Color_scan_down_area,0},    //ȥ���²���ɫʶ��λ��  ��ɫʶ����
    {0,0, 1, 1,JOB_color_scan_down,0}, 
    
    {0,0, 1, 1,JOB_To_M_down_ready1,0},//ȥ����һ��ץȡ�ȴ���  ץȡ�ȴ�����
    {0,0, 1, 1,JOB_To_M_down_T1,0},//ȥ��ץȡλ��
    {0,0, 1, 1,JOB_To_catch1,0},//ץȡ
    {0,0, 1, 1,JOB_To_M_down_ready_Back1,0},
    
    {0,0, 1, 1,JOB_To_M_down_ready2,0},//ȥ���ڶ���ץȡ�ȴ�λ��  ����1
    {0,0, 1, 1,JOB_To_M_down_T2,0},//ȥ��ץȡλ��
    {0,0, 1, 1,JOB_To_catch2,0},//ץȡ
    {0,0, 1, 1,JOB_To_M_down_ready_Back2,0},
  
    {0,0, 1, 1,JOB_To_M_down_ready3,0},//ȥ��������ץȡ�ȴ�λ��
    {0,0, 1, 1,JOB_To_M_down_T3,0},//ȥ��ץȡλ��
    {0,0, 1, 1,JOB_To_catch3,0},//ץȡ 
    {0,0, 1, 1,JOB_To_M_down_ready_Back3,0},
  
//    //�ּӹ�������2
    {0,0, 1, 1,JOB_To_Rough_machining_noarea1,0},   //������     
    
    {0,0, 1, 1,JOB_To_R_down_P1,0},  
    {0,0, 1, 1,JOB_Do_R_down_P1,0},      
    {0,0, 1, 1,JOB_To_R_down_P2,0}, 
    {0,0, 1, 1,JOB_Do_R_down_P2,0},            
    {0,0, 1, 1,JOB_To_R_down_P3,0},      
    {0,0, 1, 1,JOB_Do_R_down_P3,0}, 
    //�ּӹ���ץȡ2
    {0,0, 1, 1,JOB_To_R_down_T1,0},  
    {0,0, 1, 1,JOB_Do_R_down_T1,0},     
    {0,0, 1, 1,JOB_To_R_down_T2,0},    
    {0,0, 1, 1,JOB_Do_R_down_T2,0},     
    {0,0, 1, 1,JOB_To_R_down_T3,0}, 
    {0,0, 1, 1,JOB_Do_R_down_T3,0},  

    //���Ʒ���ڶ��η���  ���
    {0,0, 1, 1,JOB_To_H_down_P1,0},    
    {0,0, 1, 1,JOB_Do_H_down_P1,0},     
    {0,0, 1, 1,JOB_To_H_down_P2,0},   
    {0,0, 1, 1,JOB_Do_H_down_P2,0},     
    {0,0, 1, 1,JOB_To_H_down_P3,0}, 
    {0,0, 1, 1,JOB_Do_H_down_P3,0},       
    
    {0,0, 1, 1,JOB_To_Rough_machining_noarea2,0}, //������2   
    {0,0, 1, 1,JOB_To_home,0}, 
     // �������������񡣡�����
};


/**************************************************************************************
* FunctionName   : Assignment_count()
* Description    : �û�������� �ڳ�ʼ���е��ô˺���
* EntryParameter : None
* ReturnValue    : None
**************************************************************************************/
 
int TASKS_MAX=0;//�û���д����������

void Assignment_count()
{
  int i=0;
  for(i=0;i<=ALL_TASKS_MAX;i++)
  {
    if(TaskComps[i].ItvTime!=0)TASKS_MAX++;
  }
}

/**************************************************************************************
* FunctionName   : TaskRemarks()
* Description    : �����־����  �ڶ�ʱ�����жϷ������е��ô˺���
* EntryParameter : None
* ReturnValue    : None
**************************************************************************************/
void TaskRemarks(void)
{
    uint8 i;
    for (i=0; i<TASKS_MAX; i++)          // �������ʱ�䴦��
    {
         if (TaskComps[i].Timer)          // ʱ�䲻Ϊ0
        {
            TaskComps[i].Timer--;         // ��ȥһ������
            if (TaskComps[i].Timer == 0)       // ʱ�������
            {
                 TaskComps[i].Timer = TaskComps[i].ItvTime;       // �ָ���ʱ��ֵ��������һ��
                 TaskComps[i].Tover = 1;           // �����������
            }
        }
   }
}

/**************************************************************************************
* FunctionName   : TaskProcess()
* Description    : ������
* EntryParameter : None
* ReturnValue    : None
**************************************************************************************/
void TaskProcess(void)
{
    uint8 i;
    for (i=0; i<TASKS_MAX; i++)           // �������ʱ�䴦��
    {  
         if (TaskComps[i].Tover&&TaskComps[i].Run)           // ʱ�䲻Ϊ0��������ִ��
        {
             TaskComps[i].Back_value=TaskComps[i].TaskHook();// �������񲢻�÷���ֵ
             TaskComps[i].Tover = 0;          // ��־��0
        }       
    }   
}

/**************************************************************************************
* FunctionName   : Foreground_job()
* Description    : ǰ̨�������
* EntryParameter : None
* ReturnValue    : None
**************************************************************************************/
 
int progress=5;//������̣�0-4Ϊ��������

void Foreground_job()
{
  TaskComps[progress].Run=1;//ǰ̨������
  if(TaskComps[progress].Back_value==1)//�����������
  {
  progress++;//ִ����һ����
  TaskComps[progress-1].Run=0;//�ر���һ�����������
  }
  if(progress>=TASKS_MAX)progress=TASKS_MAX-1;
  
}





/*��ʱ*/
int task0_time;
uint16 All_time;
int Task0(void)
{
    task0_time++;
    if(task0_time>=100)
    {
    task0_time=0;
    All_time++;
    }
//    if(All_time>=300)
//    BUZZ_ON;
     
    return 0;
}
