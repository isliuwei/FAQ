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
   StartUpPosition =   3  '窗口缺省
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'------------------------------------------------
'【程序改错】
'------------------------------------------------

'题目：求s=72+102+132+……832的值。

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
