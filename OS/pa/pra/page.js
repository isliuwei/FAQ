
var OPT = function(testarr, len) {

	var arr = [];
	var count = 0;
	for (var i = 0; i < testarr.length; i++) {
		flag = 1;
		if (arr.length >= len) {
			if (arr.indexOf(testarr[i]) >= 0) {
				console.log(arr);
			} else {
				var pos = [];
				var temp;
				var tem;
				var j;
				arr.forEach(function(item, index, array) {
					if (testarr.slice(i).indexOf(item) === -1) {
						tem = item;
					} else {
						pos.push(testarr.slice(i).indexOf(item));
					}
				});
				if (tem) {
					temp = tem;
				} else {
					temp = testarr.slice(i)[Math.max.apply(null, pos)];
				}
				j = arr.indexOf(temp);
				if (j >= 0) {

					arr.splice(j, 1, testarr[i]);
					count++;
					console.log(arr);
				} else {
					count++;
					console.log(arr);
				} 
			}

		} else {
			for (var j = 0; j < arr.length; j++) {
				if (arr[j] === testarr[i]) {
					flag = !flag;
					break;
				}

			}
			if (flag) {
				arr.push(testarr[i]);
				console.log(arr);
			}

		}
	}

	console.log("缺页数: " + count);
	console.log("缺页率: " + ((count/testarr.length)*100).toFixed(0)+"%");
}



var LRU = function(testarr, len){

	function isLruExist(elem,arr){
		for(var j=0; j<arr.length; j++){
			if(elem == arr[j]){
				arr.splice(j,1);
				arr.push(elem);
				console.log(arr);
				flag = !flag;
				break;
			}
		}
		return flag;
	}

	var arr = [];
	var count = 0;

	for(var i=0; i<testarr.length; i++){
		flag = 1;
		if(arr.length >= len){
			if(isLruExist(testarr[i],arr)){
				arr.shift();
				arr.push(testarr[i]);
				console.log(arr);
				count++;
			}
		}else{
			if(isLruExist(testarr[i],arr)){
				arr.push(testarr[i]);
				console.log(arr);
				count++;
			}
		}

	}

	console.log("缺页数: " + count);
	console.log("缺页率: " + ((count/testarr.length)*100).toFixed(0)+"%");
}












var FIFO = function(testarr,len){

	var arr = [];
	var count = 0;

	function isExist(elem,arr){
		for(var j=0; j<arr.length; j++){
			if(elem == arr[j]){
				console.info();
				flag = !flag;
				break;
			}
		}
		return flag;
	}


	for(var i=0; i<testarr.length; i++){
		flag = 1;
		if(arr.length >= len){
			if(isExist(testarr[i],arr)){
				arr.shift();
				arr.push(testarr[i]);
				console.log(arr);
				count++;
			}
		}else{
			if(isExist(testarr[i],arr)){
				arr.push(testarr[i]);
				console.log(arr);
				count++;
			}
		}
	}

	console.log("缺页数: " + count);
	console.log("缺页率: " + ((count/testarr.length)*100).toFixed(0)+"%");
}





var readline = require('readline');
var fs = require('fs');

var rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout

});






rl.setPrompt("OS Demo > ");
rl.prompt();
	rl.on('line',function(input){
	    var shell = input.trim();
	    switch(shell){
	        case '-h':
	            console.log("\n****************************************\n"+"\n-h      ----      helpInfo\n-a      ----      authorInfo\n-i      ----      demoInfo\n-O      ----      OPT\n-F      ----      FIFO\n-L      ----      LRU\n exit   ----      exit\n"+"\n****************************************\n");
	            break;
	        case '-i':
	            console.log("\n This is a OS Page Replacement Algorithm Demo! \n");
	            break;
	        case '-a':
	            console.log("\n liuwei NO.20123349 \n");
	            break;
	        case '-F':
	        	rl.question('Please enter the test data file path: ',function(answer){
	        		var filePath = answer;
	        		var encoding = "utf8";
	        		fs.readFile(filePath,encoding,function(err,data){
	        			
	        			var testarr = file2arr(data," ");
	        			console.log("test data: ");
	        			console.log(testarr);
	        			
	        			rl.question('Please enter physical block length: ',function(answer){
	        				var len = parseInt(answer);
	        				FIFO(testarr,len);
	        			});
	        			
	        		});
	        		
	        	});
	            break;

	        case '-O':
	        	rl.question('Please enter the test data file path: ',function(answer){
	        		var filePath = answer;
	        		var encoding = "utf8";
	        		fs.readFile(filePath,encoding,function(err,data){
	        			
	        			var testarr = file2arr(data," ");
	        			console.log("test data: ");
	        			console.log(testarr);
	        			
	        			rl.question('Please enter physical block length: ',function(answer){
	        				var len = parseInt(answer);
	        				OPT(testarr,len);
	        			});
	        			
	        		});
	        		
	        	});
	            break;

	        case '-L':
	        	rl.question('Please enter the test data file path: ',function(answer){
	        		var filePath = answer;
	        		var encoding = "utf8";
	        		fs.readFile(filePath,encoding,function(err,data){
	        			
	        			var testarr = file2arr(data," ");
	        			console.log("test data: ");
	        			console.log(testarr);
	        			
	        			rl.question('Please enter physical block length: ',function(answer){
	        				var len = parseInt(answer);
	        				LRU(testarr,len);
	        			});
	        			
	        		});
	        		
	        	});
	            break;
	        
	        case 'exit':
	            console.log("\n You had closed OS Page Replacement Algorithm Demo! \n");
	            rl.close();
	            process.exit(0);
	            break;
	        default:
	            console.log("\n***************************************************************************************\n"+
	            			"*This is a OS Page Replacement Algorithm Demo,you can input '-h' see more information!*"+
	            			"\n***************************************************************************************\n"
	            );
	    }
rl.prompt();
});







var file2arr = function(fileData,separator)
{	var testarr = [];
	var arr = [];
	arr =  fileData.split(separator);
	arr.map(function(item,index,array){
		testarr.push(parseInt(item));
	});
	return testarr;
}





























