
/**
 * 定义一个队列类
 * @dataStore  	空数组
 * @enqueue  	入队
 * @dequeue  	出队
 * @front  		返回队首元素
 * @back		返回队尾元素
 * @show		打印队列
 * @isEmpty		判断队列是否为空
 */
function Queue()
{
	this.dataStore = [];
}

Queue.prototype.enqueue = function(element)
{
	this.dataStore.push(element);
}
Queue.prototype.dequeue = function()
{
	return this.dataStore.shift();
}

Queue.prototype.front = function()
{
	return this.dataStore[0];
}

Queue.prototype.back = function()
{
	return this.dataStore[this.dataStore.length-1];
}

Queue.prototype.show = function()
{
	var retStr = "";
	for(var i = 0; i < this.dataStore.length; i++)
	{
		retStr += this.dataStore[i] + "\n";
	}
	return retStr;
}
Queue.prototype.isEmpty = function()
{
	if(this.dataStore.length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/**
 * 定义一个 PCB 类
 * @pid		  		进程pid
 * @title	  		进程title
 * @get_pid  		返回pid
 * @get_title  		返回title
 */

function PCB(pid,title)
{
	this.pid = pid;
	this.title = title;
}

PCB.prototype.get_pid = function()
{
	return this.pid;
};

PCB.prototype.get_title = function()
{
	return this.title;
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

var create_process = function(title)
{
	var pid = create_pid();
	var title = title;
	var pcb = new PCB(pid,title);
	readyQue.enqueue(pcb);
}


/**
 * 阻塞进程	block_process
 */

var block_process = function()
{
	if(readyQue.isEmpty())
	{
		console.log("No ready process running");
	}
	else
	{
		blockQue.enqueue(readyQue.front());
		readyQue.dequeue();
	}

}

/**
 * 唤醒进程	wake_process
 */

var wake_process = function()
{
	if(blockQue.isEmpty())
	{
		console.log("No blocked process running");
	}
	else
	{
		readyQue.enqueue(blockQue.front());
		blockQue.dequeue();
	}

}

/**
 * 时间片到	time_end
 */

var time_end = function()
{
	if(readyQue.isEmpty())
	{
		console.log("No ready process running");
	}
	else
	{
		running = readyQue.front();
		readyQue.dequeue();
		readyQue.enqueue(running);
	}
}

/**
 * 结束进程	kill_process
 */

var kill_process = function()
{
	if(readyQue.isEmpty())
	{
		console.log("No ready process running");
	}
	else
	{
		readyQue.dequeue();
		running = readyQue.front();
	}
}

/**
 * 显示进程信息	show_process
 */

var show_process = function()
{

	var readyStr = "";
	var blockStr = "";
	if(readyQue.front())
	{
		console.log("running: " + readyQue.front().title);
	}

	for(var j=1; j<readyQue.dataStore.length; j++)
	{
		readyStr += readyQue.dataStore[j].title+" ";
	}
	console.log("ready: " + readyStr);

	for(var k=0; k<blockQue.dataStore.length; k++)
	{

		blockStr += blockQue.dataStore[k].title+" ";

	}
	console.log("blocked: " + blockStr);
}


var running = "";
var readyQue = new Queue();
var blockQue = new Queue();
var readline = require("readline");
var rl = readline.createInterface({
	    input:  process.stdin,
	    output: process.stdout
});

rl.setPrompt("OS Demo > ");
rl.prompt();
	rl.on('line',function(input){
	    var shell = input.trim();
	    switch(shell){
	        case '-h':
	            console.log("\n****************************************\n"+"\n-h      ----      helpInfo\n-a      ----      authorInfo\n-i      ----      demoInfo\n-c      ----      create a process\n-b      ----      blocked a process\n-w      ----      wake a process\n-t      ----      time end\n-k      ----      kill currenty process\n exit   ----      exit\n"+"\n****************************************\n");
	            break;
	        case '-i':
	            console.log("\n This is a OS Process Management Demo! \n");
	            break;
	        case '-a':
	            console.log("\n liuwei NO.20123349 \n");
	            break;
	        case '-c':
	        	rl.question('please enter process title:',function(answer){
	        		var title = answer;
	        		create_process(title);
	        		show_process();
	        	});
	            break;
	        case '-b':
	        	block_process();
	        	show_process();
	            break;
	        case '-w':
	        	wake_process();
	        	show_process();
	            break;
			case '-t':
				time_end();
				show_process();
				break;
	        case '-k':
	        	kill_process();
	        	show_process();
	            break;
	        case 'exit':
	            console.log("\n You had closed OS Process Management Demo! \n");
	            rl.close();
	            process.exit(0);
	            break;
	        default:
	            console.log("\n*******************************************************************************\n"+
	            			"*This is a OS Process Management Demo,you can input '-h' see more information!*"+
	            			"\n*******************************************************************************\n"
	            );
	    }
rl.prompt();
});





