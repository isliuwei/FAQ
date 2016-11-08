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

'程序运行界面如图所示。键盘输入3个数，将它们按由大到小的
'顺序输出，-1为结束标志。

'-------------------------------------------------------
Private Sub Form_Click()
 '**********SPACE**********
    Do While 【?】
        a = Val(InputBox("请输入第一个数："))
        If a = -1 Then Exit Sub
        b = Val(InputBox("请输入第二个数："))
        c = Val(InputBox("请输入第三个数："))
  '**********SPACE**********
        If 【?】 Then t = a: a = b: b = t
        If a < c Then t = a: a = c: c = t
  '**********SPACE**********
        If b < c Then t = b: 【?】
        Print a, b, c
    Loop
End Sub

