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
'------------------------------------------------
'������Ĵ���
'------------------------------------------------

'��Ŀ�����³��������������������ɴ�С����

'------------------------------------------------
Option Explicit
Dim A As Integer
Dim B As Integer
Dim C As Integer
Private Sub Form_Click()
    Dim nTemp As Integer
    A = Val(InputBox("Please input first integer", "����������"))
    B = Val(InputBox("Please input second integer", "����������"))
    C = Val(InputBox("Please input third integer", "����������"))
    '**********FOUND**********
    If A <= C Then
        nTemp = A
        A = B
        B = nTemp
    End If
    '**********FOUND**********
    If B <= C Then
        nTemp = A
        A = C
        C = nTemp
    End If
    '**********FOUND**********
    If A <= B Then
        nTemp = B
        B = C
        C = nTemp
    End If
    
    Print "The integers in order is"; A; B; C
End Sub