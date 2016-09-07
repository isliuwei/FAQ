var fs = require('fs');
var http = require('http');
var dic = "";
var dicArr = [];
var testCorpus = "";
var testArr = [];
var fileDicPath = "Data/dic.txt";
var fileTestPath = "Data/TestCorpus.txt";
var encoding = "utf-8";


fs.readFile(fileDicPath,encoding,function(err,data){
	dic = data;
	dicArr = data.split('\n');
	
	

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


	var getLengthDicArr = function(length,dicArr)
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


	var maxLength = getMaxLength(dicArr);



	


	// var l7 = getLengthDicArr(7,dicArr);
	// var l6 = getLengthDicArr(6,dicArr);
	// var l5 = getLengthDicArr(5,dicArr);
	// var l4 = getLengthDicArr(4,dicArr);
	// var l3 = getLengthDicArr(3,dicArr);
	// var l2 = getLengthDicArr(2,dicArr);
	// var l1 = getLengthDicArr(1,dicArr);
	var searchPos = function(string,length)
	{
		var lenDicArr = getLengthDicArr(length,dicArr);
		
		if(lenDicArr.indexOf(string) != -1)
		{
			return true;
		}else{
			return false;
		}
		
	}

	var searchDic = function(word,dicArr)
	{
		
		if(dicArr.indexOf(word)!= -1)
		{
			return true;
		}else{
			return false;
		}
		

	}




	
	String.prototype.trim=function() { 
		return this.replace(/(^\s|\\n*)|(\s|\\n*$)/g, ""); 
	}

	var testString = testCorpus.trim();
	var maxLength = 7;


	// for(var i=maxLength; i>0; i--)
	// {
		var retString = "";
		
		var newString = testString.substr(0,maxLength);
		
		for()
		if(searchPos(newString,maxLength))
		{
			retString+=newString;
			//console.log(newString);
			//newString = testString.substr(0,maxLength-1);

		}else{
			newString = newString.substr(0,maxLength-1);
		}
		
		
	// }
	

	

	

});



fs.readFile(fileTestPath,encoding,function(err,data){
	testCorpus = data;
	//var testArr = [];
	//testArr = data.split("");
	//console.log(testArr);


});


// var searchDic = function(word,dicArr)
// {
// 	for(var i=0; i<dicArr.length; i++)
// 	{
// 		if(dicArr[i] === word)
// 		{
// 			return i+1;
// 		}
// 	}

// }










/*
http.createServer(function(req,res){
	res.writeHead(200,{'Content-type':'text/plain'});
	//res.end(dic);
	res.end(dicArr[29795]+dicArr[46262]);
	//res.end(testCorpus);
}).listen(3000);
console.log("Web Server is listening port 3000");

*/






