var fs = require('fs');
var http = require('http');
var readline = require('readline');
var dicString = "";
var dicArr = [];
var testCorpus = "";
var fileDicPath = "Data/dic.txt";
var fileTestPath = "Data/TestCorpus.txt";
var encoding = "utf-8";
var result = "";


/**
 *
 *  getDicArr
 *  获取字典数组
 *  @param    字典数组字符串 -- dicString
 *  @return   字典数组 -- dicArr
 *
 */

var getDicArr = function(dicString)
{
  return dicString.split('\n');
}


/**
 *
 *  getTestArr
 *  将语料文件转化成数组
 *  @param    语料字符串 -- testString
 *  @return   语料数组 -- testArr
 *
 */

 var getTestArr = function(testString)
 {
 	return testString.split('');
 }


/**
 *
 *  getMaxLength
 *  获取字典词语的最大长度
 *  @param    字典数组 -- dicArr
 *  @return   字典词语的最大长度 -- maxLength
 *
 */

var getMaxLength = function(dicArr)
{
	var maxLength = 0;
	for(var i=0; i<dicArr.length; i++)
	{
		if(dicArr[i].length > maxLength)
		{
			maxLength = dicArr[i].length;
		}
	}
	return maxLength;
}


/**
 *
 *  getLengthDicArr
 *  获取不同长度词语的数组
 *  @param    字典数组 -- dicArr
 *  @param    词语长度 -- length
 *  @return   不同长度词语的数组 -- lengthDicArr
 *
 */

var getLengthDicArr = function(dicArr,length)
{
	var lengthDicArr = [];
	for(var i=0; i<dicArr.length; i++)
	{
		if(dicArr[i].length === length)
		{
			lengthDicArr.push(dicArr[i]);
		}
	}
	return lengthDicArr;

}

/**
 *
 *  forward
 *  正向最大匹配
 *  @param    语料数组 -- testArr
 *  @param    不同长度词语的数组 -- arrLen
 *  @return   正向最大匹配结果 -- retString
 *
 */

 var forward = function(testArr,arrLen)
 {
 	var retString  = '';
	var num = 7;
	for(var i = num; i>0; i--){
		var newTestStr = testArr.slice(0,i).join('');
		for(var j =0 ;j < arrLen[i-1].length ; j++){
			if(newTestStr == arrLen[i-1][j]){
				retString += newTestStr;
				for(var k = 0;k < i; k++){
					testArr.shift();
				}
				return retString;
			}
		}
	}
	testArr.shift();
	return "";
 }

/**
 *
 *  bakcward
 *  反向最大匹配
 *  @param    语料数组 -- testArr
 *  @param    不同长度词语的数组 -- arrLen
 *  @return   反向最大匹配结果 -- retString
 *
 */

var backward = function(testArr,arrLen)
{
 	var retString  = '';
 	var num = testArr.length>7?7:testArr.length;

 	for(var i = num; i>0; i--)
 	{
		
		var newTestStr = testArr.slice(testArr.length-i).join('');

		for(var j = 0 ;j < arrLen[i-1].length ; j++)
		{
			if(newTestStr == arrLen[i-1][j])
			{
				retString += newTestStr;
				for(var k = 0;k < i; k++)
				{
					testArr.pop();
				}
				return retString;
				
			}
		}
	}
	if(i==0)
	{
		testArr.pop();
		return "";

	}


}


/**
 *
 *  forwardOutput
 *  正向最大匹配输出
 *  @param    原始语料字符串 -- testCorpus
 *  @param    不同长度词语的数组 -- arrLen
 *  @return   正向最大匹配输出结果的字符串
 *
 */


 var forwardOutput = function(testCorpus,arrLen)
 {
 	var result = "";
 	var testArr = getTestArr(testCorpus);
	while(testArr.length > 0)
	{
		result = result + forward(testArr,arrLen) + '  ';
	}
	return result;
 }


 /**
 *
 *  backwardOutput
 *  反向最大匹配
 *  @param    原始语料字符串 -- testCorpus
 *  @param    不同长度词语的数组 -- arrLen
 *  @return   反向最大匹配输出结果的字符串
 *
 */


 var backwardOutput = function(testCorpus,arrLen)
 {
 	var result = "";
 	var testArr = getTestArr(testCorpus);
 	while(testArr.length > 0)
 	{
		result = backward(testArr,arrLen) + '  ' + result;
	}
	return result;
 }








// http.createServer(function(req,res){
// 	res.writeHead(200,{'Content-type':'text/plain'});
// 	var dicArr = getDicArr(dicString);
// 	res.end(dicString);
// 	//res.end(testCorpus);
// }).listen(3000);
// console.log("Web Server is listening port 3000");

/**
 *
 *  读取原始语料文件
 *  @param    filepath: "Data/TestCorpus.txt"
 *  @param    encoding: "UTF-8"
 *  @return   testCorpus: 原始语料字符串
 *
 */

fs.readFile(fileTestPath,encoding,function(err,data){
	testCorpus = data;
});


/**
 *
 *  读取字典文件
 *  @param    filepath: "Data/dic.txt"
 *  @param    encoding: "UTF-8"
 *  @return   dicString: 字典文件字符串
 *
 */


fs.readFile(fileDicPath,encoding,function(err,data){
	dicString = data;
	var dicArr = getDicArr(dicString);
	var arrLen1 = getLengthDicArr(dicArr,1);
	var arrLen2 = getLengthDicArr(dicArr,2);
	var arrLen3 = getLengthDicArr(dicArr,3);
	var arrLen4 = getLengthDicArr(dicArr,4);
	var arrLen5 = getLengthDicArr(dicArr,5);
	var arrLen6 = getLengthDicArr(dicArr,6);
	var arrLen7 = getLengthDicArr(dicArr,7);
	arrLen1.push('\n');
	var arrLen = [arrLen1,arrLen2,arrLen3,arrLen4,arrLen5,arrLen6,arrLen7];
	var maxLength = getMaxLength(dicArr);
	var testArr = getTestArr(testCorpus);
	
	var forwardResult = forwardOutput(testCorpus,arrLen);
	var backwardResult = backwardOutput(testCorpus,arrLen);
	//console.log(forwardResult);
	//console.log(backwardResult);

	

	var rl = readline.createInterface({
	    input:  process.stdin,
	    output: process.stdout
	});
	rl.setPrompt("NLP Demo > ");
	rl.prompt();
	rl.on('line',function(input){
	    var shell = input.trim();
	    switch(shell){
	        case '-h':
	            console.log("\n********************\n"+"\n-h   ----  helpInfo\n-t   ----  teamInfo\n-i   ----  demoInfo\n-f   ----  show fmm result in Node REPL\n-fw  ----  write fmm result to fmmResult.txt\n-fb  ----  show fmm result in browser!\n-b   ----  show bmm result in Node REPL\n-bw  ----  write bmm result to bmmResult.txt\n-bb  ----  show bmm result in browser!\n-c   ----  close\n"+"\n********************\n");
	            break;
	        case '-i':
	            console.log("\n This is a NLP FMM & BMM demo! \n");
	            break;
	        case '-t':
	            console.log("\n dingyongzhi && liuwei \n");
	            break;
	        case '-f':
	            console.log(forwardResult);
	            break;
	        case '-fw':
	            fs.writeFile('Data/fmmResult.txt', forwardResult, function (err) {
				  if (err) throw err;
				  console.log('Fmm result have been saved in fmmResult.txt!');
				});
				//rl.close();
	            break;
	        case '-fb':
	        	http.createServer(function(req,res){
	        		res.writeHead(200,{"Content-type":"text/plain"});
	        		res.end(forwardResult);
	        	}).listen(3000);
	        	console.log("\nWeb Server is listening port 3000!\n" + "\nYou can enter 'localhost:3000' in the browser address bar and to see fmm result!\n")
	            break;
	        case '-b':
	            console.log(backwardResult);
	            break;
	        case '-bw':
	            fs.writeFile('Data/bmmResult.txt', backwardResult, function (err) {
				  if (err) throw err;
				  console.log('Bmm result have been saved in bmmResult.txt!');
				});
				//rl.close();
	            break;
	        case '-bb':
	        	http.createServer(function(req,res){
	        		res.writeHead(200,{"Content-type":"text/plain"});
	        		res.end(backwardResult);
	        	}).listen(3000);
	        	console.log("\nWeb Server is listening port 3000!\n" + "\nYou can enter 'localhost:3000' in the browser address bar and to see bmm result!\n")
	            break;
	        case '-c':
	            console.log("\n You had closed NLP Demo! \n");
	            rl.close();
	            process.exit(0);
	            break;
	        default:
	            console.log("\n***********************************************************************\n"+
	            			"*This is a NLP FMM & BMM demo,you can input '-h' see more information!*"+
	            			"\n***********************************************************************\n"
	            );
	    }
	    rl.prompt();
	});
	

	
	
});



















