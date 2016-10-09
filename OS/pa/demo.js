
/**
 * 定义一个 PCB 类
 * @pid		  		进程pid
 * @title	  		进程title
 * @size	  		进程size
 * @get_pid  		返回pid
 * @get_title  		返回title
 * @get_size  		返回size
 */

	 function PCB(pid,title,size)
	 {
		 this.pid = pid;
		 this.title = title;
		 this.size = size;
	 }

	 PCB.prototype.get_pid = function()
	 {
		 return this.pid;
	 };

	 PCB.prototype.get_title = function()
	 {
		 return this.title;
	 };

	 PCB.prototype.get_size = function()
	 {
		 return this.size;
	 };

 /**
  * 生成一个随机pid
  */

	 var create_pid = function()
	 {
		 var myDate = new Date();
		 var myYear = myDate.getYear();
		 var myMonth = myDate.getMonth();
		 var myHour= myDate.getHours();
		 var myMinute = myDate.getMinutes();
		 var mySecond = myDate.getSeconds();
		 var myRandom = ~~(Math.random()*1000);
		 var pid = myYear+myMonth+myHour+myMinute+mySecond+myRandom;
		 return pid;
	 }

 /**
  * 创建进程	create_process
  */

 	var create_process = function(title,size)
	 {
		 var pid = create_pid();
		 var title = title;
		 var size = size;
		 var pcb = new PCB(pid,title,size);
	 }

	var show_pageTable = function(pcb, bitmap)
	{

		var newArr = Array.prototype.concat.apply([],bitmap);
		var str = '';
		var status;


		if(newArr.length < pcb.size)
		{
			console.log('越界');
		}
		else
		{
			str += (页号+"    "+状态+"       ");
			for(var i=0; i<pcb.size; i++)
			{
				if(newArr[i] == 0)
				{
					status = 0;
				}
				else
				{
					status = 1;
				}

				str += (i+"    "+status+"       ");
			}
			str+="\n";
		}
		console.log(str);

	}





var readline = require('readline');

var rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout

});



var bitMap = function()
{
	var bitArr = [];
	for(var i=0; i<8; i++)
	{
		var colArr = [];
		for(var j=0; j<8; j++)
		{
			colArr[j] = parseInt(Math.random()*2);
		}
		bitArr[i] = colArr;
	}
	return bitArr;
}

var bitmap = bitMap();



var showbitMap = function(bitMap)
{
	var str = '';
	for(var i=0; i<8; i++)
	{
		for(var j=0; j<8; j++)
		{
			str += bitMap[i][j]+"       ";
		}
		str+="\n";
	}

	console.log(str);
}

var block = function(bitmap)
{
	for(var i = 0;i < 8;i ++)
	{
		for(var j = 0;j < 8;j ++)
		{
			if(bitmap[i][j] == 0)
			{
				bitmap[i][j] =1 ;
			    blockNo = (i * 8) + (j +1);
				return blockNo;
			}
				 
		}
	}

}




var convert = function(blockLen,logical,bitmap)
{
	
	var blockNo = block(bitmap);
	var pageNo = parseInt(logical / (blockLen * 1024));
	var pageAdd = logical % (blockLen * 1024);
	var phisical = blockNo*blockLen*1024 + pageAdd;

	console.log("页号为: " + pageNo);
	console.log("页内地址为: " + pageAdd);
	console.log("块号: " + blockNo);
	console.log("物理地址为: " + phisical);
	
}



rl.setPrompt("OS Demo > ");
rl.prompt();
	rl.on('line',function(input){
	    var shell = input.trim();
	    switch(shell){
	        case '-h':
	            console.log("\n****************************************\n"+"\n-h      ----      helpInfo\n-a      ----      authorInfo\n-i      ----      demoInfo\n-r      ----      running demo\n exit   ----      exit\n"+"\n****************************************\n");
	            break;
	        case '-i':
	            console.log("\n This is a OS Paging Storage Management Demo! \n");
	            break;
	        case '-a':
	            console.log("\n liuwei NO.20123349 \n");
	            break;
	        case '-r':
	        	rl.question('请输入逻辑地址(十进制) : ',function(answer){
 	        		console.log("输入的逻辑地址为: ",answer);
				    console.log("初始位示图为: ");
					showbitMap(bitmap);
					convert(1,answer,bitmap);
					console.log("当前位示图为: ");
					showbitMap(bitmap); 
	        		
	        	});
	            break;

	        
	        case 'exit':
	            console.log("\n You had closed OS Paging Storage Management Demo! \n");
	            rl.close();
	            process.exit(0);
	            break;
	        default:
	            console.log("\n***************************************************************************************\n"+
	            			"*This is a OS Paging Storage Management Demo,you can input '-h' see more information!*"+
	            			"\n***************************************************************************************\n"
	            );
	    }
rl.prompt();
});





/*
rl.question("请输入逻辑地址(十进制): ",function(answer){
    console.log("输入的逻辑地址为: ",answer);


    var bitmap = bitMap();
    console.log("初始位示图为: ");
	showbitMap(bitmap);
	convert(1,answer,bitmap);
	console.log("当前位示图为: ");
	showbitMap(bitmap); 
	

    //rl.close();
});
*/



 












