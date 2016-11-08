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

'题目：已知C的公式表示如下:
'              n!
'     C=------------------
'          (n-m)!*m!
       
'函数过程fac( )求k！函数,在Fomr_Click事件中完成运算，
'请修正程序中错误。

'------------------------------------------------
Option Explicit
Private Function fac(k As Integer) As Single
    Dim x As Single, j As Integer
    '**********FOUND**********
    x = 0
    For j = 1 To k
        '**********FOUND**********
        x = x ^ j
    Next j
    fac = x
End Function
Private Sub Form_Click()
    Dim C As Single
    Dim m As Integer, n As Integer
    m = Val(InputBox("请输入一个整数(m)："))
    n = Val(InputBox("请输入一个整数(n)："))
    '**********FOUND**********
    C = fac(n) / fac(n - m) * fac(m)
    Print "C="; C
End Sub
