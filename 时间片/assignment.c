#include "headfile.h"

/**************************************************************************************
   Variable definition                            
**************************************************************************************/
 TASK_COMPONENTS TaskComps[ALL_TASKS_MAX] = //必须确定成员数量，否则assign_count()计数不准确
{
  //Base_assignment(基础任务)
    {0,0, 10, 10, Task0,0},                    // 任务0 计时10ms    //0
    {1,0,  5,  5, get_speed,0},                // 获取速度         //1
    {0, 0 , 5 ,5 ,calculate,0},                //计算                  //2 
    {1,0, 200, 200, screen_display,0},         // 屏幕显示    //3
    {0,0, 5, 5, MotorOutput,0},                 // 电机输出         //4
   
   //Foreground_job(前台任务开始) 
    {0,0, 1, 1, JOB_To_QR_code_area,0},  //5     去往扫码地点
    {0,0, 1, 1, JOB_QR_code_scan,0}, //6    扫描二维码
    {0,0, 1, 1, JOB_To_Color_scan_area,0}, //7    去往颜色识别地点
    {0,0, 1, 1,JOB_color_scan ,0},     //8   上层颜色识别 
   
//    //原料区上层抓取
    {0,0, 1, 1,JOB_To_M_UP_T1,0},//9    去往原料区抓取地点1 
    {0,0, 1, 1,JOB_Do_M_UP_T1,0},    
    {0,0, 1, 1,JOB_To_M_UP_T2,0},
    {0,0, 1, 1,JOB_Do_M_UP_T2,0},     
    {0,0, 1, 1,JOB_To_M_UP_T3,0},
    {0,0, 1, 1,JOB_Do_M_UP_T3,0},   
// 
//    //粗加工区放置1
    {0,0, 1, 1,JOB_To_Rough_machining_noarea1,0},   //缓冲区     
    
    {0,0, 1, 1,JOB_To_R_UP_P1,0},  
    {0,0, 1, 1,JOB_Do_R_UP_P1,0},      
    {0,0, 1, 1,JOB_To_R_UP_P2,0}, 
    {0,0, 1, 1,JOB_Do_R_UP_P2,0},            
    {0,0, 1, 1,JOB_To_R_UP_P3,0},      
    {0,0, 1, 1,JOB_Do_R_UP_P3,0}, 
    //粗加工区抓取
    {0,0, 1, 1,JOB_To_R_UP_T1,0},  
    {0,0, 1, 1,JOB_Do_R_UP_T1,0},     
    {0,0, 1, 1,JOB_To_R_UP_T2,0},    
    {0,0, 1, 1,JOB_Do_R_UP_T2,0},     
    {0,0, 1, 1,JOB_To_R_UP_T3,0}, 
    {0,0, 1, 1,JOB_Do_R_UP_T3,0},  
    
    
    //半成品区第一次放置
    {0,0, 1, 1,JOB_To_H_UP_P1,0},    
    {0,0, 1, 1,JOB_Do_H_UP_P1,0},     
    {0,0, 1, 1,JOB_To_H_UP_P2,0},   
    {0,0, 1, 1,JOB_Do_H_UP_P2,0},     
    {0,0, 1, 1,JOB_To_H_UP_P3,0}, 
    {0,0, 1, 1,JOB_Do_H_UP_P3,0},   
       
    //****下层抓取
    {0,0, 1, 1,JOB_To_Color_scan_down_area,0},    //去往下层颜色识别位置  颜色识别动作
    {0,0, 1, 1,JOB_color_scan_down,0}, 
    
    {0,0, 1, 1,JOB_To_M_down_ready1,0},//去往第一次抓取等待区  抓取等待动作
    {0,0, 1, 1,JOB_To_M_down_T1,0},//去往抓取位置
    {0,0, 1, 1,JOB_To_catch1,0},//抓取
    {0,0, 1, 1,JOB_To_M_down_ready_Back1,0},
    
    {0,0, 1, 1,JOB_To_M_down_ready2,0},//去往第二次抓取等待位置  放置1
    {0,0, 1, 1,JOB_To_M_down_T2,0},//去往抓取位置
    {0,0, 1, 1,JOB_To_catch2,0},//抓取
    {0,0, 1, 1,JOB_To_M_down_ready_Back2,0},
  
    {0,0, 1, 1,JOB_To_M_down_ready3,0},//去往第三次抓取等待位置
    {0,0, 1, 1,JOB_To_M_down_T3,0},//去往抓取位置
    {0,0, 1, 1,JOB_To_catch3,0},//抓取 
    {0,0, 1, 1,JOB_To_M_down_ready_Back3,0},
  
//    //粗加工区放置2
    {0,0, 1, 1,JOB_To_Rough_machining_noarea1,0},   //缓冲区     
    
    {0,0, 1, 1,JOB_To_R_down_P1,0},  
    {0,0, 1, 1,JOB_Do_R_down_P1,0},      
    {0,0, 1, 1,JOB_To_R_down_P2,0}, 
    {0,0, 1, 1,JOB_Do_R_down_P2,0},            
    {0,0, 1, 1,JOB_To_R_down_P3,0},      
    {0,0, 1, 1,JOB_Do_R_down_P3,0}, 
    //粗加工区抓取2
    {0,0, 1, 1,JOB_To_R_down_T1,0},  
    {0,0, 1, 1,JOB_Do_R_down_T1,0},     
    {0,0, 1, 1,JOB_To_R_down_T2,0},    
    {0,0, 1, 1,JOB_Do_R_down_T2,0},     
    {0,0, 1, 1,JOB_To_R_down_T3,0}, 
    {0,0, 1, 1,JOB_Do_R_down_T3,0},  

    //半成品区第二次放置  码垛
    {0,0, 1, 1,JOB_To_H_down_P1,0},    
    {0,0, 1, 1,JOB_Do_H_down_P1,0},     
    {0,0, 1, 1,JOB_To_H_down_P2,0},   
    {0,0, 1, 1,JOB_Do_H_down_P2,0},     
    {0,0, 1, 1,JOB_To_H_down_P3,0}, 
    {0,0, 1, 1,JOB_Do_H_down_P3,0},       
    
    {0,0, 1, 1,JOB_To_Rough_machining_noarea2,0}, //缓冲区2   
    {0,0, 1, 1,JOB_To_home,0}, 
     // 这里添加你的任务。。。。
};


/**************************************************************************************
* FunctionName   : Assignment_count()
* Description    : 用户任务计数 在初始化中调用此函数
* EntryParameter : None
* ReturnValue    : None
**************************************************************************************/
 
int TASKS_MAX=0;//用户所写的任务数量

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
* Description    : 任务标志处理  在定时器的中断服务函数中调用此函数
* EntryParameter : None
* ReturnValue    : None
**************************************************************************************/
void TaskRemarks(void)
{
    uint8 i;
    for (i=0; i<TASKS_MAX; i++)          // 逐个任务时间处理
    {
         if (TaskComps[i].Timer)          // 时间不为0
        {
            TaskComps[i].Timer--;         // 减去一个节拍
            if (TaskComps[i].Timer == 0)       // 时间减完了
            {
                 TaskComps[i].Timer = TaskComps[i].ItvTime;       // 恢复计时器值，重新下一次
                 TaskComps[i].Tover = 1;           // 任务可以运行
            }
        }
   }
}

/**************************************************************************************
* FunctionName   : TaskProcess()
* Description    : 任务处理
* EntryParameter : None
* ReturnValue    : None
**************************************************************************************/
void TaskProcess(void)
{
    uint8 i;
    for (i=0; i<TASKS_MAX; i++)           // 逐个任务时间处理
    {  
         if (TaskComps[i].Tover&&TaskComps[i].Run)           // 时间不为0并且允许执行
        {
             TaskComps[i].Back_value=TaskComps[i].TaskHook();// 运行任务并获得返回值
             TaskComps[i].Tover = 0;          // 标志清0
        }       
    }   
}

/**************************************************************************************
* FunctionName   : Foreground_job()
* Description    : 前台任务调度
* EntryParameter : None
* ReturnValue    : None
**************************************************************************************/
 
int progress=5;//任务进程（0-4为基础任务）

void Foreground_job()
{
  TaskComps[progress].Run=1;//前台任务开启
  if(TaskComps[progress].Back_value==1)//若此任务完成
  {
  progress++;//执行下一任务
  TaskComps[progress-1].Run=0;//关闭上一个已完成任务
  }
  if(progress>=TASKS_MAX)progress=TASKS_MAX-1;
  
}





/*计时*/
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
