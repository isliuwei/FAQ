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
'-------------------------------------------------------
'【程序填空】
'-------------------------------------------------------

'题目：已知用inputbox函数输入两个数x和y，比较它们的大小，
'      使得x大于y。
'-------------------------------------------------------

Private Sub Form_Click()
Dim x As Single, y As Single
x = InputBox("输入数据1：")
'**********SPACE**********
y = InputBox("输入数据2:")
Print "x值", "y值"
Print x, y
If x < y Then
'**********SPACE**********
  【?】
'**********SPACE**********
  【?】
'**********SPACE**********
  【?】
End If
Print x, y
End Sub
