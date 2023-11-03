#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#define  ALL_TASKS_MAX     500    // �ܵĿɹ�����Ķ�ʱ������Ŀ


extern uint16 All_time;//��������ʱ��

// ����ṹ
typedef struct _TASK_COMPONENTS
{
    uint8 Run;                   // �����Ƿ����б��   0--��ֹ����    1--��������
    uint8 Tover;                 //��ʱ�������־     0--���ڼ�ʱ  1--
    uint8 Timer;                 // ��ʱ��
    uint8 ItvTime;                // �������м��ʱ��
    int (*TaskHook)(void);     // Ҫ���е�������
    int  Back_value;
} TASK_COMPONENTS;              // ������


extern TASK_COMPONENTS TaskComps[];

void TaskRemarks(void);//���ñ�־λ
void TaskProcess(void);//������

extern int progress;//�������
void Foreground_job();//����˳����

void Assignment_count();//�û��������

int Task0(void);





#endif