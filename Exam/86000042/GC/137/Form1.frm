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

'��Ŀ����s=72+102+132+����832��ֵ��

'------------------------------------------------
Option Explicit
Private Sub Form_Click()
Cls
Dim s As Long
Dim i As Integer
'**********FOUND**********
s = 1
'**********FOUND**********
For i = 7 To 832
s = s + i
'**********FOUND**********
loop  30
Print s
End Sub