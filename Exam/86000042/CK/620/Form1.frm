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

'�������н�����ͼ��ʾ �������10��100���ڵ�����������Ϊ�㣩��
'�����е����������С����ѡ������

'-------------------------------------------------------
Private Sub Form_Click()
    Dim Max, Min As Integer
    Randomize
'**********SPACE**********
    x = Int(100 * Rnd + 1)
    Max = x: Min = x
    Print x;
    For i = 1 To 9
    x = Int(100 * Rnd + 1)
    Print x;
 '**********SPACE**********
    If x > Max Then Max = x
    If x < Min Then Min = x
    Next i
    Print
    Print "Max="; Max, "Min="; Min
End Sub

