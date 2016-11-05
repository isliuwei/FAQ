

		var  processArr = [];
		var x = [];


		function change(){
			processArr.forEach(function (item,index) {
				item.flag = true;
			});
		}

		processArr = [
			{
				name: 'A',
				arrive: 0,
				server: 4

			},
			{
				name: 'B',
				arrive: 1,
				server: 3

			},
			{
				name: 'C',
				arrive: 2,
				server: 5

			},
			{
				name: 'D',
				arrive: 3,
				server: 2

			},
			{
				name: 'E',
				arrive: 4,
				server: 4

			}
		];

		function FCFS(arr){
			change();
			var flag = false;
			var timer = 0;
			var temp;
			var len = arr.length;
			while(len > 0){
				flag = false;
				for(var i = 0 ; i < arr.length; i++){
					if (arr[i].arrive <= timer && arr[i].flag == true){
						flag = true;
						temp = i;
						len--;

						break;
					}
				}
				if(flag){
					arr[temp].begin = timer;
					arr[temp].flag = false;
					timer += arr[temp].server
					arr[temp].end = timer;
					arr[temp].turn = arr[temp].end - arr[temp].arrive;
					arr[temp].weightTurn = arr[temp].turn / arr[temp].server;
					console.log("    "+arr[temp].name +"      |  "+"    "+arr[temp].arrive +"     |  "+"    "+arr[temp].server +"      |  "+"    "+arr[temp].end +"        |  "+"    "+arr[temp].turn +"      |  "+"    "+arr[temp].weightTurn);
				}else{
					timer ++;
				}

			}
		}

		function SJF(arr){
			change();
			var flag = false;
			var timer = 0;
			var temp;
			var len = arr.length;
			var joblen = 100;
			while(len > 0){
				joblen = 100;
				flag = false;
				for(var i = 0 ; i < arr.length; i++){
					if (arr[i].arrive <= timer && arr[i].flag == true){
						flag = true;
						if(arr[i].server<joblen){
							joblen = arr[i].server;
							temp = i;
						}
					}
				}
				if(flag){
					len--;
					arr[temp].begin = timer;
					arr[temp].flag = false;
					timer += arr[temp].server
					arr[temp].end = timer;
					arr[temp].turn = arr[temp].end - arr[temp].arrive;
					arr[temp].weightTurn = arr[temp].turn / arr[temp].server;
					console.log("    "+arr[temp].name +"      |  "+"    "+arr[temp].arrive +"     |  "+"    "+arr[temp].server +"      |  "+"    "+arr[temp].end +"        |  "+"    "+arr[temp].turn +"      |  "+"    "+arr[temp].weightTurn);


				}else{
					timer ++;
				}

			}
		}

		function RR(arr,num){
			change();
			var lenArr = [];
			var len = 0;
			var recoder = [];

			arr.forEach(function (item,index){
				lenArr.push(item.server);
				len += item.server;
			});
			console.log(arr[0].beign);


			var timer = 0;

			while(len>0){
				var flag1 = true;
				arr.forEach(function (item,index){
					if(item.flag == true){
						flag1 = false;
					}
				});

				flag = false;
				var temp;
				for(var i = 0 ; i < arr.length; i++){
					if (arr[i].arrive <= timer && arr[i].flag == true){
						flag = true;
						temp = i;
						break;
					}
				}

				if(flag||flag1){

					if(flag1){
						for(var i = 0 ; i<lenArr.length; i++){
								if(lenArr[i] > 0){
								var t =	lenArr[i]>num? num : lenArr[i];
								lenArr[i]-=t;
								// console.log(lenArr[i]);
								timer+=t;
								len-=t;
								for(var j = 0; j<t;j++){
									// console.log(arr[index].name);
									recoder.push(arr[i].name);
									}
							}
						}

					}

						arr[temp].flag = false;
					var t = lenArr[temp]>num?num:lenArr[temp];
						lenArr[temp]-=t;
						timer+=t;
						len-=t;
						for(var j = 0; j<t;j++){
							recoder.push(arr[temp].name);

						}
				}else{
					timer++;
					recoder.push(' ');
				}
			}

			arr.forEach(function (item,index){
					item.turn = recoder.lastIndexOf(item.name)+1-item.arrive;
					item.weightTurn = item.turn/item.server;
					console.log("    "+item.name +"      |  "+"    "+item.arrive +"     |  "+"    "+item.server +"      |  "+"    "+item.end +"        |  "+"    "+item.turn +"      |  "+"    "+item.weightTurn);


			});
			console.log(recoder);
			return recoder;

		}

		function RRR(){

			// var str = 'ABCDEABCDEABCEACEC';
			// var arr = str.split('');
			var str = 'ABCDEABCDEABCEACE';
			var arr = str.split('');
			x = arr;


			processArr.forEach(function(item,index,array){
				item.end = arr.lastIndexOf(item.name)+1;
				item.turn = arr.lastIndexOf(item.name)+1-item.arrive;
				item.weightTurn = item.turn/item.server;
				console.log("    "+item.name +"      |  "+"    "+item.arrive +"     |  "+"    "+item.server +"      |  "+"    "+item.end +"        |  "+"    "+item.turn +"      |  "+"    "+item.weightTurn);
			});

		}



var readline = require('readline');

var rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout

});



rl.setPrompt("OS Demo > ");
rl.prompt();
	rl.on('line',function(input){
	    var shell = input.trim();
	    switch(shell){
	        case 'HELP':
	            console.log("\n****************************************\n"+"\n-HELP      ----      帮助信息\n-FCFS      ----      先来先服务\n-SJF       ----      短作业优先\n-RR        ----      时间片轮转\n-EXIT      ----      退出\n"+"\n****************************************\n");
	            break;
	        case 'FCFS':
	            console.log("\n 进程名称  |  达到时间  |   服务时间  |  完成时间    |   周转时间  |  带权周转时间  |  \n");
	            FCFS(processArr);
	            break;
	        case 'SJF':
	            console.log("\n 进程名称  |  达到时间  |   服务时间  |  完成时间    |   周转时间  |  带权周转时间  |  \n");
	            SJF(processArr);
	            break;
	        case 'RR':
	            console.log("\n 进程名称  |  达到时间  |   服务时间  |  完成时间    |   周转时间  |  带权周转时间  |  \n");
	            RRR();
	            console.info();
	            console.log("    "+x.join(' '));
	            break;
	        case 'EXIT':
	            console.log("\n 程序已经退出！ \n");
	            rl.close();
	            process.exit(0);
	            break;
	        default:
	            console.log("\n****************************************************************\n"+
	            			"*    操作系统进程调度实验演示！输入'HELP'查看更多帮助信息！    *"+
	            			"\n****************************************************************\n"
	            );
	    }
rl.prompt();
});
