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

'题目：据统计，手印全长与人体身高存在一定的比例关系：
'      身高（厘米）=手印全长*9.75，编写通过人手印长计
'      算身高的函数?

'-------------------------------------------------------

Private Function length(flong As Single)
'**********SPACE**********
length = flong * 9.75
End Function

Private Sub Form_Click()
Dim le   As Single
le = Val(InputBox("请输入人手印全长"))
'**********SPACE**********
h = length(le)
Print "此人的手印全长是：" & le & " 厘米  " & "可能的身高是：" & h & "厘米"
End Sub

