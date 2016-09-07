var fs = require('fs');
var http = require('http');
var dic = "";
var dicArr = [];
var testCorpus = "";
var fileDicPath = "Data/dic.txt";
var fileTestPath = "Data/TestCorpus.txt";
var encoding = "utf-8";
var result = "";

fs.readFile(fileTestPath,encoding,function(err,data){
	testCorpus = data;
	
});

fs.readFile(fileDicPath,encoding,function(err,data){
	dic = data;
	dicArr = data.split('\n');
	var arr = [];
	
	var str ;

	function maxlen(arr){
		var len = arr.length;
		var max = 0;

		for(var i = 0; i<len ; i++ ){
		if(arr[i].length > max){
			max = arr[i].length;	
		}
		
	}
	return max;
}
	
	function lenArr(arr, len){
		var len1 = arr.length;
		var retarr = [];
		for(var i = 0;i < len1;i++ ){
			if(arr[i].length == len){
				retarr.push(arr[i]);
			}
		}
		return retarr;
	}
	
	var max = maxlen(dicArr);

	var arrLen1 = lenArr(dicArr,1);
	var arrLen2 = lenArr(dicArr,2);
	var arrLen3 = lenArr(dicArr,3);
	var arrLen4 = lenArr(dicArr,4);
	var arrLen5 = lenArr(dicArr,5);
	var arrLen6 = lenArr(dicArr,6);
	var arrLen7 = lenArr(dicArr,7);
	arrLen1.push('\n');

	var arrLen = [arrLen1,arrLen2,arrLen3,arrLen4,arrLen5,arrLen6,arrLen7];

	//var newarr = [];
	var newarr = testCorpus.split('');


	/*
	
	function find(arr){
		var str  = '';
		var num = 7;
		for(var i = num; i>0; i--){
			var narr = arr.slice(0,i).join('');
			for(var j =0 ;j < arrLen[i-1].length ; j++){
				if(narr == arrLen[i-1][j]){
					str += narr;
					for(var k = 0;k < i; k++){
						arr.shift();
					}
					return str;
				}
			}
		}
		arr.shift();
		return "";

	}
	

	console.time('time');
	while(newarr.length > 0){
		result = result + find(newarr) + '  ';
	}
	console.log(result );
	console.timeEnd('time');


	while(newarr.length > 0){
		result = result + find(newarr) + '  ';
	}
	console.log(result );

	*/



	function findBack(arr){
		var str  = '';
		var num = 7;
		for(var i = num; i>0; i--){
			//（附图片1张）
			var narr = arr.slice(arr.length-num,arr.length).join('');
			//console.log(narr);
			for(var j = 0 ;j < arrLen[i-1].length ; j++){
				if(narr == arrLen[i-1][j]){
					str += narr;
					for(var k = 0;k < i; k++){
						arr.pop();
					}
					return str;
					
				}
			}
		}
		arr.pop();
		return "";

	}


	while(newarr.length > 0){
		result = result + findBack(newarr) + '  ';
	}
	console.log(result);
	
	

	

});






// http.createServer(function(req,res){
// 	res.writeHead(200,{'Content-type':'text/plain'});
// 	//res.end(dic);
// 	res.end(result);
// 	//res.end(testCorpus);
// }).listen(3000);
// console.log("Web Server is listening port 3000");








