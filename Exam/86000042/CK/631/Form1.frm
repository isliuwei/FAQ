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
      Caption         =   "Command1"
      Height          =   735
      Left            =   480
      TabIndex        =   2
      Top             =   1800
      Width           =   3375
   End
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   360
      TabIndex        =   0
      Top             =   120
      Width           =   3495
   End
   Begin VB.Label Label1 
      Height          =   495
      Left            =   360
      TabIndex        =   1
      Top             =   720
      Width           =   3495
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'-------------------------------------------------------
'��������ա�
'-------------------------------------------------------

'��Ŀ���ܱ�4�����Ҳ��ܱ�100�����������ܱ�400�����������
'      ���꣬�Բ��������ж�����ĳ���.

'-------------------------------------------------------
Private Sub Command1_Click()
Dim y As Integer
Dim leapyear As Boolean                 ' ������
y = Val(Text1.Text)                     ' yΪ���
 Label1.Caption = "��������"
'**********SPACE**********
  If (y Mod 4 = 0 And y Mod 100 <> 0) Or y Mod 400 = 0 Then
   leapyear = True
'**********SPACE**********
  Label1.Caption = "������"
   End If
End Sub
