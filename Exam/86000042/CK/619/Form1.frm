VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
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

'�������н�����ͼ��ʾ����������3�����������ǰ��ɴ�С��
'˳�������-1Ϊ������־��

'-------------------------------------------------------
Private Sub Form_Click()
 '**********SPACE**********
    Do While ��?��
        a = Val(InputBox("�������һ������"))
        If a = -1 Then Exit Sub
        b = Val(InputBox("������ڶ�������"))
        c = Val(InputBox("���������������"))
  '**********SPACE**********
        If ��?�� Then t = a: a = b: b = t
        If a < c Then t = a: a = c: c = t
  '**********SPACE**********
        If b < c Then t = b: ��?��
        Print a, b, c
    Loop
End Sub

