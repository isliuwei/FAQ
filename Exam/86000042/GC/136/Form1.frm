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
'������Ĵ�
'------------------------------------------------

'��Ŀ��������Ϊ��ӡ����ͼ�Σ�
'   *
'   **
'   ***
'   ****
'   *****

'------------------------------------------------
Option Explicit
Private Sub Form_Click()
Cls
Dim i As Integer
Dim j As Integer
'**********FOUND**********
For i = 1 To 7
'**********FOUND**********
    For j = 1 To 5
        Print "*";
'**********FOUND**********
    Loop
Print
Next i
End Sub
