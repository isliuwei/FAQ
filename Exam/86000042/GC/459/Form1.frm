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
   Begin VB.CommandButton Command1 
      Caption         =   "Run"
      Height          =   495
      Left            =   1800
      TabIndex        =   0
      Top             =   2040
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "Label1"
      Height          =   735
      Left            =   480
      TabIndex        =   1
      Top             =   360
      Width           =   3735
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'------------------------------------------------
'������Ĵ���
'------------------------------------------------

'��Ŀ���������n����λ��������n������Ի������룬��n>0����
'      ������е�ż��֮�ͣ����ڱ�ǩ��Label1����ʾ��

'------------------------------------------------
Option Explicit
Private Sub Command1_Click()
    Dim n As Integer
    Dim i As Integer, sum As Long
    Dim rnddat As Integer
    n = Val(InputBox("Please input a integer", "Input N value"))
    '**********FOUND**********
    sum = n
    If n > 0 Then
        For i = 1 To n
            '**********FOUND**********
            rnddat = (Int(90 * Rnd))
            Me.Print rnddat;
            '**********FOUND**********
            If rnddat / 2 = 0 Then
                sum = sum + rnddat
            End If
        Next i
        Label1.Caption = sum
    End If
End Sub