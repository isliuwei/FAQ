VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   StartUpPosition =   3  '����ȱʡ
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'-------------------------------------------------------
'��������ա�
'-------------------------------------------------------

'��Ŀ�����³���Ĺ����ǣ��Ӽ������������ɸ�ѧ���Ŀ��Է�����
'      ͳ�Ʋ������߷�������ͷ����������븺��ʱ�������룬
'      ���������뽫���򲹳�������

'-------------------------------------------------------
Private Sub Form_Click()
Dim x, amax, amin As Single
x = InputBox("Enter a score")
amax = x
amin = x
'**********SPACE**********
Do While x > 0
If x > amax Then
 amax = x
 End If
 '**********SPACE**********
 If x < amin Then
 amin = x
 End If
 x = InputBox("Enter a score")
 Loop
 Print "max="; amax, "min="; amin

End Sub