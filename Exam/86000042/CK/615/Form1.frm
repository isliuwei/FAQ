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
   Begin VB.CommandButton Command1 
      Caption         =   "请输入数据"
      Height          =   615
      Left            =   1200
      TabIndex        =   0
      Top             =   1680
      Width           =   1935
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

'-------------------------------------------------------
'【程序填空】
'-------------------------------------------------------

'如图所示：有10辆车，键盘上输入车型、车的颜色、车号，把车
'         号尾数为5的车挑选出来。当车型输入为-1时，停止输
'         入?请完善程序?

'-------------------------------------------------------
Private Sub Command1_Click()
     Print "车牌号最末位为5的车是："
    Print "车型", "颜色", "车号"
    Do
        a = InputBox("请输入车型")
    '**********SPACE**********
        If Val(a) = -1 Then Exit Do
        b = InputBox("请输入车的颜色")
        c = InputBox("请输入车号")
    '**********SPACE**********
         If Right(c, 1) = 5 Then
            Print a, b, c
        End If
    Loop
End Sub


