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

'题目：下面程序可输出如下图形：
'           *
'          ***
'         *****
'        *******
'       *********

'------------------------------------------------
Option Explicit
Private Sub Form_Click()
Dim m As Integer, n As Integer, s As String, i As Integer, j As Integer
n = 4
m = 1
s = "*"
For i = 5 To 1 Step -1
   '**********FOUND**********
   Print Spc(n)
   For j = 1 To 2 * m - 1
       Print s;
   Next j
   Print
  '**********FOUND**********
   n = n + 1
  '**********FOUND**********
   m = m - 1
Next i
End Sub
