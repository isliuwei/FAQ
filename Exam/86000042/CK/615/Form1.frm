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
   StartUpPosition =   3  '����ȱʡ
   Begin VB.CommandButton Command1 
      Caption         =   "����������"
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
'��������ա�
'-------------------------------------------------------

'��ͼ��ʾ����10���������������복�͡�������ɫ�����ţ��ѳ�
'         ��β��Ϊ5�ĳ���ѡ����������������Ϊ-1ʱ��ֹͣ��
'         ��?�����Ƴ���?

'-------------------------------------------------------
Private Sub Command1_Click()
     Print "���ƺ���ĩλΪ5�ĳ��ǣ�"
    Print "����", "��ɫ", "����"
    Do
        a = InputBox("�����복��")
    '**********SPACE**********
        If Val(a) = -1 Then Exit Do
        b = InputBox("�����복����ɫ")
        c = InputBox("�����복��")
    '**********SPACE**********
         If Right(c, 1) = 5 Then
            Print a, b, c
        End If
    Loop
End Sub

