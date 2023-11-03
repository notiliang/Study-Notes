#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#define  ALL_TASKS_MAX     500    // 总的可供分配的定时任务数目


extern uint16 All_time;//程序运行时间

// 任务结构
typedef struct _TASK_COMPONENTS
{
    uint8 Run;                   // 程序是否运行标记   0--禁止运行    1--允许运行
    uint8 Tover;                 //计时器满足标志     0--正在计时  1--
    uint8 Timer;                 // 计时器
    uint8 ItvTime;                // 任务运行间隔时间
    int (*TaskHook)(void);     // 要运行的任务函数
    int  Back_value;
} TASK_COMPONENTS;              // 任务定义


extern TASK_COMPONENTS TaskComps[];

void TaskRemarks(void);//重置标志位
void TaskProcess(void);//任务处理

extern int progress;//任务进程
void Foreground_job();//任务顺序处理

void Assignment_count();//用户任务计数

int Task0(void);





#endif