var fs = require('fs');
var http = require('http');
var readline = require('readline');
var dicString = "";
var dicArr = [];
var testCorpus = "";
var goldText = "";
var fileDicPath = "Data/dic.txt";
var fileTestPath = "Data/TestCorpus.txt";
var fileGoldPath = "gold.txt";
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
 *  读取金标语料文件
 *  @param    filepath: "gold.txt"
 *  @param    encoding: "UTF-8"
 *  @return   goldText: 金标语料字符串
 *
 */

fs.readFile(fileGoldPath,encoding,function(err,data){
	goldText = data;
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


	// var reg = /\\n*/g;
	// goldText.replace(reg,"  ");
	// console.log(goldText);



	var forwardResultArr = function(forwardResult)
	{
		return forwardResult.split("  ");
	}

	var goldTextArr = function(goldText)
	{
		return goldText.split("  ");
	}

	

	//console.log(goldTextArr(goldText));
	//console.log(forwardResultArr(forwardResult));

	// var goldTextArr = goldTextArr(goldText);
	// var forwardResultArr = forwardResultArr(forwardResult);

	// var count = 0;

	// for(var i=0; i<forwardResultArr.length;i++)
	// {
		
	// 	if(forwardResultArr[i] === goldTextArr[i])
	// 	{
	// 		console.log(forwardResultArr[i]+"--"+goldTextArr[i]);
	// 		count++;

	// 		forwardResultArr.pop();

	// 		goldTextArr.pop();

	// 	}else{

	// 	}
	// }
	// console.log(count);

	

	

	
	
});



















