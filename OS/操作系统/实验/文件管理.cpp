#include<iostream>
#include<time.h>
using namespace std;

struct FCB
{
		char	name[100];
		int		year,month,day,hour,minute,second;
		int		length;
		int		startaddr;
		int		node;
	
}fcb[1000];

struct Directory
{
		char	name[100][100];
		int		year,month,day,hour,minute,second;
		int		judge[100];			/*0为文件夹,1为文件*/
		int		link[100];		
		int		node;
		int		num;
}Dir[1000];

int		path = 1,Time = 1,used_fcb = 0,used_dir = 1;

int		step = 0;	
char	steps[100][100];		/*step保存当前工作路径深度,steps保存当前工作路径*/

int		FAT[256];	/*	FAT表	*/

int		Memory = 0;

char	bitmap[32];	/*	位示图	*/

time_t T; /*用来存系统时间*/
struct tm *TimeP; /*用来存localtime传回的地址*/	

void init(int n,int root)		/*对新结点初始化*/
{
		strcpy(Dir[n].name[0],".");
		strcpy(Dir[n].name[1],"..");
		Dir[n].judge[0]=Dir[n].judge[1] = 0;
		Dir[n].link[0]	= Time;
		Dir[n].link[1]	= root;
		Dir[n].node		= Time ++;
		Dir[n].num		= 2;
	

		T = time(NULL);
		TimeP = localtime( &T ); 
		Dir[n].year   = (TimeP->tm_year) +1900;
		Dir[n].month  = (TimeP->tm_mon) + 1;
		Dir[n].day    = (TimeP->tm_mday);
		Dir[n].hour   = (TimeP->tm_hour);
		Dir[n].minute = (TimeP->tm_min);
		Dir[n].second = (TimeP->tm_sec);
}
bool get_bit_map(int n);
void init_bit_map()	/*初始化位示图*/
{
		int				i;
		for(i = 0 ; i < 32 ; i ++)
				bitmap[i] = rand()%256;
		for(i = 0 ; i < 256 ; i ++)
				FAT[i] = -1;
		for(i = 0 ; i < 256 ; i++)
				if(get_bit_map(i) == 0)
						Memory ++;

		
}

void show_bit_map()	/*显示位示图*/
{
		int				i,j;
		cout << "位示图" <<endl;
		for(i = 0 ; i < 16 ; i ++)
		{
				for(j = 0 ; j < 16 ; j ++)
						printf("%d ",bool(bitmap[(i*16+j)/8] & (1<<(7-(i*16+j)%8))));
				cout<<endl;
		}
		
}


bool get_bit_map(int n)
{
		return bool(bitmap[n/8] & (1<<(7-n%8)));
}

void set_bit_map(int n,int k)
{
		if(k)
				bitmap[n/8]=bitmap[n/8] | (1<<(7-n%8));
		else
				bitmap[n/8]=bitmap[n/8] & ~(1<<(7-n%8));
}

void md()		/*创建文件夹*/
{
		int				i;
		char			 op[100];
		cin>>op;
		for(i = 2 ;i < Dir[path-1].num ; i ++)
				if(!Dir[path-1].judge[i] && !strcmp(Dir[path-1].name[i],op))
				{
						cout<<"文件夹已经存在"<<endl;
						return ;
				}
				
		init(used_dir++,path);
				
		Dir[path-1].judge[Dir[path-1].num] = 0;
		Dir[path-1].link[Dir[path-1].num]  = used_dir;
		strcpy(Dir[path-1].name[Dir[path-1].num],op);
		Dir[path-1].num++;
				
}

void rd()		/*	删除文件夹	*/
{
		int				i,j;
		char op[100];
		cin>>op;
		for(i = 2 ; i < Dir[path-1].num ; i ++)
				if(!Dir[path-1].judge[i] && !strcmp(Dir[path-1].name[i],op))
				{
						if(Dir[Dir[path-1].link[i]-1].num  >2)
								cout<<"该文件夹不为空, 不能删除"<<endl;
						else
						{
								for(j = i ; j < Dir[path-1].num-1 ; j ++)
								{
										Dir[path-1].link[j]  = Dir[path-1].link[j+1];
										Dir[path-1].judge[j] = Dir[path-1].judge[j+1];
										strcpy(Dir[path-1].name[j],Dir[path-1].name[j+1]);
								}
								Dir[path-1].num--;
								cout<<"删除成功"<<endl;
						}
						return ;
				}
		cout<<"该文件夹不存在"<<endl;
}

void fat()
{
		int				i,j,k;
		for(i = 2 ; i < Dir[path-1].num ; i ++)
		{
				if(Dir[path-1].judge[i])
				{
						cout << Dir[path-1].name[i] << ":" ;
						k = fcb[Dir[path-1].link[i]].startaddr;
						for(j=0;j<fcb[Dir[path-1].link[i]].length;j++)
						{
								cout << k << " ";
								k = FAT[k];
						}
						cout << endl;
				}
		}
}

void output_path()	/*输出工作路径*/
{
		cout<<endl<<"    C:\\";
		for(int i = 0 ; i <= step ; i ++)
		{
				if(i == step)
						break;
				else if(i == 0)
						cout<<steps[i];
				else
						cout<<"\\"<<steps[i];
		}
	
}


void dir()
{
		int				i;
		int				dir=0,file=0;
		int				sum=0;
		show_bit_map();
		output_path();
		cout << "的目录" << endl << endl;

		for(i = 0 ; i < Dir[path-1].num ; i ++)
			if(!Dir[path-1].judge[i])
			{
					cout<<Dir[Dir[path-1].link[i]-1].year<<"-"<<Dir[Dir[path-1].link[i]-1].month<<"-"<<Dir[Dir[path-1].link[i]-1].day<<"\t"<<Dir[Dir[path-1].link[i]-1].hour<<":"<<Dir[Dir[path-1].link[i]-1].minute<<":"<<Dir[Dir[path-1].link[i]-1].second<<"\t";
					cout<<"<DIR>\t";
					cout<<Dir[path-1].name[i]/*<<"\t"<<Dir[Dir[path-1].link[i]-1].node*/<<endl;
					dir ++;
			}
			else
			{
					cout<<fcb[Dir[path-1].link[i]].year<<"-"<<fcb[Dir[path-1].link[i]].month<<"-"<<fcb[Dir[path-1].link[i]].day<<"\t"<<fcb[Dir[path-1].link[i]].hour<<":"<<fcb[Dir[path-1].link[i]].minute<<":"<<fcb[Dir[path-1].link[i]].second<<"\t\t";
					cout<<fcb[Dir[path-1].link[i]].length<<"\t";
					cout<<Dir[path-1].name[i]/*<<"\t"<<fcb[Dir[path-1].link[i]].node*/<<endl;
					sum += fcb[Dir[path-1].link[i]].length;
					file ++;
			}
		cout << "\t\t" << file << "个文件\t" << sum << "\t字节" << endl;
		cout << "\t\t"<< dir << "个目录\t" << Memory << "\t可用字节" << endl;
		fat();
}


void _dir(char *choose)
{
	 int			i,j,k;
	 for(i = 0 ; i < Dir[path-1].num ; i ++)
	 {
				for(j=k=0;j<=strlen(Dir[path-1].name[i]);j++)
				{
						if(choose[k]== '*')
								k++;
						if(choose[k] != '*' && choose[k] != '?' && choose[k] == Dir[path-1].name[i][j])
							k++;
						else	if(choose[k] == '?')
							k++;

				}
				if(k>=strlen(choose))
				{
						if(!Dir[path-1].judge[i])
						{
								cout<<Dir[Dir[path-1].link[i]-1].year<<"-"<<Dir[Dir[path-1].link[i]-1].month<<"-"<<Dir[Dir[path-1].link[i]-1].day<<"\t"<<Dir[Dir[path-1].link[i]-1].hour<<":"<<Dir[Dir[path-1].link[i]-1].minute<<":"<<Dir[Dir[path-1].link[i]-1].second<<"\t";
								cout<<"\t<DIR>\t";
								cout<<Dir[path-1].name[i]<<endl;
						}
						else
						{
								cout<<fcb[Dir[path-1].link[i]].year<<"-"<<fcb[Dir[path-1].link[i]].month<<"-"<<fcb[Dir[path-1].link[i]].day<<"\t"<<fcb[Dir[path-1].link[i]].hour<<":"<<fcb[Dir[path-1].link[i]].minute<<":"<<fcb[Dir[path-1].link[i]].second<<"\t";
								cout<<fcb[Dir[path-1].link[i]].length<<"\t";
								cout<<Dir[path-1].name[i]<<endl;
				}

				}
	 }
}

bool output[100];

void tree(int p,int deep)
{
		int				i,j;
		for(i = 2 ; i < Dir[p-1].num ; i ++)
		{
				
				for(j = 0 ; j < deep ; j ++)
						if(output[j] == true)
								cout<<"│\t";
						else
								cout<<"\t";
				if(i < Dir[p-1].num-1)
						cout<<"├───"<<Dir[p-1].name[i]<<endl;
				else
						cout<<"└───"<<Dir[p-1].name[i]<<endl;

				output[deep] = false;
				if(i < Dir[p-1].num-1)
					output[deep] = true;

				if(!Dir[p-1].judge[i])
						tree(Dir[p-1].link[i],deep+1);
		}
}

void cd()
{
		char op[100];
		int i;
		cin>>op;
		if(!strcmp(op,"\\"))
		{
			path=1;
			step=0;	
			return ;
		}
		for(i = 0 ; i < Dir[path-1].num ; i ++)
				if(!Dir[path-1].judge[i] && !strcmp(Dir[path-1].name[i],op))
				{
						path=Dir[path-1].link[i];
						
						if(i == 1 && step)
								step--;
						else if(i != 1 && i)
						{
								strcpy(steps[step++],op);
						}
						
						return ;
				}
		cout<<"不存在该文件夹"<<endl;
}

void mk()
{
		int i,j,k;
		cin>>fcb[used_fcb].name;
		cin>>fcb[used_fcb].length;
		
		Memory -= fcb[used_fcb].length;

		for(i = 2 ; i < Dir[path-1].num ; i ++)
				if(Dir[path-1].judge[i] && !strcmp(Dir[path-1].name[i],fcb[used_fcb].name))
				{
						cout<<"文件重名，创建失败"<<endl;
						return ;
				}
				
		for(i = j = 0 ; i < 256 && j < fcb[used_fcb].length ; i ++)
			if(!get_bit_map(i))
				j ++;
		if(i == 256)
		{
			cout<<"没有足够空间,不能创建文件"<<endl;
			return ;
		}
			
		for(i = j = 0 , k = -1 ; i < fcb[used_fcb].length ; i ++ , j ++)
		{
			while(get_bit_map(j))
				j ++;
			set_bit_map(j,1);
			if(k == -1)
				fcb[used_fcb].startaddr = j;
			else
				FAT[k] = j;
			k = j;
		}
		
		strcpy(Dir[path-1].name[Dir[path-1].num],fcb[used_fcb].name);
		fcb[used_fcb].node = Time++;
		Dir[path-1].link[Dir[path-1].num]  = used_fcb;
		Dir[path-1].judge[Dir[path-1].num] = 1;

		
		T = time(NULL);
		TimeP = localtime( &T ); 
		fcb[used_fcb].year = (TimeP->tm_year) + 1900;
		fcb[used_fcb].month  = (TimeP->tm_mon) + 1;
		fcb[used_fcb].day  = (TimeP->tm_mday) ;
		fcb[used_fcb].hour   = (TimeP->tm_hour);
		fcb[used_fcb].minute = (TimeP->tm_min);
		fcb[used_fcb].second = (TimeP->tm_sec);
	
		Dir[path-1].num++;
		used_fcb++;
		
}

void del()		/*删除文件*/
{
		int i,j,k;
		
		char na[100];
		cin>>na;
		for(i = 2 ; i < Dir[path-1].num ; i ++)
				if(Dir[path-1].judge[i] && !strcmp(Dir[path-1].name[i],na))
				{
						k = fcb[Dir[path-1].link[i]].startaddr;
						for(j=0;j<fcb[Dir[path-1].link[i]].length;j++)
						{
								set_bit_map(k,0);
								k = FAT[k];
								Memory ++;
						}
						
						for(j = i ; j < Dir[path-1].num-1 ; j ++)
						{
								Dir[path-1].link[j]  = Dir[path-1].link[j+1];
								Dir[path-1].judge[j] = Dir[path-1].judge[j+1];
								strcpy(Dir[path-1].name[j],Dir[path-1].name[j+1]);
						}
						Dir[path-1].num--;
						
						cout<<"删除成功"<<endl;
						return ;
				}
		cout<<"没找到文件"<<endl;
}

bool outputpath()	/*输出工作路径*/
{
		cout<<"C:\\>";
		for(int i = 0 ; i < step ; i ++)
		{
				cout<<steps[i]<<'>';
		}
		return true;
}

void choose()
{	
		char op[100],choose[100];
		
		while(outputpath()	&& cin>>op && strcmp(op,"exit"))
		{
				memset(choose,'\0',sizeof(choose));
				if(!strcmp(op,"cd"))
				{
						cd();
				}
				else if(!strcmp(op,"rd"))
				{
						rd();
				}
				else if(!strcmp(op,"md"))
				{
						md();
				}
				else if(!strcmp(op,"tree"))
				{
						tree(path,0);
						
				}
				else if(!strcmp(op,"mk"))
				{
						mk();
				}
				else if(!strcmp(op,"del"))
				{
						del();
				}
				else if(!strcmp(op,"dir"))
				{
						getchar();
						gets(choose);
						if(choose[0]!='\0')
								_dir(choose);
						else
								dir();
				}
				else if(!strcmp(op,"cls"))
				{
						system("cls");
				}else if(!strcmp(op,"show")){
					show_bit_map();
					cout<<endl;
					fat();
				}
				
		}
		
}




int main()
{
		init(0,1);
		cout << "Microsoft Windows XP [版本 5.1.2600]\n(C) 版权所有  .\n\n" << endl;
		init_bit_map();
		choose();
		return 0;
}
