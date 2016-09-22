




/*
var bitMap = {

	init: function(){

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
		},

	

	show: function(){
			bit = this.init();
			var str = '';
			for(var i=0; i<8; i++)
			{
				for(var j=0; j<8; j++)
				{
					str += bit[i][j]+"       ";
				}
				str+="\n";
			}
			console.log(str);
		},

	find: function(){

	}

};
bitMap.show();
bitMap.show();
*/

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
	//return str;
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



 












