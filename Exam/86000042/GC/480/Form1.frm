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
   Begin VB.CommandButton Command1 
      Caption         =   "Run"
      Height          =   495
      Left            =   1800
      TabIndex        =   0
      Top             =   1320
      Width           =   1215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'------------------------------------------------
'【程序改错】
'------------------------------------------------

'题目:下面函数的功能是：求变量s(s=a+aa+aaa+aaaa+……)
'     的值。其中，a是一个0-9的数字，总共累加a项。
'     例如，当a=3时,s=3+33+333   (共累加3项)。

'------------------------------------------------
Option Explicit
Public Function Calc(a As Integer)
    Dim s As Long
    Dim t As Long
    Dim i As Integer
    s = a
    '**********FOUND**********
    t = 1
    For i = 2 To a
        '**********FOUND**********
        t = t + a
        s = s + t
    Next i
    Calc = s
    Print s
End Function

Private Sub Command1_Click()
    Dim i As Integer
    i = InputBox("请输入数字（0-9）:")
    '**********FOUND**********
    Calc call i
End Sub
