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

'题目：以下程序的功能是：从键盘上输入若干个学生的考试分数，
'      统计并输出最高分数和最低分数，当输入负数时结束输入，
'      输出结果，请将程序补充完整。

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
